#include "stdafx.h"
#include "GameThreads.h"

#include <windows.h>
#include <thread>
#include <iostream>
#include <time.h>

#include "Traffic.h"
#include "Block.h"
#include "Printer.h"

using namespace CarRacingNamespace;

GameThreads::GameThreads() {
}

void GameThreads::increaseLevel() {
	if (distance_ % Constants::distanceToLevelUp == 0) {
		level_++;
		speed_++;
		screen_.rePrintSpeed(speed_);
		screen_.rePrintLevel(level_);
	}
}

bool GameThreads::isCrachedByEnemy(Enemy &block, Enemy &traffic) {
	Enemy enemies[2] = { block, traffic };
	bool isCrached = false;
	for (int i = 0; i < 2; i++) {
		if ((enemies[i].getPositionLeftY() >= car_.getPositionLeftY() + car_.getSizeY() 
			|| enemies[i].getPositionLeftY() + enemies[i].getSizeY() <= car_.getPositionLeftY())
			|| enemies[i].getPositionBottomX() <= car_.getPositionBottomX() - car_.getSizeX()) {
			isCrached = false;
		}
		else {
			isCrached = true;
			break;
		}
	}
	return isCrached;
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
		if (car_.getPositionLeftY() >= car_.getSizeY() + 1) {
			int oldCarPositionY = car_.getPositionLeftY();
			car_.moveLeft();
		}
	}
	if (GetAsyncKeyState(VK_RIGHT)) {
		if (car_.getPositionLeftY() < Constants::nColumns - car_.getSizeY() - 1) {
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

void GameThreads::autoMovements(Enemy &block, Enemy &traffic, int timeWaitIndex) {
	Sleep(Constants::maximumTimePause / speed_);
	if (!traffic.isNoMatterOfPosition() && !traffic.isRightPosition()) {
		traffic.moveDown();
	}
	else if (!traffic.isNoMatterOfPosition() && timeWaitIndex % (Constants::waitIndex * Constants::waitIndex) == 0) {
		traffic.moveDown();
	}
	if (block.isNoMatterOfPosition() && timeWaitIndex % Constants::waitIndex == 0) {
		block.moveDown();
		distance_++;
		screen_.rePrintDistance(distance_);
	}
}

void GameThreads::chooseContinueOrQuit() {
	while (!GetAsyncKeyState(VK_ESCAPE)) {
		if (GetAsyncKeyState(VK_RETURN)) {
			level_ = 0;
			speed_ = 1;
			distance_ = 1;
			startGameThread();
		}
		if (GetAsyncKeyState(VK_ESCAPE)) {
			exit(0);
		}
	}
}

void GameThreads::startGameThread() {
	time_t start, finish;
	double timeGame;
	Enemy* block = generator_.generateEnemy(BLOCK);
	Enemy* traffic = generator_.generateEnemy(TRAFFIC);

	Printer printers[3] = { Printer(&car_), Printer(block), Printer(traffic) };

	int timeWaitIndex = 1;

	screen_.printStartInfo();
	getchar();
	system("cls");
	screen_.printScreen();
	time(&start);

	while (!isCrachedByEnemy(*block, *traffic)) {

		if (block->getPositionBottomX() == Constants::nRows + block->getSizeX()) {
			delete block;
			block = generator_.generateEnemy(BLOCK);
		}
		if (traffic->getPositionBottomX() == Constants::nRows + car_.getSizeX()) {
			delete traffic;
			traffic = generator_.generateEnemy(TRAFFIC);
		}
		
		for (int i = 0; i < 3; i++) {
			printers[i].print();
		}

		autoMovements(*block, *traffic, timeWaitIndex);
		if (distance_ > 0) {
			increaseLevel();
		}
		
		if (isPaused_) {
			pause();
		}
		
		control();
		timeWaitIndex++;
	}
	time(&finish);
	timeGame = difftime(finish, start);
	screen_.printGameOverInfo(speed_, distance_, level_, timeGame);
	
	chooseContinueOrQuit();
}