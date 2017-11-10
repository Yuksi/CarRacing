#ifndef CAR_H
#define CAR_H

#include "Active.h"

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
	positionLeftY_ -= sizeY_;
}
inline void Car::moveRight() {
	oldPositionLeftY_ = positionLeftY_;
	positionLeftY_ += sizeY_;
}

#endif CAR_H