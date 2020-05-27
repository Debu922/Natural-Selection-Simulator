#include "SimulationEngine.h"
#include "World.h"
#include "CLIEngine.h"
#include <iostream>

SimulationEngine SimulationEngine::sim;

void SimulationEngine::startUI()
{
    std::cout << "CLI has been initialized properly.\n";
    /* @todo (debbh#1#03/26/20): NEED TO MAKE A PROPER CLI */

}


void SimulationEngine::initWorld()
{
    World* world = World::getWorld();

    std::cout << "Initializing World\n";

    world->setSeed(4);
    world->setSize(50, 50);
    world->setOrganismCount(10);
    world->setFoodCount(10);
    world->setGlobalReach(2.0);
    stepCount = 0;
    /**
    world.printParams();
    world.setSeed(cli.getUserInputI("Please input seed(int)"));
    world.setSize(cli.getUserInputD("Please set world xSize(float)"),cli.getUserInputD("Please set world ySize(float)"));
    world.setOrganismCount(cli.getUserInputI("Please set initial organism count(int)"));
    world.setFoodCount(cli.getUserInputI("Please set initial food count(float)"));
    **/
    world->printParams();
}

void SimulationEngine::initSim()
{
    World* world = World::getWorld();
    world->randomizeOrganismPosition();
    world->randomizeFoodPosition();
}

void SimulationEngine::startSim(int steps)
{
    World* world = World::getWorld();
    for (int i = 0; i < steps;i++) {
        preTimeStep();
        timeStep();
        postTimeStep();
    }
    
}

void SimulationEngine::checkVision() {
    //This function will print out the values of the organisms within vision
    World* world = World::getWorld();
    std::cout << "PRINTING ORGANISMS WITHIN VISION" << std::endl;
    for (int j = 0; j < world->organisms.size(); j++) {
        std::cout << "Organism:" << j << " ";
        for (int i = 0; i < world->organisms[j].organismsWithinVision.size(); i++) {
            std::cout << world->organisms[j].organismsWithinVision[i] << " ";
        }
        std::cout << std::endl;
    };
    std::cout << "PRINTING FOOD WITHIN VISION" << std::endl;
        for (int j = 0; j < world->organisms.size(); j++) {
            std::cout << "Organism:" << j << " ";
            for (int i = 0; i < world->organisms[j].foodWithinVision.size(); i++) {
                std::cout << world->organisms[j].foodWithinVision[i] << " ";
                
            }
            std::cout << std::endl;
        }
}

void SimulationEngine::checkOFDistance() {
    World* world = World::getWorld();
    std::cout << "Printing OFDisntances in timestep :" << stepCount << std::endl;
    for (int i = 0; i < world->organisms.size(); i++) {
        if (world->organisms[i].foodWithinVision.size() != 0) {
            std::cout << "Organism id" << i << world->organisms[i].pos <<  "target " << world->organisms[i].state.targetFood<<"\t";
            for (int j = 0; j < world->organisms[i].foodWithinVision.size(); j++) {
                std::cout << world->organisms[i].foodWithinVision[j] << " " << world->foodStuff[world->organisms[i].foodWithinVision[j]].pos << ":" 
                    << world->OFDistances[i][world->organisms[i].foodWithinVision[j]] << " ";
            }
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
    return;
}

void SimulationEngine::preTimeStep()
{
    World* world = World::getWorld();
    
    world->calculateOFDistance();
    world->calculateOODistance();
    world->organismVision_Reach();
    //ORGANISMS CAN SEE EACH OTHER BASED ON THEIR VISION PARAMETER!
    //checkVision();
}



void SimulationEngine::timeStep()
{
    World* world = World::getWorld();

    world->OOInteractions(); 
    world->OFInteractions();
    world->organismDecision();
    //checkOFDistance();
    world->updatePositions();
    world->updateEnergy();
}

void SimulationEngine::postTimeStep()
{
    World* world = World::getWorld();
    //world->printOrganismStats();
    world->initNewOrganisms();
    world->updateOrganisms();
    world->updateFood();
    world->updateHealth();

    world->spawnFood();
    stepCount++;
}
bool SimulationEngine::isSimInit()
{
    return true;
}

bool SimulationEngine::isWorldInit()
{
    return true;
}

