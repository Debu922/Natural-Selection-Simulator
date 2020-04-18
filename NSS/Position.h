#pragma once
#include <iostream>
#include <istream>

class Position
{
public:
    Position();
    virtual ~Position();
    void updatePos(float x, float y);
    void updateDir(float x);
    float getXPos();
    float getYpos();
    float getDirection();
    friend std::ostream& operator<<(std::ostream&, Position const& x);
protected:
    float xPos;
    float yPos;
    float direction;
private:
};

std::ostream& operator<<(std::ostream& os, const Position& x);