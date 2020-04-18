#include "Organism.h"
#include <iostream>
#include "World.h"

Organism::Organism()
{
    visibility = 10.0;
    reach = 2.0;
}

Organism::Organism(std::vector<Organism> organisms)
{

    visibility = 10.0;
    reach = 2.0;
}

Organism::Organism(int x)
{
    id = x;
    visibility = 10.0;
    reach = 2.0;
}


Organism::Organism(Organism m, Organism f)
{
    // TODO (debbh#1#03/24/20): Need to introduce gamete fusion after returning meiosis geneated chromo
}

Organism::~Organism()
{
    //
}

int Organism::getID()
{
    return id;
}

bool Organism::isVisible(float x)
{
    //TODO NOT INITIALIZED!
    return visibility > x;
}
bool Organism::isReachable(float x)
{
    //TODO NOT INITIALIZED!
    return reach > x;
}

void Organism::scanEnvironment(int id)
{
    World* world = World::getWorld();

    organismsWithinVision.clear();
    foodWithinVision.clear();
    organismsWithinReach.clear();
    foodWithinReach.clear();
    for (unsigned int i = 0; i < world->OODistances[id].size(); i++)
    {
        //std::cout<<world->OODistances[id][i];
        if (isVisible(world->OODistances[id][i]))
        {
            organismsWithinVision.push_back(i);
        }
        if (isReachable(world->OODistances[id][i]))
        {
            organismsWithinReach.push_back(i);
        }
    }
    for (unsigned int i = 0; i < world->OFDistances[id].size(); i++)
    {
        if (isVisible(world->OFDistances[id][i]))
        {
            foodWithinVision.push_back(i);
        }
        if (isReachable(world->OFDistances[id][i]))
        {
            foodWithinReach.push_back(i);
        }
    }
}

void Organism::setReach(float reach)
{
    this->reach = reach;
}

void Organism::getVision()
{

}

void Organism::judgement()
{
    int closeFriendly;
    int closeFoe;
}


