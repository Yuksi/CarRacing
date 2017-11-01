#ifndef BLOCK_H
#define BLOCK_H

#include "Active.h"

class Block : public Active {

public:
	Block(int positionBottomX, int positionLeftY);
	inline void moveDownOnScreen();
	void print();
};

inline void Block::moveDownOnScreen() {
	positionBottomX_++;
}

#endif BLOCK_H