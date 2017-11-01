#include "stdafx.h"
#include "Block.h"

Block::Block(int positionXBottom, int positionY) {
	Block::positionXBottom_ = positionXBottom;
	Block::positionLeftY_ = positionY;
}
int Block::getPositionXBottom() const {
	return Block::positionXBottom_;
}
int Block::getPositionLeftY() const {
	return Block::positionLeftY_;
}
