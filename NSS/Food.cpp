#include "Food.h"

Food::Food()
{
    this->amount = 0;
    //ctor
}

void Food::updateAmount(double x)
{
    amount = x;
}

float Food::getAmount()
{
	return amount;
}
