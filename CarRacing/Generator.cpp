#include "stdafx.h"
#include <random>

#include "Generator.h"
#include "Constants.h"
#include "Block.h"
#include "Traffic.h"

Generator::Generator()
{
}

int Generator::generatePositionLeftY(int activeSize) {
	return (1 + rand() % (CarRacingNamespace::Constants::nColumns - 1 - activeSize - 1));
}

Enemy* Generator::generateEnemy(Enemies enemyId) {
	Enemy* enemy;
	int enemyLeftPoint;
	switch (enemyId)
	{
	case BLOCK:
		enemyLeftPoint = generatePositionLeftY(CarRacingNamespace::Constants::blockSize);
		enemy = new Block(0, enemyLeftPoint);
		break;
	case TRAFFIC:
		enemyLeftPoint = generatePositionLeftY(CarRacingNamespace::Constants::carSizeY);
		enemy = new Traffic(0, enemyLeftPoint);
		break;
	default:
		enemy = NULL;
	}
	return enemy;
}