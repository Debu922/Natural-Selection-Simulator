#pragma once
#include "Position.h"
#include <string>

class Food
{
public:
    Food();
    void upddateAmount(double x);

    Position pos;

protected:
    double amount;
    std::string type;
private:
};

