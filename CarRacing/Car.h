<<<<<<< HEAD
#ifndef CAR_H
#define CAR_H

#include "Constants.h"

class Car {

public:
	Car();
	inline void Car::moveLeft() {
		Car::positionLeftY_ -= CarRacingNamespace::Constants::carSizeY;
	}

	inline void Car::moveRight() {
		Car::positionLeftY_ += CarRacingNamespace::Constants::carSizeY;
	}
	inline void Car::setSpeed(int speed) {
		Car::speed_ = speed;
	}
	int getPositionLeftY() const;
	int getPositionBottomX() const;
	int getSpeed() const;

private:
	int positionLeftY_;
	int positionBottomX_;
	int speed_;
};

=======
#ifndef CAR_H
#define CAR_H

#include "Constants.h"

class Car {

public:
	Car();
	inline void Car::moveLeft() {
		Car::positionLeftY_ -= CarRacingNamespace::Constants::carSizeY;
	}

	inline void Car::moveRight() {
		Car::positionLeftY_ += CarRacingNamespace::Constants::carSizeY;
	}
	inline void Car::setSpeed(int speed) {
		Car::speed_ = speed;
	}
	int getPositionLeftY() const;
	int getPositionBottomX() const;
	int getSpeed() const;

private:
	int positionLeftY_;
	int positionBottomX_;
	int speed_;
};

>>>>>>> Revert "levels & traffic & fixes & pause"
#endif CAR_H