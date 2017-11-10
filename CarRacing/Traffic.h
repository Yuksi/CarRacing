#ifndef TRAFFIC_H
#define TRAFFIC_H

#include "Enemy.h"
#include "Constants.h"

class Traffic : public Enemy
{
public:
	Traffic(int positionBottomX, int positionY);
	virtual ~Traffic();
	void print();

private:
	inline void findAndSetRightPosition();
};

inline void Traffic::findAndSetRightPosition() {
	if (positionLeftY_ >= CarRacingNamespace::Constants::nColumns / 2) {
		isRightPosition_ = true;
	}
	else {
		isRightPosition_ = false;
	}
}

#endif TRAFFIC_H