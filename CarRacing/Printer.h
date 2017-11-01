<<<<<<< HEAD
#ifndef PRINTER_H
#define PRINTER_H

#include "Car.h"
#include "Block.h"
#include "Traffic.h"

class Printer
{
public:
	Printer();
	void printScreen(Car car);
	void rePrintCar(const int oldCarPositionLeftY, Car car);
	void rePrintSpeed(const int speed);
	void rePrintDistance(const int distance);
	void rePrintLevel(const int level);
	void printBlock(Block block);
	void printTraffic(Traffic traffic);
	void printGameOver();
private:
	void putConsoleCursorToXY(const int x, const int y);

	Printer(const Printer&) = delete;
	void operator=(const Printer&) = delete;
};

#endif PRINTER_H
=======
#ifndef PRINTER_H
#define PRINTER_H

#include "Car.h"
#include "Block.h"
#include "Traffic.h"

class Printer
{
public:
	Printer();
	void printScreen(Car car);
	void rePrintCar(const int oldCarPositionLeftY, Car car);
	void rePrintSpeed(const int speed);
	void rePrintDistance(const int distance);
	void rePrintLevel(const int level);
	void printBlock(Block block);
	void printTraffic(Traffic traffic);
	void printGameOver();
private:
	void putConsoleCursorToXY(const int x, const int y);

	Printer(const Printer&) = delete;
	void operator=(const Printer&) = delete;
};

#endif PRINTER_H
>>>>>>> Revert "levels & traffic & fixes & pause"
