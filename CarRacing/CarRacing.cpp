#include "stdafx.h"
#include "CarRacing.h"

#include <iostream>
#include "GameThreads.h"


int main() 
{
	GameThreads game;
	game.startGameThread();
		
	system("pause");
	return 0;
}
