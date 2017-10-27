#pragma once
class Car {
	private:
		//left Y coordinate of the car
		int positionY_;

	public:
		Car();
		void moveLeft();
		void moveRight();
		int getPositionY();
		//car sizes
		static const int sizeX = 4, sizeY = 3;
};
