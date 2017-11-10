#ifndef BLOCK_H
#define BLOCK_H

#include "Enemy.h"

class Block : public Enemy {

public:
	Block(int positionBottomX, int positionLeftY);
	virtual ~Block();
	void print();
};

#endif BLOCK_H