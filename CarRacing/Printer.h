#ifndef PRINTER_H
#define PRINTER_H

#include "Car.h"
#include "Block.h"

class Printer
{
public:
	Printer();
	void printScreen(Car &car);
	void rePrintCar(int oldCarPositionLeftY, Car &car);
	void rePrintSpeed(int speed);
	void rePrintDistance(int distance);
	void printBlock(Block block);
	void printGameOver();
private:
	void gotoXY(int x, int y);
};

#endif PRINTER_H
