#pragma once
#include "Position.h"
#include <string>

class Food
{
public:
    Food();
    void updateAmount(float x);
    float getAmount();

    Position pos;

protected:
    float amount;
    std::string type;
private:
};

