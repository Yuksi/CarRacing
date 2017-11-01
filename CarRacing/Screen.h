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
	void printGameOver();
private:
	void Screen::putConsoleCursorToXY(const int x, const int y);
};

#endif SCREEN_H