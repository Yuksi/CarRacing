<<<<<<< HEAD
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
	Generator(const Generator&) = delete;
	void operator=(const Generator&) = delete;
};

=======
#ifndef GENERATOR_H
#define GENERATOR_H

#include "Block.h"

class Generator
{
public:
	Generator();
	Block generateBlock();
};

>>>>>>> Revert "levels & traffic & fixes & pause"
#endif GENERATOR_H