#ifndef GENERATOR_H
#define GENERATOR_H

#include "Enemy.h"
#include "Enemies.h"

class Generator
{
public:
	Generator();
	Enemy* generateEnemy(Enemies enemyId);

private:
	int generatePositionLeftY(int activeSize);
};

#endif GENERATOR_H