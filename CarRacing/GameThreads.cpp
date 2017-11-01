<<<<<<< HEAD
#include "stdafx.h"
#include "GameThreads.h"

#include <windows.h>
#include <thread>

#include "Car.h"
#include "Block.h"
#include "Constants.h"
#include "Generator.h"
#include "Printer.h"

int speed = Constants::speedMin;
int distance = 0;
bool isPaused = false;
bool isGameOver = false;

Car car;

Generator generator;
Printer printer;

GameThreads::GameThreads() {
	printer.printScreen(car);
}

void GameThreads::blockDisplayThread() {
	Block block = generator.generateBlock();
	while ((block.getPositionLeftY() >= car.getPositionLeftY() + car.sizeY || block.getPositionLeftY() + Block::size <= car.getPositionLeftY())
		|| block.getPositionXBottom() < Constants::nRows - car.sizeX) {

		if (block.getPositionXBottom() == Constants::nRows + block.size) {
			block = generator.generateBlock();
		}
		printer.printBlock(block);
		std::this_thread::sleep_for(std::chrono::milliseconds(120 - 20 * speed));
		block.moveDownOnScreen();
		distance++;
		printer.rePrintDistance(distance);
		if (isPaused) {
			system("pause");
		}
	}

	printer.printGameOver();
	isGameOver = true;
}

void GameThreads::startGameThread() {
	printer.printScreen(car);

	HANDLE stdInputHandle = GetStdHandle(STD_INPUT_HANDLE);
	DWORD dr;
	INPUT_RECORD  inputRecord;
	while (!isGameOver) {
		ReadConsoleInput(stdInputHandle, &inputRecord, sizeof(INPUT_RECORD), &dr);
		FlushConsoleInputBuffer(stdInputHandle);
		if (inputRecord.EventType == KEY_EVENT) {
			if (inputRecord.Event.KeyEvent.bKeyDown) {
				switch (inputRecord.Event.KeyEvent.wVirtualKeyCode) {
				case VK_LEFT:
					if (car.getPositionLeftY() >= car.sizeY + 1) {
						int oldCarPositionY = car.getPositionLeftY();
						car.moveLeft();
						printer.rePrintCar(oldCarPositionY, car);
					}
					break;
				case VK_RIGHT:
					if (car.getPositionLeftY() < Constants::nColumns - car.sizeY - 1) {
						int oldCarPositionLeftY = car.getPositionLeftY();
						car.moveRight();
						printer.rePrintCar(oldCarPositionLeftY, car);
					}
					break;
				case VK_UP:
					if (speed < Constants::speedMax) {
						speed++;
						printer.rePrintSpeed(speed);
					}
					break;
				case VK_DOWN:
					if (speed > Constants::speedMin) {
						speed--;
						printer.rePrintSpeed(speed);
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

/*
void GameThreads::startGameThread() {
	char x;
	while (!isGameOver) {
		x = _getch();
		switch (_getch())
		{
		case 72: //up
			if (speed < Constants::speedMax) {
				speed++;
				printer.rePrintSpeed(speed);
			}
			break;
		case 80: //down
			if (speed > Constants::speedMin) {
				speed--;
				printer.rePrintSpeed(speed);
			}
			break;
		case 75: //left
			if (car.getPositionLeftY() >= car.sizeY + 1) {
				int oldCarPositionY = car.getPositionLeftY();
				car.moveLeft();
				printer.rePrintCar(oldCarPositionY, car);
			}
			break;
		case 77: //right
			if (car.getPositionLeftY() < Constants::nColumns - car.sizeY) {
				int oldCarPositionLeftY = car.getPositionLeftY();
				car.moveRight();
				printer.rePrintCar(oldCarPositionLeftY, car);
			}
			break;
		}
	}
}
*/