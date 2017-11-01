<<<<<<< HEAD
#include "stdafx.h"
#include "Printer.h"

#include <windows.h>
#include <iostream>
#include <string>

#include "Constants.h"
#include "Car.h"
#include "Block.h"
using namespace CarRacingNamespace;

Printer::Printer()
{
}

void Printer::printScreen(Car car) {
	for (int i = 0; i < Constants::nRows; i++) {
		for (int k = 0; k < Constants::nColumns; k++) {

			if (k == 0 || k == Constants::nColumns - 1) {
				std::cout << Constants::boardSymbol;
			}
			else if (i <= car.getPositionBottomX() && i > car.getPositionBottomX() - Constants::carSizeX
				&& k >= car.getPositionLeftY() && k <= car.getPositionLeftY() - 1 + Constants::carSizeY) {
				std::cout << Constants::carSymbol;
			}

			else std::cout << Constants::spaceSymbol;
		}
		std::cout << std::endl;
	}

	std::cout << speedString << Constants::speedMin << std::endl;
	std::cout << distanceString << "0" << std::endl;
	std::cout << levelString << "0" << std::endl;
}

void Printer::putConsoleCursorToXY(const int x, const int y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
	);
}

void Printer::rePrintCar(const int oldCarPositionLeftY, Car car)
{
	for (int i = 0; i < Constants::carSizeX; i++) {
		for (int k = 0; k < Constants::carSizeY; k++) {
			putConsoleCursorToXY(oldCarPositionLeftY + k, car.getPositionBottomX() - i);
			std::cout << Constants::spaceSymbol;
		}

		for (int k = 0; k < Constants::carSizeY; k++) {
			putConsoleCursorToXY(car.getPositionLeftY() + k, car.getPositionBottomX() - i);
			std::cout << Constants::carSymbol;
		}
	}
}

void Printer::rePrintSpeed(const int speed) {
	putConsoleCursorToXY(speedString.length(), Constants::nRows);
	std::cout << speed;
}

void Printer::rePrintDistance(const int distance) {
	putConsoleCursorToXY(distanceString.length(), Constants::nRows + 1);
	std::cout << distance;
}

void Printer::rePrintLevel(const int level) {
	putConsoleCursorToXY(levelString.length(), Constants::nRows + 2);
	std::cout << level;
}

void Printer::printBlock(Block block) {
	for (int i = 0; i < Constants::blockSize; i++) {
		int blockLine = block.getPositionXBottom() - i;
		if (blockLine >= 0 && blockLine < Constants::nRows) {
			putConsoleCursorToXY(block.getPositionLeftY(), blockLine);
			for (int k = 0; k < Constants::blockSize; k++) {
				std::cout << Constants::blockSymbol;
			}
		}
		if (blockLine - Constants::blockSize >= 0 && blockLine - Constants::blockSize < Constants::nRows) {
			putConsoleCursorToXY(block.getPositionLeftY(), blockLine - Constants::blockSize);
			for (int k = 0; k < Constants::blockSize; k++) {
				std::cout << Constants::spaceSymbol;
			}
		}
	}
}

void Printer::printTraffic(Traffic traffic) {
	for (int i = 0; i < Constants::carSizeX; i++) {
		int trafficLine = traffic.getPositionBottomX() - i;
		if (trafficLine >= 0 && trafficLine < Constants::nRows) {
			putConsoleCursorToXY(traffic.getPositionLeftY(), trafficLine);
			for (int k = 0; k < Constants::carSizeY; k++) {
				std::cout << Constants::trafficSymbol;
			}
		}
		if (trafficLine - Constants::carSizeX >= 0 && trafficLine - Constants::carSizeX < Constants::nRows) {
			putConsoleCursorToXY(traffic.getPositionLeftY(), trafficLine - Constants::carSizeX);
			for (int k = 0; k < Constants::carSizeY; k++) {
				std::cout << Constants::spaceSymbol;
			}
		}
	}
}

void Printer::printGameOver() {
	std::cout << "GAME OVER" << std::endl;
=======
#include "stdafx.h"
#include "Printer.h"

#include <windows.h>
#include <iostream>
#include <string>

#include "Constants.h"
#include "Car.h"
#include "Block.h"

const std::string speedString = "Speed = ";
const std::string distanceString = "Distance = ";

Printer::Printer()
{
}

void Printer::printScreen(Car &car) {
	for (int i = 0; i < Constants::nRows; i++) {
		for (int k = 0; k < Constants::nColumns; k++) {

			if (k == 0 || k == Constants::nColumns - 1) {
				std::cout << Constants::boardSymbol;
			}
			else if (i >= Constants::nRows - car.sizeX && k >= car.getPositionLeftY() && k <= car.getPositionLeftY() - 1 + car.sizeY) {
				std::cout << Constants::carSymbol;
			}

			else std::cout << Constants::spaceSymbol;
		}
		std::cout << std::endl;
	}

	std::cout << speedString << Constants::speedMin << std::endl;
	std::cout << distanceString << "0" << std::endl;
}

void Printer::gotoXY(int x, int y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
	);
}

void Printer::rePrintCar(int oldCarPositionLeftY, Car &car)
{
	for (int i = 0; i < car.sizeX; i++) {
		for (int k = 0; k < car.sizeY; k++) {
			gotoXY(oldCarPositionLeftY + k, Constants::nRows - car.sizeX + i);
			std::cout << Constants::spaceSymbol;
		}

		for (int k = 0; k < car.sizeY; k++) {
			gotoXY(car.getPositionLeftY() + k, Constants::nRows - car.sizeX + i);
			std::cout << Constants::carSymbol;
		}
	}
}

void Printer::rePrintSpeed(int speed) {
	gotoXY(speedString.length(), Constants::nRows);
	std::cout << speed;
}

void Printer::rePrintDistance(int distance) {
	gotoXY(distanceString.length(), Constants::nRows + 1);
	std::cout << distance;
}

void Printer::printBlock(Block block) {
	for (int i = 0; i < block.size; i++) {
		int blockLine = block.getPositionXBottom() - i;
		if (blockLine >= 0 && blockLine < Constants::nRows) {
			gotoXY(block.getPositionLeftY(), blockLine);
			for (int k = 0; k < block.size; k++) {
				std::cout << Constants::blockSymbol;
			}
		}
		if (blockLine - block.size >= 0 && blockLine - block.size < Constants::nRows) {
			gotoXY(block.getPositionLeftY(), blockLine - block.size);
			for (int k = 0; k < block.size; k++) {
				std::cout << Constants::spaceSymbol;
			}
		}
	}
}

void Printer::printGameOver() {
	std::cout << "GAME OVER" << std::endl;
>>>>>>> Revert "levels & traffic & fixes & pause"
}