#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

namespace CarRacingNamespace {
	const std::string speedString = "Speed = ";
	const std::string distanceString = "Distance = ";
	const std::string levelString = "Level = ";

	class Constants { 
	public:
		static const int speedMax = 5;
		static const int speedMin = 1;

		static const int nRows = 20;
		static const int nColumns = 20;

		static const char boardSymbol = 222;
		static const char blockSymbol = 'X';
		static const char carSymbol = 178;
		static const char spaceSymbol = ' ';
		static const char trafficSymbol = '0';

		static const int blockSize = 3;

		static const int carSizeX = 4;
		static const int carSizeY = 3;

		static const int distanceToLevelUp = 100;
		static const int maximumTimePause = 100;
	};
}

#endif CONSTANTS_H