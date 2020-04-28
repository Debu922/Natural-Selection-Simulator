#pragma once

struct Gene {
    unsigned char value = 0;
    float dominance = 0;
};

struct GeneticMaterial {
    Gene eyeSight;
    Gene brainDev;
    Gene maxEnzymeEfficiency;
    Gene bodySize;
    Gene feetSize;
    Gene handSize;
    Gene reactionTime;
    Gene feathers;
};

struct ExpressedGene {
    unsigned char eyeSight;
    unsigned char brainDev;
    unsigned char maxEnzymeEfficiency;
    unsigned char bodySize;
    unsigned char feetSize;
    unsigned char handSize;
    unsigned char reactionTime;
    unsigned char feathers;
};

class Genome
{
public:
    Genome();
    Genome(GeneticMaterial X, GeneticMaterial Y);
    void initRandomGeneticMaterial();
    GeneticMaterial meiosis();
    ExpressedGene getExpressedGene();
protected:
    GeneticMaterial X, Y;
private:
};

