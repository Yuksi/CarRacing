#include "stdafx.h"
#include "Active.h"

#include <windows.h>

Active::Active() {}

void Active::print() {}

void Active::putConsoleCursorToXY(const int x, const int y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
	);
}

