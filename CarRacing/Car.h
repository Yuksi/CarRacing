#ifndef CAR_H
#define CAR_H

class Car {

public:
		Car();
		void moveLeft();
		void moveRight();
		int getPositionLeftY() const;
		static const int sizeX = 4, sizeY = 3;

private:
	    int positionLeftY_;
};

#endif CAR_H