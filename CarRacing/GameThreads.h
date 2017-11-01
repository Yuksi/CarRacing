<<<<<<< HEAD
#ifndef GAME_THREADS_H
#define GAME_THREADS_H

#include "Car.h"
#include "Printer.h"
#include "Generator.h"
#include "Constants.h"

class GameThreads
{
public:
	GameThreads();
	void blockDisplayThread();
	void startGameThread();
	bool isGameOver;
	void displayTrafficThread();

private:
	void increaseLevel();

	
};

=======
#ifndef GAME_THREADS_H
#define GAME_THREADS_H

class GameThreads
{
public:
	GameThreads();
	void blockDisplayThread();
	void startGameThread();
};

>>>>>>> Revert "levels & traffic & fixes & pause"
#endif GAME_THREADS_H