#pragma once
class Block {

private:
	//left Y block coordinate
	int positionY_;
	//left X bottom block coordinate
	int positionXBottom_;

public:
	Block(int positionXBottom, int positionY);
	void moveDownOnScreen();
	int getPositionXBottom();
	int getPositionY();
	//block sizes
	static const int size = 3;
};

