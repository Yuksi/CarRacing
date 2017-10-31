#include "stdafx.h"
#include "Car.h"

static const int sizeX = 4, sizeY = 3;

Car::Car()
{
	Car::positionLeftY_ = (sizeY * 2) + 1;
}
		
void Car::moveLeft() {
	Car::positionLeftY_ -= sizeY;
}

void Car::moveRight() {
	Car::positionLeftY_ += sizeY;
}

int Car::getPositionLeftY() const {
	return positionLeftY_;
}
