#pragma once

struct Gene {
    unsigned char value = 0;
    float dominance = 0;
};

struct GeneticMaterial {
    Gene eyesight;
    Gene brainDev;
    Gene maxEnzymeEfficiency;
    Gene bodySize;
    Gene feetsize;
    Gene handsize;
    Gene reactionTime;
    Gene feathers;
};

class Genome
{
public:
    Genome();
    Genome(GeneticMaterial X, GeneticMaterial Y);
    GeneticMaterial meiosis();
protected:
    GeneticMaterial X, Y;
private:
};

