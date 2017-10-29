// CarRacing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <random>
#include <thread>
#include <windows.h>
#include "Car.h"
#include "Block.h"
#include "CarRacing.h"

static const int nRows = 20;
static const int nColumns = 17;

static const char boardSymbol = 222;
static const char blockSymbol = 'X';
static const char carSymbol = 178;

static const int speedMax = 5;
static const int speedMin = 1;

static int speed = speedMin;
static int distance = 0;
static Car car;
static bool isPaused = false;

static void printScreen() {
	for (int i = 0; i < nRows; i++) {
		for (int k = 0; k < nColumns; k++) {

			if (k == 0 || k == nColumns - 1) {
				std::cout << boardSymbol;
			}
			else if (i >= nRows - car.sizeX && k >= car.getPositionY() - 1 && k <= car.getPositionY() + 1) {
				std::cout << carSymbol;
			}

			else std::cout << ' ';
		}
		std::cout << std::endl;
	}
	std::cout << "Speed = " << speed;
	std::cout << " Distance = " << distance;
}

static void gotoXY(int x, int y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
	);
}

static void rePrintCar(int oldCarPositionY)
{
	for (int i = 0; i < car.sizeX; i++) {
		gotoXY(oldCarPositionY - 1, nRows - car.sizeX + i);
		std::cout << "   ";
		
		for (int k = 0; k < 3; k++) {
			gotoXY(car.getPositionY() - 1 + k, nRows - car.sizeX + i);
			std::cout << carSymbol;
		}
	}
}

static void rePrintSpeed() {
	gotoXY(8, 20);
	std::cout << speed;
}

static void rePrintDistance() {
	gotoXY(20, 20);
	std::cout << distance;
}

static Block generateBlock() {
	int blockMiddleBottomPoint = 2 + rand() % (nColumns - 4);
	Block block = Block(0, blockMiddleBottomPoint);
	return block;
}

static void printBlock(Block block) {
	for (int i = 0; i < block.size; i++) {
		int blockLine = block.getPositionXBottom() - i;
		if (blockLine >= 0 && blockLine < nRows) {
			gotoXY(block.getPositionY() - 1, blockLine);
			for (int k = 0; k < block.size; k++) {
				std::cout << blockSymbol;
			}
		}
		if (blockLine - block.size >= 0 && blockLine - block.size < nRows) {
			gotoXY(block.getPositionY() - 1, blockLine - block.size);
			std::cout << "   ";
		}
	}
}

static void blockDisplayThread() {
	Block block = generateBlock();
	while ((block.getPositionY() - 1 > car.getPositionY() + 1 || block.getPositionY() + 1 < car.getPositionY() - 1)
		|| block.getPositionXBottom() < nRows - car.sizeX) {
	
		if (block.getPositionXBottom() == nRows + block.size) {
			block = generateBlock();
		}
		printBlock(block);
		std::this_thread::sleep_for(std::chrono::milliseconds(100 - 20*speed));
		block.moveDownOnScreen();
		distance++;
		rePrintDistance();
	}
	
	std::cout << "GAME OVER" << std::endl;
}

static void startGameThread() {
	HANDLE s_in = GetStdHandle(STD_INPUT_HANDLE);
	DWORD dr;
	INPUT_RECORD  rec;
	while (true) {
		ReadConsoleInput(s_in, &rec, sizeof(INPUT_RECORD), &dr);
		FlushConsoleInputBuffer(s_in);
		if (rec.EventType == KEY_EVENT) {
			if (rec.Event.KeyEvent.bKeyDown) {
				switch (rec.Event.KeyEvent.wVirtualKeyCode) {
				case VK_LEFT:
					if (car.getPositionY() - 1 >= car.sizeY + 1) {
						int oldCarPositionY = car.getPositionY();
						car.moveLeft();
						rePrintCar(oldCarPositionY);
					}
					break;
				case VK_RIGHT:
					if (car.getPositionY() < nColumns - car.sizeY) {
						int oldCarPositionY = car.getPositionY();
						car.moveRight();
						rePrintCar(oldCarPositionY);
					}
					break;
				case VK_UP:
					if (speed < speedMax) {
						speed++;
						rePrintSpeed();
					}
					break;
				case VK_DOWN:
					if (speed > speedMin) {
						speed--;
						rePrintSpeed();
					}
					break;
				case VK_RETURN:
					if (isPaused == false) {
						isPaused = true;
					}
					else {
						isPaused = false;
					}
					break;
				case VK_ESCAPE:
					exit(0);
					break;
				}
			}
		}
	}
}

int main() 
{
	printScreen();

	std::thread start(startGameThread);
	std::thread moveBlock(blockDisplayThread);

	system("pause");
	return 0;
}
