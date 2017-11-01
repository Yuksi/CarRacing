#include "stdafx.h"
#include "Block.h"
#include "Constants.h"
#include <iostream>
using namespace CarRacingNamespace;

Block::Block(int positionBottomX, int positionLeftY) {
	positionBottomX_ = positionBottomX;
	positionLeftY_ = positionLeftY;
}
void Block::print() {
	for (int i = 0; i < Constants::blockSize; i++) {
		int blockLine = getPositionBottomX() - i;
		if (blockLine >= 0 && blockLine < Constants::nRows) {
			putConsoleCursorToXY(getPositionLeftY(), blockLine);
			for (int k = 0; k < Constants::blockSize; k++) {
				std::cout << Constants::blockSymbol;
			}
		}
		if (blockLine - Constants::blockSize >= 0 && blockLine - Constants::blockSize < Constants::nRows) {
			putConsoleCursorToXY(getPositionLeftY(), blockLine - Constants::blockSize);
			for (int k = 0; k < Constants::blockSize; k++) {
				std::cout << Constants::spaceSymbol;
			}
		}
	}
}
