#include "stdafx.h"
#include "Traffic.h"


Traffic::Traffic(int positionXBottom, int positionY) {
	Traffic::positionBottomX_ = positionXBottom;
	Traffic::positionLeftY_ = positionY;
}

int Traffic::getPositionLeftY() const {
	return positionLeftY_;
}

int Traffic::getPositionBottomX() const {
	return positionBottomX_;
}

int Traffic::getSpeed() const {
	return speed_;
}

