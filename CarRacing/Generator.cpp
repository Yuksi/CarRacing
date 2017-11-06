#include "stdafx.h"
#include <random>

#include "Generator.h"

#include "Constants.h"
#include "Block.h"

Generator::Generator()
{
}

int Generator::generatePositionLeftY(int activeSize) {
	return (1 + rand() % (CarRacingNamespace::Constants::nColumns - 1 - activeSize - 1));
}

Block Generator::generateBlock() {
	int blockLeftPoint = generatePositionLeftY(CarRacingNamespace::Constants::blockSize);
	Block block = Block(0, blockLeftPoint);
	return block;
}

Traffic Generator::generateTraffic() {
	int carLeftPoint = generatePositionLeftY(CarRacingNamespace::Constants::carSizeY);
	Traffic traffic = Traffic(0, carLeftPoint);
	return traffic;
}

