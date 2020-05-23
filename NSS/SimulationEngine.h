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
    void startSim(int steps);

    static SimulationEngine* getSim() { return &sim; }

    void preTimeStep();
    void timeStep();
    void postTimeStep();

    void checkVision();
    void checkOFDistance();

    bool isSimInit();
    bool isWorldInit();

    int stepCount = 0;
};

