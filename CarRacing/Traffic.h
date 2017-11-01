#ifndef TRAFFIC_H
#define TRAFFIC_H

#include "Car.h"
class Traffic : public Active
{
public:
	Traffic(int positionBottomX, int positionY);
	inline void moveDown();
	inline void setSpeed(int speed);
	inline int getSpeed() const;
	void print();

private:
	int speed_;
};

inline void Traffic::moveDown() {
	positionBottomX_++;
}
inline void Traffic::setSpeed(int speed) {
	speed_ = speed;
}
inline int Traffic::getSpeed() const {
	return speed_;
}

#endif TRAFFIC_H