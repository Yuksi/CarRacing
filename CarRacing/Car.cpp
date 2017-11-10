#include "stdafx.h"
#include "Car.h"
#include "Constants.h"
#include <iostream>

Car::Car()
{
	sizeY_ = CarRacingNamespace::Constants::carSizeY;
	sizeX_ = CarRacingNamespace::Constants::carSizeX;
	positionLeftY_ = (sizeY_ * 2) + 1;
	positionBottomX_ = CarRacingNamespace::Constants::nRows - 1;
}

void Car::print() {
	for (int i = 0; i < sizeX_; i++) {
		if (oldPositionLeftY_ > 0) {
			for (int k = 0; k < sizeY_; k++) {
				putConsoleCursorToXY(oldPositionLeftY_ + k, getPositionBottomX() - i);
				std::cout << CarRacingNamespace::Constants::spaceSymbol;
			}
		}

		for (int k = 0; k < sizeY_; k++) {
			putConsoleCursorToXY(getPositionLeftY() + k, getPositionBottomX() - i);
			std::cout << CarRacingNamespace::Constants::carSymbol;
		}
	}
}
