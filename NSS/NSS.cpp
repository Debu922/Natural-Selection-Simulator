// NSS.cpp : This file contains the 'main' function. Program execution begins and ends there.

/*
Author: Debaditya Bhattacharya
Version: 0.3gamma
*/
#include <iostream>
#include "CLIEngine.h"
#include "SimulationEngine.h"

std::string version;

int main()
{
    SimulationEngine* sim = SimulationEngine::getSim();
    version = "0.3gamma";
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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
