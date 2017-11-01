#include "stdafx.h"
#include "Traffic.h"
#include "Constants.h"
#include <iostream>
using namespace CarRacingNamespace;

Traffic::Traffic(int positionXBottom, int positionY) {
	positionBottomX_ = positionXBottom;
	positionLeftY_ = positionY;
}

void Traffic::print() {
	for (int i = 0; i < Constants::carSizeX; i++) {
		int trafficLine = getPositionBottomX() - i;
		if (trafficLine >= 0 && trafficLine < Constants::nRows) {
			putConsoleCursorToXY(getPositionLeftY(), trafficLine);
			for (int k = 0; k < Constants::carSizeY; k++) {
				std::cout << Constants::trafficSymbol;
			}
		}
		if (trafficLine - Constants::carSizeX >= 0 && trafficLine - Constants::carSizeX < Constants::nRows) {
			putConsoleCursorToXY(getPositionLeftY(), trafficLine - Constants::carSizeX);
			for (int k = 0; k < Constants::carSizeY; k++) {
				std::cout << Constants::spaceSymbol;
			}
		}
	}
}

