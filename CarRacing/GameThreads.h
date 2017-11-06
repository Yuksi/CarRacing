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
	bool isGameOver(Block &block);
	void pause();
	void startGameThread();
	void displayTrafficThread();

private:
	void increaseLevel();
};

#endif GAME_THREADS_H