#ifndef CAR_H
#define CAR_H

#include "Active.h"
#include "Constants.h"

class Car : public Active {

public:
	Car();
	inline void moveLeft();
	inline void moveRight();
	void print();

private:
	int oldPositionLeftY_;
};

inline void Car::moveLeft() {
	oldPositionLeftY_ = positionLeftY_;
	positionLeftY_ -= CarRacingNamespace::Constants::carSizeY;
}
inline void Car::moveRight() {
	oldPositionLeftY_ = positionLeftY_;
	positionLeftY_ += CarRacingNamespace::Constants::carSizeY;
}

#endif CAR_H