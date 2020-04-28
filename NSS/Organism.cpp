#include "Organism.h"
#include <iostream>
#include "World.h"

Organism::Organism()
{
    World* world = World::getWorld();
    genome.initRandomGeneticMaterial();
    generateAttributes();
    visibility = this->attributes.vision;
}

Organism::Organism(std::vector<Organism> organisms)
{
    visibility = 10.0;
}

Organism::Organism(int x)
{
    visibility = 10.0;
}


Organism::Organism(Organism m, Organism f)
{
    // TODO (debbh#1#03/24/20): Need to introduce gamete fusion after returning meiosis geneated chromo
}

Organism::~Organism()
{
    //
}

float pNormal(unsigned char x) {
    return x * (256 - x) / (256.0 * 256.0);
}

void Organism::generateAttributes()
{
    ExpressedGene expressedGene = genome.getExpressedGene();
    //enzymeEfficiency - returns present enzyme effiency always between [36,100] for fresh born.
    this->enzymeEfficiency = 36.0 + 0.25*expressedGene.maxEnzymeEfficiency;
    //intelligence - returns fraction, always between (0.1,0.99) for fresh born.
    this->attributes.intelligence = 0.1 + 0.0002 * expressedGene.brainDev * sqrt(this->enzymeEfficiency);
    //vision - returns distance can see, between (4,50)
    this->attributes.vision = 4 + (0.125 * expressedGene.eyeSight * (expressedGene.brainDev / 256.0)) * this->attributes.intelligence * 1.5;
    //agility - returns max speed NEEDS TO BE UPDATED EVERY RUN
    this->attributes.agility = 5.0 + (10 * (this->enzymeEfficiency / 100.0)) + (5.0 * (expressedGene.feetSize / 256.0))
        - 3.0 * (expressedGene.bodySize / 256.0) - 2.0 * (expressedGene.feathers / 256.0);
    //strength - returns value (10,75)
    this->attributes.strength = 10.0 + (25 * (expressedGene.bodySize / 256.0) + 20 * (expressedGene.feetSize + expressedGene.handSize) / 256.0) * this->enzymeEfficiency/100.0;
    //fighting capability returns fraction
    this->attributes.fightingCapability = (100 * (sqrt(expressedGene.handSize / 256.0)) * ((expressedGene.feetSize + expressedGene.handSize) / 265.0) + this->attributes.strength) * this->attributes.agility * this->attributes.intelligence;
    //attractiveness
    this->attributes.attractiveness = pNormal(expressedGene.feathers) + pNormal(expressedGene.bodySize) + pNormal(expressedGene.handSize) + pNormal(expressedGene.feetSize);
}

void Organism::updateAttributes()
{
    ExpressedGene expressedGene = genome.getExpressedGene();
    //agility - returns max speed NEEDS TO BE UPDATED EVERY RUN
    this->attributes.agility = 5.0 + (10 * (this->enzymeEfficiency / 100.0)) + (5.0 * (expressedGene.feetSize / 256.0))
        - 3.0 * (expressedGene.bodySize / 256.0) - 2.0 * (expressedGene.feathers / 256.0);
    //strength - returns value (10,75)
    this->attributes.strength = 10.0 + (25 * (expressedGene.bodySize / 256.0) + 20 * (expressedGene.feetSize + expressedGene.handSize) / 256.0) * this->enzymeEfficiency / 100.0;
    //fighting capability returns fraction
    this->attributes.fightingCapability = (100 * (sqrt(expressedGene.handSize / 256.0)) * ((expressedGene.feetSize + expressedGene.handSize) / 265.0) + this->attributes.strength) * this->attributes.agility * this->attributes.intelligence;
}

bool Organism::isVisible(float x)
{
    //TODO NOT INITIALIZED!
    return visibility > x;
}
bool Organism::isReachable(float x)
{
    
    //TODO NOT INITIALIZED!
    return 2.0 > x;
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

void Organism::getVision()
{

}

void Organism::judgement()
{
    int closeFriendly;
    int closeFoe;
}

void Organism::printAttributes()
{
    std::cout << "A:" << attributes.agility << " V:" << attributes.vision << " At:" << attributes.attractiveness 
        << " FC:" << attributes.fightingCapability << " I:" << attributes.intelligence << std::endl;
}


