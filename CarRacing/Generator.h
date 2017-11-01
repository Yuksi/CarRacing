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
};

#endif GENERATOR_H