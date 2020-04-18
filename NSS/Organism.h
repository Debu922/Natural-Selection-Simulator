#pragma once
#include "Position.h"
#include "Genome.h"
#include <vector>

struct State {
    bool isFlee;
    bool isFight;
    bool isMate;
    bool isFood;
    int foodInAttention;
    int organismInAttention;
};

struct Attributes {
    float intelligence;
    float vision;
    float agility;
    float fightingCapability;
    float strength;
    float attractiveness;
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
    void setReach(float reach);
    void getVision();
    void judgement();

    Position pos;

    bool isReachable(float x);
    bool isVisible(float x);
    State state;

    int getID();
    std::vector<int> organismsWithinVision;
    std::vector<int> organismsWithinReach;
    std::vector<int> foodWithinVision;
    std::vector<int> foodWithinReach;
protected:
    Genome genome;
    float energy;
    float health;
    float maxHealth;
    float enzymeEfficiency;
    float reach = 1;
    float visibility = 10;
    int age;
    int id;
private:

};