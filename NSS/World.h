#pragma once
#include <vector>
#include "Organism.h"
#include "Food.h"

class World
{
    friend class Organism;

public:

    static World* getWorld()
    {
        return &world;
    }

    World();

    float getDistance(Organism a, Organism b);
    float getDistance(Organism a, Food b);
    //static float* getGlobalReach() {
    //    return &globalReach;
    //}

    //setVariables
    void setSize(float x, float y);
    void setSeed(int x);
    void setOrganismCount(int x);
    void setFoodCount(int x);
    void setGlobalReach(float x);
    

    void randomizeOrganismPosition();
    void randomizeFoodPosition();

    void calculateOODistance();
    void calculateOFDistance();
    void organismDecision();
    void organismVision_Reach();
    void OOInteractions();
    void OFInteractions();

    void initNewOrganisms();
    void killOldOrganisms();
    void updateHealth();
    void updatePositions();
    void spawnFood();
    void updateEnergy();
    
    //logging
    void printParams();
    void printOrganismStats();

    //dataVectors
    std::vector<Organism> organisms;
    std::vector<Food> foodStuff;
    std::vector<std::vector<float>> OODistances;
    std::vector<std::vector<float>> OFDistances;

private:

    //permanentVariables
    int seed;
    float xSize;
    float ySize;
    float geneCopyErrorProb;

    static World world;
    //static float globalReach;
    //dynamicVariables
    int organismCount;
    int foodCount;
    long timeStep;
};

//float World::globalReach = 0.0;