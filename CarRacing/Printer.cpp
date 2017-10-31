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
}