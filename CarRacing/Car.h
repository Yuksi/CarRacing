#pragma once
class Car {

public:
		Car();
		void moveLeft();
		void moveRight();
		int getPositionY();
		//car sizes
		static const int sizeX = 4, sizeY = 3;

private:
	    //center Y coordinate of the car
	    int positionY_;
};
