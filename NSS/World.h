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

    void setSize(float x, float y);
    void setSeed(int x);
    void setOrganismCount(int x);
    void setFoodCount(int x);

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
    void setGlobalReach(float reach);

    void initComplete();

    void printParams();

    std::vector<Organism> organisms;
    std::vector<Food> foodStuff;
    std::vector<std::vector<float>> OODistances;
    std::vector<std::vector<float>> OFDistances;
protected:

    int seed;

    float geneCopyErrorProb;

    long timeStep;
    float xSize;
    float ySize;
    float reach;

    bool isInit;
private:
    static World world;
};
