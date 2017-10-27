#include "stdafx.h"
#include "Block.h"

Block::Block(int positionXBottom, int positionY) {
	Block::positionXBottom_ = positionXBottom;
	Block::positionY_ = positionY;
}
void Block::moveDownOnScreen() {
	Block::positionXBottom_++;
}
int Block::getPositionXBottom() {
	return Block::positionXBottom_;
}
int Block::getPositionY() {
	return Block::positionY_;
}
