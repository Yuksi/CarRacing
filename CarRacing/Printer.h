#ifndef PRINTER_H
#define PRINTER_H

#include "Active.h"

class Printer
{
public:
	Printer(Active *comp);
	void print();

private:
	Active *active;
};

#endif PRINTER_H
