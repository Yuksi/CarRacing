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

bool isPaused_ = false;

int speed_ = CarRacingNamespace::Constants::speedMin;
int distance_ = 0;

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

bool GameThreads::isGameOver(Block &block) {
	if ((block.getPositionLeftY() >= car_.getPositionLeftY() + Constants::carSizeY || block.getPositionLeftY() + Constants::blockSize <= car_.getPositionLeftY())
		|| block.getPositionBottomX() < Constants::nRows - Constants::carSizeX) {
		return false;
	}
	return true;
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
			pause();
		}
	}

	screen_.printGameOver();
	//isGameOver = true;
}

void GameThreads::pause() {
	isPaused_ = true;
	while (isPaused_) {
		if (GetAsyncKeyState(VK_RETURN)) {
			isPaused_ = false;
		}
	}
}

void GameThreads::startGameThread() {
	
	Printer printerCar(&car_);

	Block block = generator_.generateBlock();
	
	while (!isGameOver(block)) {

		if (block.getPositionBottomX() == Constants::nRows + Constants::blockSize) {
			block = generator_.generateBlock();
		}
		Printer printer(&block);
		printer.print();
		Sleep(Constants::maximumTimePause / speed_);
		block.moveDownOnScreen();
		distance_++;
		screen_.rePrintDistance(distance_);
		increaseLevel();

		printerCar.print();
		
		if (GetAsyncKeyState(VK_LEFT)) {
			if (car_.getPositionLeftY() >= Constants::carSizeY + 1) {
				int oldCarPositionY = car_.getPositionLeftY();
				car_.moveLeft();
				printer.print();
			}
		}
		if (GetAsyncKeyState(VK_RIGHT)) {
			if (car_.getPositionLeftY() < Constants::nColumns - Constants::carSizeY - 1) {
				int oldCarPositionLeftY = car_.getPositionLeftY();
				car_.moveRight();
				printer.print();
			}
		}
		if (GetAsyncKeyState(VK_UP)) {
			if (speed_ < Constants::speedMax + level_) {
				speed_++;
				screen_.rePrintSpeed(speed_);
			}
		}
		if (GetAsyncKeyState(VK_DOWN)) {
			if (speed_ > Constants::speedMin + level_) {
				speed_--;
				screen_.rePrintSpeed(speed_);
			}
		}
		if (GetAsyncKeyState(VK_RETURN)) {
			pause();
		}
		if (GetAsyncKeyState(VK_ESCAPE)) {
			exit(0);
		}
	}
	screen_.printGameOver();
	//isGameOver = true;
}
