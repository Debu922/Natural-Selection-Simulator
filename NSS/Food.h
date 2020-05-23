#pragma once
#include "Position.h"
#include <string>

class Food
{
public:
    Food();
    void updateAmount(double x);
    float getAmount();

    Position pos;

protected:
    float amount;
    std::string type;
private:
};

