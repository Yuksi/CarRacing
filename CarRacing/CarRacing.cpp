#include "stdafx.h"
#include "CarRacing.h"

#include <thread>
#include <iostream>
#include "GameThreads.h"


int main() 
{
		GameThreads game;
		std::thread start(&GameThreads::startGameThread, game);
		std::thread moveBlock(&GameThreads::blockDisplayThread, game);
		std::thread moveOnTraffic(&GameThreads::displayTrafficThread,game);
		moveBlock.detach();
		start.detach();
		moveOnTraffic.detach();
		
	system("pause");
	return 0;
}
