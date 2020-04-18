#include "world.h"
#include <vector>

class SimulationEngine
{
private:
    static SimulationEngine sim;
protected:
    std::vector<int[2]> OOInteractionID;
    std::vector<int[2]> OFIntearctionID;
public:
    void startUI();
    void initWorld();
    void initSim();
    void startSim();

    static SimulationEngine* getSim() { return &sim; }

    void preTimeStep();
    void timeStep();
    void postTimeStep();

    bool isSimInit();
    bool isWorldInit();
};

