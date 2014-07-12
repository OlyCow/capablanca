#include "score.h"

Score::Score() :
	num(0)
{}

Score::Score(int init) :
	num(init)
{}

int Score::get()
{ return num; }

void Score::calculate() {}
void Score::update_internals() {}
void Score::clear() {}
