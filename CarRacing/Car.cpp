#include "stdafx.h"
#include "Car.h"
#include "Constants.h"
#include <iostream>
using namespace CarRacingNamespace;

Car::Car()
{
	positionLeftY_ = (CarRacingNamespace::Constants::carSizeY * 2) + 1;
	positionBottomX_ = CarRacingNamespace::Constants::nRows - 1;
}

void Car::print() {
	for (int i = 0; i < Constants::carSizeX; i++) {
		if (oldPositionLeftY_ > 0) {
			for (int k = 0; k < Constants::carSizeY; k++) {
				putConsoleCursorToXY(oldPositionLeftY_ + k, getPositionBottomX() - i);
				std::cout << Constants::spaceSymbol;
			}
		}

		for (int k = 0; k < Constants::carSizeY; k++) {
			putConsoleCursorToXY(getPositionLeftY() + k, getPositionBottomX() - i);
			std::cout << Constants::carSymbol;
		}
	}
}
