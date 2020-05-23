#include "Position.h"

Position::Position()
{
    direction = 0;
    xPos = 0;
    yPos = 0;
    //ctor
}

Position::~Position()
{
    //dtor
}

void Position::updatePos(float x, float y)
{
    xPos = x;
    yPos = y;
}

void Position::updateDir(float x)
{
    direction = x;
}

float Position::getXPos()
{
    return xPos;
}

float Position::getYPos()
{
    return yPos;
}
float Position::getDirection()
{
    return direction;
}

std::ostream& operator<<(std::ostream& os, const Position& x)
{
    return os << "(" << x.xPos << "," << x.yPos << ","<< x.direction <<")";
}
