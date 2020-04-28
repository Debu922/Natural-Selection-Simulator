#include "Genome.h"
#include "World.h"
#include "Utils.h"
#include <iostream>
Genome::Genome()
{
    
}   
Genome::Genome(GeneticMaterial X, GeneticMaterial Y) {
    this->X = X;
    this->Y = Y;
}
void Genome::initRandomGeneticMaterial()
{
    X.bodySize.dominance = randF(1);
    X.bodySize.value = randI(256);
    X.brainDev.dominance = randF(1);
    X.brainDev.value = randI(256);
    X.eyeSight.dominance = randF(1);
    X.eyeSight.value = randI(256);
    X.feathers.dominance = randF(1);
    X.feathers.value = randI(256);
    X.feetSize.dominance = randF(1);
    X.feetSize.value = randI(256);
    X.handSize.dominance = randF(1);
    X.handSize.value = randI(256);
    X.maxEnzymeEfficiency.dominance = randF(1);
    X.maxEnzymeEfficiency.value = randI(256);
    X.reactionTime.dominance = randF(1);
    X.reactionTime.value = randI(256);

    Y.bodySize.dominance = randF(1);
    Y.bodySize.value = randI(256);
    Y.brainDev.dominance = randF(1);
    Y.brainDev.value = randI(256);
    Y.eyeSight.dominance = randF(1);
    Y.eyeSight.value = randI(256);
    Y.feathers.dominance = randF(1);
    Y.feathers.value = randI(256);
    Y.feetSize.dominance = randF(1);
    Y.feetSize.value = randI(256);
    Y.handSize.dominance = randF(1);
    Y.handSize.value = randI(256);
    Y.maxEnzymeEfficiency.dominance = randF(1);
    Y.maxEnzymeEfficiency.value = randI(256);
    Y.reactionTime.dominance = randF(1);
    Y.reactionTime.value = randI(256);
}
GeneticMaterial Genome::meiosis()
{
  
    GeneticMaterial temp;

    return temp;
}

ExpressedGene Genome::getExpressedGene()
{
    ExpressedGene output;
    output.bodySize = X.bodySize.dominance > Y.bodySize.dominance ? X.bodySize.value : Y.bodySize.value;
    output.brainDev = X.brainDev.dominance > Y.brainDev.dominance ? X.brainDev.value : Y.brainDev.value;
    output.maxEnzymeEfficiency = X.maxEnzymeEfficiency.dominance > Y.maxEnzymeEfficiency.dominance ? X.maxEnzymeEfficiency.value : Y.maxEnzymeEfficiency.value;
    output.eyeSight = X.eyeSight.dominance > Y.eyeSight.dominance ? X.eyeSight.value : Y.eyeSight.value;
    output.feetSize = X.feetSize.dominance > Y.feetSize.dominance ? X.feetSize.value : Y.feetSize.value;
    output.handSize = X.handSize.dominance > Y.handSize.dominance ? X.handSize.value : Y.handSize.value;
    output.reactionTime = X.reactionTime.dominance > Y.reactionTime.dominance ? X.reactionTime.value : Y.reactionTime.value;
    output.feathers = X.feathers.dominance > Y.feathers.dominance ? X.feathers.value : Y.feathers.value;
    return output;
}
