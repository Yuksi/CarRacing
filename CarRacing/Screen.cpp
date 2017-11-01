#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include "Screen.h"
#include "Constants.h"
using namespace CarRacingNamespace;

Screen::Screen()
{
}

void Screen::printScreen() {
	for (int i = 0; i < Constants::nRows; i++) {
		for (int k = 0; k < Constants::nColumns; k++) {

			if (k == 0 || k == Constants::nColumns - 1) {
				std::cout << Constants::boardSymbol;
			}

			else std::cout << Constants::spaceSymbol;
		}
		std::cout << std::endl;
	}

	std::cout << speedString << Constants::speedMin << std::endl;
	std::cout << distanceString << "0" << std::endl;
	std::cout << levelString << "0" << std::endl;
}

void Screen::putConsoleCursorToXY(const int x, const int y) {
	COORD coord = { x, y };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
	);
}

void Screen::rePrintSpeed(const int speed) {
	putConsoleCursorToXY(speedString.length(), Constants::nRows);
	std::cout << speed;
}

void Screen::rePrintDistance(const int distance) {
	putConsoleCursorToXY(distanceString.length(), Constants::nRows + 1);
	std::cout << distance;
}

void Screen::rePrintLevel(const int level) {
	putConsoleCursorToXY(levelString.length(), Constants::nRows + 2);
	std::cout << level;
}

void Screen::printGameOver() {
	std::cout << "GAME OVER" << std::endl;
}
