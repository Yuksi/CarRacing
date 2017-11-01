#include "stdafx.h"
#include "GameThreads.h"

#include <windows.h>
#include <thread>

#include "Car.h"
#include "Block.h"
#include "Constants.h"
#include "Generator.h"
#include "Printer.h"
#include "Screen.h"

using namespace CarRacingNamespace;

int speed_ = CarRacingNamespace::Constants::speedMin;
int distance_ = 0;
bool isPaused_ = false;

int level_ = 0;

Car car_;

Generator generator_;
Screen screen_;

GameThreads::GameThreads() {
	screen_.printScreen();
}

void GameThreads::increaseLevel() {
	if (distance_ % Constants::distanceToLevelUp == 0) {
		level_++;
		speed_++;
		screen_.rePrintSpeed(speed_);
		screen_.rePrintLevel(level_);
	}
}

void GameThreads::blockDisplayThread() {
	Block block = generator_.generateBlock();
	while ((block.getPositionLeftY() >= car_.getPositionLeftY() + Constants::carSizeY || block.getPositionLeftY() + Constants::blockSize <= car_.getPositionLeftY())
		|| block.getPositionBottomX() < Constants::nRows - Constants::carSizeX) {

		if (block.getPositionBottomX() == Constants::nRows + Constants::blockSize) {
			block = generator_.generateBlock();
		}
		Printer printer(&block);
		printer.print();
		std::this_thread::sleep_for(std::chrono::milliseconds(Constants::maximumTimePause / speed_));
		block.moveDownOnScreen();
		distance_++;
		screen_.rePrintDistance(distance_);
		increaseLevel();
		if (isPaused_) {
			int k = 1;
			while (k != 2) {
				if (GetAsyncKeyState(VK_RETURN))
					k = 2;
			}
		}
	}

	screen_.printGameOver();
	isGameOver = true;
}

void GameThreads::displayTrafficThread() {
	Traffic traffic = generator_.generateTraffic();
	while ((traffic.getPositionLeftY() >= car_.getPositionLeftY() + Constants::carSizeY || traffic.getPositionLeftY() + Constants::carSizeY <= car_.getPositionLeftY())
		|| traffic.getPositionBottomX() <= car_.getPositionBottomX() - Constants::carSizeX) {

		if (traffic.getPositionBottomX() == Constants::nRows + Constants::carSizeX) {
			traffic = generator_.generateTraffic(); 
		}
		Printer printer(&traffic);
		printer.print();
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

	screen_.printGameOver();
	isGameOver = true;
}

void GameThreads::startGameThread() {
	HANDLE stdInputHandle = GetStdHandle(STD_INPUT_HANDLE);
	DWORD dr;
	INPUT_RECORD  inputRecord;

	Printer printer(&car_);
	
	while (true) {
		ReadConsoleInput(stdInputHandle, &inputRecord, sizeof(INPUT_RECORD), &dr);
		FlushConsoleInputBuffer(stdInputHandle);
		printer.print();
		
		if (inputRecord.EventType == KEY_EVENT) {
			if (inputRecord.Event.KeyEvent.bKeyDown) {
				switch (inputRecord.Event.KeyEvent.wVirtualKeyCode) {
				case VK_LEFT:
					if (car_.getPositionLeftY() >= Constants::carSizeY + 1) {
						int oldCarPositionY = car_.getPositionLeftY();
						car_.moveLeft();
						printer.print();
					}
					break;
				case VK_RIGHT:
					if (car_.getPositionLeftY() < Constants::nColumns - Constants::carSizeY - 1) {
						int oldCarPositionLeftY = car_.getPositionLeftY();
						car_.moveRight();
						printer.print();
					}
					break;
				case VK_UP:
					if (speed_ < Constants::speedMax + level_) {
						speed_++;
						screen_.rePrintSpeed(speed_);
					}
					break;
				case VK_DOWN:
					if (speed_ > Constants::speedMin + level_) {
						speed_--;
						screen_.rePrintSpeed(speed_);
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
