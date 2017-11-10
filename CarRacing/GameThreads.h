#ifndef GAME_THREADS_H
#define GAME_THREADS_H

#include "Constants.h"
#include "Car.h"
#include "Enemy.h"
#include "Generator.h"
#include "Screen.h"

class GameThreads
{
public:
	GameThreads();
	void startGameThread();

private:
	void increaseLevel();
	bool isCrachedByEnemy(Enemy &block, Enemy &traffic);
	void pause();
	void control();
	void autoMovements(Enemy &block, Enemy &traffic, int timeWaitIndex);
	void chooseContinueOrQuit();

	bool isPaused_ = false;
	int speed_ = CarRacingNamespace::Constants::speedMin;
	int distance_ = 0;
	int level_ = 0;
	Car car_;
	Generator generator_;
	Screen screen_;
};

#endif GAME_THREADS_H