#include "stdafx.h"
#include "Traffic.h"
#include <iostream>

Traffic::Traffic(int positionXBottom, int positionY) {
	sizeX_ = CarRacingNamespace::Constants::carSizeX;
	sizeY_ = CarRacingNamespace::Constants::carSizeY;
	positionBottomX_ = positionXBottom;
	positionLeftY_ = positionY;
	isNoMatterOfPosition_ = false;
	findAndSetRightPosition();
}

Traffic::~Traffic() {}

void Traffic::print() {
	for (int i = 0; i < sizeX_; i++) {
		int trafficLine = getPositionBottomX() - i;
		if (trafficLine >= 0 && trafficLine < CarRacingNamespace::Constants::nRows) {
			putConsoleCursorToXY(getPositionLeftY(), trafficLine);
			for (int k = 0; k < sizeY_; k++) {
				std::cout << CarRacingNamespace::Constants::trafficSymbol;
			}
		}
		if (trafficLine - sizeX_ >= 0 && trafficLine - sizeX_ < CarRacingNamespace::Constants::nRows) {
			putConsoleCursorToXY(getPositionLeftY(), trafficLine - sizeX_);
			for (int k = 0; k < sizeY_; k++) {
				std::cout << CarRacingNamespace::Constants::spaceSymbol;
			}
		}
	}
}

