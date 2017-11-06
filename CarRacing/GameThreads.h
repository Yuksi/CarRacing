#ifndef GAME_THREADS_H
#define GAME_THREADS_H

#include "Car.h"
#include "Printer.h"
#include "Generator.h"
#include "Constants.h"
#include "Screen.h"

class GameThreads
{
public:
	GameThreads();
	bool isCrachedByBlock(Block &block);
	bool isCrachedByTraffic(Traffic &traffic);
	void pause();
	void startGameThread();

private:
	void increaseLevel();
	void control();

	bool isPaused_ = false;
	int speed_ = CarRacingNamespace::Constants::speedMin;
	int distance_ = 0;
	int level_ = 0;
	Car car_;
	Generator generator_;
	Screen screen_;
};

#endif GAME_THREADS_H