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

using namespace CarRacingNamespace;

int speed_ = CarRacingNamespace::Constants::speedMin;
int distance_ = 0;
bool isPaused_ = false;

int level_ = 0;

Car car_;

Generator generator_;
Printer printer_;

GameThreads::GameThreads() {
	printer_.printScreen(car_);
}

void GameThreads::increaseLevel() {
	if (distance_ % Constants::distanceToLevelUp == 0) {
		level_++;
		speed_++;
		printer_.rePrintSpeed(speed_);
		printer_.rePrintLevel(level_);
	}
}

void GameThreads::blockDisplayThread() {
	Block block = generator_.generateBlock();
	while ((block.getPositionLeftY() >= car_.getPositionLeftY() + Constants::carSizeY || block.getPositionLeftY() + Constants::blockSize <= car_.getPositionLeftY())
		|| block.getPositionXBottom() < Constants::nRows - Constants::carSizeX) {

		if (block.getPositionXBottom() == Constants::nRows + Constants::blockSize) {
			block = generator_.generateBlock();
		}
		printer_.printBlock(block);
		std::this_thread::sleep_for(std::chrono::milliseconds(Constants::maximumTimePause / speed_));
		block.moveDownOnScreen();
		distance_++;
		printer_.rePrintDistance(distance_);
		increaseLevel();
		if (isPaused_) {
			int k = 1;
			while (k != 2) {
				if (GetAsyncKeyState(VK_RETURN))
					k = 2;
			}
		}
	}

	printer_.printGameOver();
	isGameOver = true;
}

void GameThreads::displayTrafficThread() {
	Traffic traffic = generator_.generateTraffic();
	while ((traffic.getPositionLeftY() >= car_.getPositionLeftY() + Constants::carSizeY || traffic.getPositionLeftY() + Constants::carSizeY <= car_.getPositionLeftY())
		|| traffic.getPositionBottomX() <= car_.getPositionBottomX() - Constants::carSizeX) {

		if (traffic.getPositionBottomX() == Constants::nRows + Constants::carSizeX) {
			traffic = generator_.generateTraffic(); 
		}
		printer_.printTraffic(traffic);
		if (traffic.getSpeed() < 0) {
			std::this_thread::sleep_for(std::chrono::milliseconds((Constants::maximumTimePause * 2) / speed_));
		}
		else std::this_thread::sleep_for(std::chrono::milliseconds(Constants::maximumTimePause / 2 * speed_));
		traffic.moveDown();
		if (isPaused_) {
			int k = 1;
			while (k != 2) {
				if (GetAsyncKeyState(VK_RETURN))
					k = 2;
			}
		}
	}

	printer_.printGameOver();
	isGameOver = true;
}

void GameThreads::startGameThread() {
	printer_.printScreen(car_);

	HANDLE stdInputHandle = GetStdHandle(STD_INPUT_HANDLE);
	DWORD dr;
	INPUT_RECORD  inputRecord;
	
	while (true) {
		ReadConsoleInput(stdInputHandle, &inputRecord, sizeof(INPUT_RECORD), &dr);
		FlushConsoleInputBuffer(stdInputHandle);
		
		if (inputRecord.EventType == KEY_EVENT) {
			if (inputRecord.Event.KeyEvent.bKeyDown) {
				switch (inputRecord.Event.KeyEvent.wVirtualKeyCode) {
				case VK_LEFT:
					if (car_.getPositionLeftY() >= Constants::carSizeY + 1) {
						int oldCarPositionY = car_.getPositionLeftY();
						car_.moveLeft();
						printer_.rePrintCar(oldCarPositionY, car_);
					}
					break;
				case VK_RIGHT:
					if (car_.getPositionLeftY() < Constants::nColumns - Constants::carSizeY - 1) {
						int oldCarPositionLeftY = car_.getPositionLeftY();
						car_.moveRight();
						printer_.rePrintCar(oldCarPositionLeftY, car_);
					}
					break;
				case VK_UP:
					if (speed_ < Constants::speedMax + level_) {
						speed_++;
						printer_.rePrintSpeed(speed_);
					}
					break;
				case VK_DOWN:
					if (speed_ > Constants::speedMin + level_) {
						speed_--;
						printer_.rePrintSpeed(speed_);
					}
					break;
				case VK_RETURN:
					if (!isPaused_ ) {
						isPaused_ = true;
					}
					else isPaused_ = false;
					break;
				case VK_ESCAPE:
					exit(0);
					break;
				default:
					break;
				}
			}
		}
	}
}
=======
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
>>>>>>> Revert "levels & traffic & fixes & pause"
