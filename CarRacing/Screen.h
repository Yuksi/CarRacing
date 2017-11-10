#ifndef SCREEN_H
#define SCREEN_H

class Screen
{
public:
	Screen();
	void printScreen();
	void rePrintSpeed(const int speed);
	void rePrintDistance(const int distance);
	void rePrintLevel(const int level);
	void printStartInfo();
	void printGameOverInfo(int speed, int distance, int level, double timeGame);
private:
	void Screen::putConsoleCursorToXY(const int x, const int y);
	void printMenu();
};

#endif SCREEN_H