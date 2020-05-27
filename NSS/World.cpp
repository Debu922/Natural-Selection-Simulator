#include "World.h"
#include <iostream>
#include <iomanip>
#include "Utils.h"
#include "Organism.h"
#include "SimulationEngine.h"

World World::world;

World::World()
{
    seed = 0;
    xSize = 0;
    ySize = 0;
    organisms.resize(0);
    foodStuff.resize(0);
}


float World::getDistance(Organism a, Organism b)
{
    return distance(a.pos, b.pos);
}

float World::getDistance(Organism a, Food b)
{
    return distance(a.pos, b.pos);
}

void World::setSize(float x, float y)
{
    xSize = x;
    ySize = y;
}

void World::setSeed(int x)
{
    seed = x;
    ::setRandSeed(x);
}

void World::setOrganismCount(int x)
{
    organisms.clear();
    for (int i = 0; i < x; i++) {
        Organism temp;
        organisms.push_back(temp);
    }
}

void World::setFoodCount(int x)
{
    foodStuff.resize(x);
}

void World::setGlobalReach(float x)
{
    //globalReach = x;
}

void World::printParams()
{
    std::cout << std::fixed << std::setw(11) << std::setprecision(2);
    std::cout << "World Parameters\n";
    std::cout << "Seed:\t\t " << seed << "\n";
    std::cout << "Size(X x Y):\t " << xSize << " x " << ySize << "\n";
    std::cout << "timeStep:\t " << timeStep << "\n";
    std::cout << "Organism count:\t " << organisms.size() << "\n";
    std::cout << "Food count:\t " << foodStuff.size() << "\n";
}

void World::printOrganismStats()
{
    for (int i = 0; i < organisms.size(); i++) {
        std::cout << "ID: " << i << " ";
        organisms[i].printAttributes();
    }
}

void World::randomizeOrganismPosition()
{
    for (unsigned int i = 0; i < organisms.size(); i++)
    {
        organisms[i].pos.updatePos(randF(xSize), randF(ySize));
        organisms[i].pos.updateDir(randF(360));
    }
}

void World::randomizeFoodPosition()
{
    for (unsigned int i = 0; i < foodStuff.size(); i++)
    {
        foodStuff[i].pos.updatePos(randF(xSize), randF(ySize));
        foodStuff[i].updateAmount(25 + randF(75));
    }
}

void World::calculateOODistance()
{
    int orgSize = organisms.size();
    OODistances.resize(orgSize);
    for (int i = 0; i < orgSize; i++)
    {
        OODistances[i].resize(orgSize);
    }
    for (int i = 0; i < orgSize; i++)
    {
        for (int j = 0; j < orgSize; j++)
        {
            OODistances[i][j] = getDistance(organisms[i], organisms[j]);
        }
    }

}

void World::calculateOFDistance()
{
    int orgSize = organisms.size();
    int foodSize = foodStuff.size();
    OFDistances.resize(orgSize);
    for (int i = 0; i < orgSize; i++)
    {
        OFDistances[i].resize(foodSize);
    }
    for (int i = 0; i < orgSize; i++)
    {
        for (int j = 0; j < foodSize; j++)
        {
            OFDistances[i][j] = distance(organisms[i].pos, foodStuff[j].pos);
        }
    }
}

void World::organismVision_Reach()
{
    for (unsigned int i = 0; i < organisms.size(); i++)
    {
        organisms[i].scanEnvironment(i);
    }
}


void World::organismDecision()
{
    for (unsigned int i = 0; i < organisms.size(); i++)
    {
        organisms[i].foodJudgement(i);
    }
}

void World::OOInteractions()
{
    //for (int i = 0; i < organisms.size(); i++) {
    //    if (organisms[i].organismsWithinReach.size() != 0) {
    //        organisms[i].organismInteract(i);
    //    }
    //}
}

void World::OFInteractions()
{
    for (int i = 0; i < organisms.size(); i++) {
        if (organisms[i].foodWithinReach.size() != 0) {
            organisms[i].foodInteract(i);
        }
    }
}

void World::initNewOrganisms()
{

}

void updateHungerState(Organism* organism) {
    if (organism->energy > 50) {
        organism->state.isHungry = false;
    }
    else {
        organism->state.isHungry = true;
    }
}

void updateCooldown(Organism* organism) {
    if (organism->state.cooldown > 0) {
        organism->state.cooldown--;
    }
}

void updateWanderState(Organism* organism) {
    if (!organism->state.isFlee && !organism->state.isChaseMate && !organism->state.isHungry && (organism->state.targetFood != -1)) {
        organism->state.wander = true;
    }
}

void World::updateOrganisms()
{
    SimulationEngine* sim = SimulationEngine::getSim();
    for (int i = 0; i < organisms.size(); i++) {
        updateCooldown(&organisms[i]);
        updateHungerState(&organisms[i]);
        updateWanderState(&organisms[i]);
        
    }
    //Kill Organism
    for (int i = organisms.size() - 1; i > -1; i--) {
        if (organisms[i].energy <= 0) {
            organisms.erase(organisms.begin() + i);
            std::cout << sim->stepCount << " Organism Killed" << std::endl;
        }
    }
}

void World::updateHealth()
{

}

void World::updatePositions()
{
    for (int i = 0; i < organisms.size(); i++) {
        Organism* organism = &organisms[i];
        organism->updateDirection(i);
        organism->move(i);
    }
}

void World::updateFood()
{   
    SimulationEngine* sim = SimulationEngine::getSim();
    for (int i = foodStuff.size() - 1; i > -1; i--) {
        if (sim->stepCount % 100 == 0) {
            std::cout << i << " " << foodStuff[i].getAmount()<<std::endl;
        }
        if (foodStuff[i].getAmount() <= 0) {
            foodStuff.erase(foodStuff.begin() + i);
            std::cout << sim->stepCount<< " - Food Deleted" << std::endl;
        }
    }
}

void World::spawnFood()
{

}

void World::updateEnergy()
{
    for (int i = 0; i < organisms.size(); i++) {
        organisms[i].energy -= 0.5 * (1 - organisms[i].enzymeEfficiency);
        organisms[i].enzymeEfficiency *= 0.99;
    }
}