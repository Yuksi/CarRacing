#ifndef TRAFFIC_H
#define TRAFFIC_H

#include "Car.h"
class Traffic : public Active
{
public:
	Traffic(int positionBottomX, int positionY);
	inline void moveDown();
	void print();

};

inline void Traffic::moveDown() {
	positionBottomX_++;
}

#endif TRAFFIC_H