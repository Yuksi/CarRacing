#include "stdafx.h"
#include "GameThreads.h"

#include <windows.h>
#include <thread>
#include <iostream>

#include "Car.h"
#include "Block.h"
#include "Constants.h"
#include "Generator.h"
#include "Printer.h"
#include "Screen.h"

using namespace CarRacingNamespace;

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

bool GameThreads::isCrachedByBlock(Block &block) {
	if ((block.getPositionLeftY() >= car_.getPositionLeftY() + Constants::carSizeY || block.getPositionLeftY() + Constants::blockSize <= car_.getPositionLeftY())
		|| block.getPositionBottomX() < Constants::nRows - Constants::carSizeX) {
		return false;
	}
	return true;
}

bool GameThreads::isCrachedByTraffic(Traffic &traffic) {
	if ((traffic.getPositionLeftY() >= car_.getPositionLeftY() + Constants::carSizeY || traffic.getPositionLeftY() + Constants::carSizeY <= car_.getPositionLeftY())
		|| traffic.getPositionBottomX() <= car_.getPositionBottomX() - Constants::carSizeX) {
		return false;
	}
	return true;
}

void GameThreads::pause() {
	isPaused_ = true;
	while (isPaused_) {
		if (GetAsyncKeyState(VK_RETURN)) {
			isPaused_ = false;
		}
	}
}

void GameThreads::control() {
	if (GetAsyncKeyState(VK_LEFT)) {
		if (car_.getPositionLeftY() >= Constants::carSizeY + 1) {
			int oldCarPositionY = car_.getPositionLeftY();
			car_.moveLeft();
		}
	}
	if (GetAsyncKeyState(VK_RIGHT)) {
		if (car_.getPositionLeftY() < Constants::nColumns - Constants::carSizeY - 1) {
			int oldCarPositionLeftY = car_.getPositionLeftY();
			car_.moveRight();
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

void GameThreads::startGameThread() {
	
	Printer printerCar(&car_);

	Block block = generator_.generateBlock();
	Printer printerBlock(&block);

	Traffic traffic = generator_.generateTraffic();
	Printer printerTraffic(&traffic);

	int timeWaitIndex = 1;
	
	while (!isCrachedByBlock(block) && !isCrachedByTraffic(traffic)) {

		if (block.getPositionBottomX() == Constants::nRows + Constants::blockSize) {
			block = generator_.generateBlock();
		}
		if (traffic.getPositionBottomX() == Constants::nRows + Constants::carSizeX) {
			traffic = generator_.generateTraffic();
		}
		printerBlock.print();
		printerTraffic.print();
		printerCar.print();

		Sleep(Constants::maximumTimePause / (2 * speed_));
		traffic.moveDown();
		
		if (timeWaitIndex % 2 == 0) {
			Sleep(Constants::maximumTimePause / speed_);
			block.moveDownOnScreen();
		}
	
		distance_++;
		screen_.rePrintDistance(distance_);
		increaseLevel();
		
		if (isPaused_) {
			pause();
		}
		
		control();
		printerCar.print();
		timeWaitIndex++;
	}
	screen_.printGameOver();
}