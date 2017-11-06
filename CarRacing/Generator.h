#ifndef GENERATOR_H
#define GENERATOR_H

#include "Block.h"
#include "Car.h"
#include "Traffic.h"

class Generator
{
public:
	Generator();
	Block generateBlock();
	Traffic generateTraffic();

private:
	int generatePositionLeftY(int activeSize);
};

#endif GENERATOR_H