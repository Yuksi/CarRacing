<<<<<<< HEAD
#ifndef BLOCK_H
#define BLOCK_H

class Block {

public:
	Block(int positionXBottom, int positionY);
	inline void moveDownOnScreen() {
		Block::positionXBottom_++;
	}
	int getPositionXBottom() const;
	int getPositionLeftY() const;

private:
	int positionLeftY_;
	int positionXBottom_;
};

=======
#ifndef BLOCK_H
#define BLOCK_H

class Block {

public:
	Block(int positionXBottom, int positionY);
	inline void moveDownOnScreen() {
		Block::positionXBottom_++;
	}
	int getPositionXBottom() const;
	int getPositionLeftY() const;

private:
	int positionLeftY_;
	int positionXBottom_;
};

>>>>>>> Revert "levels & traffic & fixes & pause"
#endif BLOCK_H