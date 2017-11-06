#include "stdafx.h"
#include "CarRacing.h"

#include <thread>
#include <iostream>
#include "GameThreads.h"


int main() 
{
		GameThreads game;
		
		std::thread moveOnTraffic(&GameThreads::displayTrafficThread,game);
		
		moveOnTraffic.detach();
		game.startGameThread();
		
	system("pause");
	return 0;
}
