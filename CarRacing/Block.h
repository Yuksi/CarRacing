#pragma once
class Block {

public:
	Block(int positionXBottom, int positionY);
	void moveDownOnScreen();
	int getPositionXBottom();
	int getPositionY();
	//block sizes
	static const int size = 3;

private:
	//center Y block coordinate
	int positionY_;
	//X bottom block coordinate
	int positionXBottom_;
};

