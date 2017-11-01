#pragma once
#include "Car.h"
class Traffic : public Car
{
public:
	Traffic(int positionXBottom, int positionY);
	inline void Traffic::moveDown() {
		Traffic::positionBottomX_++;
	}
	inline void Traffic::setSpeed(int speed) {
		Traffic::speed_ = speed;
	}
	int getPositionLeftY() const;
	int getPositionBottomX() const;
	int getSpeed() const;

private:
	int positionLeftY_;
	int positionBottomX_;
	int speed_;
};

