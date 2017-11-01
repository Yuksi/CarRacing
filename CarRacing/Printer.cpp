#include "stdafx.h"
#include "Printer.h"

Printer::Printer(Active *comp)
	: active(comp) {}

void Printer::print() {
	active->print();
}
