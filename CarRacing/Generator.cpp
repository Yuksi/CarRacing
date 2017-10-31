#include "stdafx.h"
#include <random>

#include "Generator.h"

#include "Constants.h"
#include "Block.h"

Generator::Generator()
{
}

Block Generator::generateBlock() {
	int blockLeftPoint = 1 + rand() % (Constants::nColumns - 1 - Block::size);
	Block block = Block(0, blockLeftPoint);
	return block;
}
