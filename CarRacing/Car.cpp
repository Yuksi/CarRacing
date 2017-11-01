<<<<<<< HEAD
#include "stdafx.h"
#include "Car.h"
#include "Constants.h"

Car::Car()
{
	Car::positionLeftY_ = (CarRacingNamespace::Constants::carSizeY * 2) + 1;
	Car::positionBottomX_ = CarRacingNamespace::Constants::nRows - 1;
}

int Car::getPositionLeftY() const {
	return positionLeftY_;
}

int Car::getPositionBottomX() const {
	return positionBottomX_;
}

int Car::getSpeed() const {
	return speed_;
}
=======
#include "stdafx.h"
#include "Car.h"
#include "Constants.h"

Car::Car()
{
	Car::positionLeftY_ = (CarRacingNamespace::Constants::carSizeY * 2) + 1;
	Car::positionBottomX_ = CarRacingNamespace::Constants::nRows - 1;
}

int Car::getPositionLeftY() const {
	return positionLeftY_;
}

int Car::getPositionBottomX() const {
	return positionBottomX_;
}

int Car::getSpeed() const {
	return speed_;
}
>>>>>>> Revert "levels & traffic & fixes & pause"
