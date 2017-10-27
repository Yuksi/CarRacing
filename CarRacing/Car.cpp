#include "stdafx.h"
#include "Car.h"

static const int sizeX = 4, sizeY = 3;

Car::Car()
{
	Car::positionY_ = (sizeY * 2) + 2;
}
		
void Car::moveLeft() {
	Car::positionY_ -= 3;
}

void Car::moveRight() {
	Car::positionY_ += 3;
}

int Car::getPositionY() {
	return positionY_;
}
