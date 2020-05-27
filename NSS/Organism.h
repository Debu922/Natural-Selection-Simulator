#pragma once
#include "Position.h"
#include "Genome.h"
#include <vector>

struct State {
    bool isFlee = false;
    bool isChaseMate = false;
    bool isHungry = true;
    bool wander = false;
    int targetFood = -1;
    int fleeFrom = -1;
    int chasedMate = -1;
    int cooldown = 0;
};

struct Attributes {
    float intelligence = 0.0;
    float vision = 0.0;
    float agility = 0.0;
    float fightingCapability = 0.0;
    float strength = 0.0;
    float attractiveness = 0.0;
};
class Organism {
    friend class World;
public:
    Organism();
    Organism(std::vector<Organism> Organisms);
    Organism(int id);
    Organism(Organism m, Organism f);
    virtual ~Organism();

    void scanEnvironment(int id);
    void getVision();
    void foodJudgement(int id);
    void foodInteract(int id);
    void organismInteract(int id);
    void updateDirection(int id);
    void move(int id);

    void printAttributes();

    Position pos;
    Attributes attributes;

    bool isReachable(float x);
    bool isVisible(float x);
    State state;

    std::vector<int> organismsWithinVision;
    std::vector<int> organismsWithinReach;
    std::vector<int> foodWithinVision;
    std::vector<int> foodWithinReach;

    void generateAttributes();
    void updateAttributes();
    Genome genome;
    float energy = 50.0;
    float health = 100.0;
    float maxHealth = 100.0;
    float enzymeEfficiency = 1.0;
    float visibility = 0.0;
    int age = 0;
private:

};