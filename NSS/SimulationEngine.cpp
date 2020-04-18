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

    world->setSeed(99189898);
    world->setSize(100, 100);
    world->setOrganismCount(10);
    world->setFoodCount(100);
    world->setGlobalReach(2.0);
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

void SimulationEngine::startSim()
{
    preTimeStep();
    std::cout << "preTimeStep completed successfully\n";
    timeStep();
    std::cout << "timeStep completed successfully\n";
    postTimeStep();
    std::cout << "postTimeStep completed successfully\n";
}

void SimulationEngine::preTimeStep()
{
    World* world = World::getWorld();
    world->randomizeFoodPosition();
    std::cout << "Randomized Food Position Successfully\n";
    world->randomizeOrganismPosition();
    std::cout << "Randomized Organism Position Successfully\n";
    world->calculateOFDistance();
    std::cout << "OFD completed successfully\n";
    world->calculateOODistance();
    std::cout << "OOD completed successfully\n";
    world->organismVision_Reach();
    std::cout << "VR completed successfully\n";
}



void SimulationEngine::timeStep()
{
    World* world = World::getWorld();

    world->OOInteractions();
    world->OFInteractions();
    world->organismDecision();
    world->updatePositions();
    world->updateEnergy();
}

void SimulationEngine::postTimeStep()
{
    World* world = World::getWorld();

    world->initNewOrganisms();
    world->killOldOrganisms();
    world->updateHealth();

    world->spawnFood();
}
bool SimulationEngine::isSimInit()
{
    return true;
}

bool SimulationEngine::isWorldInit()
{
    return true;
}

