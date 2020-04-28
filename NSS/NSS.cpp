// NSS.cpp : This file contains the 'main' function. Program execution begins and ends there.

/*
Author: Debaditya Bhattacharya
Version: 0.4gamma
*/
#include <iostream>
#include "CLIEngine.h"
#include "SimulationEngine.h"

std::string version;

int main()
{
    SimulationEngine* sim = SimulationEngine::getSim();
    version = "0.4gamma";
    std::cout << "NATURAL SELECTION SIMULATOR V: " << version << std::endl;
    sim->startUI();
    std::cout << "UI Started successfully\n";
    sim->initWorld();
    std::cout << "World Initialized successfully\n";
    sim->initSim();
    std::cout << "Simulation Initialized successfully\n";
    sim->startSim();
    std::cout << "Simulation Started successfully\n";
    return 0;
}

