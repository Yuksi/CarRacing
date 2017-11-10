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

void Screen::printMenu() {
	putConsoleCursorToXY(Constants::nColumns, Constants::nRows / 2);
	for (int i = 0; i <= Constants::menuSizeX; i++) {
		for (int k = 0; k <= Constants::menuSizeY; k++) {
			if (i == 0 || i == Constants::menuSizeX || k == 0) {
				std::cout << Constants::menuSymbol;
			}
			if (k == Constants::menuSizeY) {
				putConsoleCursorToXY(Constants::nColumns + k, Constants::nRows / 2 + i);
				std::cout << Constants::menuSymbol;
			}
		}
		putConsoleCursorToXY(Constants::nColumns, Constants::nRows / 2 + i);
	}
}

void Screen::printStartInfo() {
	printMenu();
	putConsoleCursorToXY(Constants::nColumns + 2, Constants::nRows / 2 + 2);
	std::cout << "Print name and press enter to start: ";
}

void Screen::printGameOverInfo(int speed,int distance, int level, double timeGame) {
	printMenu();
	int i = 1;
	putConsoleCursorToXY(Constants::nColumns + 2, Constants::nRows / 2 + ++i);
	std::cout << "GAME OVER";
	++i;
	putConsoleCursorToXY(Constants::nColumns + 2, Constants::nRows / 2 + ++i);
	std::cout << speedString << speed;
	putConsoleCursorToXY(Constants::nColumns + 2, Constants::nRows / 2 + ++i);
	std::cout << distanceString << distance;
	putConsoleCursorToXY(Constants::nColumns + 2, Constants::nRows / 2 + ++i);
	std::cout << levelString << level;
	putConsoleCursorToXY(Constants::nColumns + 2, Constants::nRows / 2 + ++i);
	std::cout << "Time of game = " << timeGame << " sec";
	++i;
	putConsoleCursorToXY(Constants::nColumns + 2, Constants::nRows / 2 + ++i);
	std::cout << "Press Enter to restart game and Esc to quit";
}
