#include "stdafx.h"
#include <random>

#include "Generator.h"

#include "Constants.h"
#include "Block.h"

Generator::Generator()
{
}

Block Generator::generateBlock() {
	int blockLeftPoint = 1 + rand() % 
		(CarRacingNamespace::Constants::nColumns - 1 - CarRacingNamespace::Constants::blockSize - 1);
	Block block = Block(0, blockLeftPoint);
	return block;
}

Traffic Generator::generateTraffic() {
	int carLeftPoint = 1 + rand() %
		(CarRacingNamespace::Constants::nColumns - 1 - CarRacingNamespace::Constants::carSizeY - 1);
	Traffic traffic = Traffic(0, carLeftPoint);
	return traffic;
}

