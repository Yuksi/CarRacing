#include "stdafx.h"
#include "Block.h"
#include "Constants.h"
#include <iostream>

Block::Block(int positionBottomX, int positionLeftY) {
	sizeX_ = CarRacingNamespace::Constants::blockSize;
	sizeY_ = CarRacingNamespace::Constants::blockSize;
	positionBottomX_ = positionBottomX;
	positionLeftY_ = positionLeftY;
	isNoMatterOfPosition_ = true;
}
Block::~Block() {}
void Block::print() {
	for (int i = 0; i < sizeX_; i++) {
		int blockLine = getPositionBottomX() - i;
		if (blockLine >= 0 && blockLine < CarRacingNamespace::Constants::nRows) {
			putConsoleCursorToXY(getPositionLeftY(), blockLine);
			for (int k = 0; k <sizeX_; k++) {
				std::cout << CarRacingNamespace::Constants::blockSymbol;
			}
		}
		if (blockLine - sizeX_ >= 0 && blockLine - sizeX_ < CarRacingNamespace::Constants::nRows) {
			putConsoleCursorToXY(getPositionLeftY(), blockLine - sizeX_);
			for (int k = 0; k < sizeX_; k++) {
				std::cout << CarRacingNamespace::Constants::spaceSymbol;
			}
		}
	}
}
