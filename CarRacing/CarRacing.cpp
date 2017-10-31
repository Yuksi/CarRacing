#include "stdafx.h"
#include "CarRacing.h"

#include <thread>

#include "GameThreads.h"


int main() 
{
	GameThreads game;

	std::thread start(&GameThreads::startGameThread, game);
	std::thread moveBlock(&GameThreads::blockDisplayThread, game);
	moveBlock.detach();
	start.detach();

	system("pause");
	return 0;
}
