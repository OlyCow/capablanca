#include "match.h"

Match::Match() :
	red(new Alliance()),
	blue(new Alliance()),
	match_time(0),
	gamePeriod(PERIOD_AUTON)
{}

Match::Match(Alliance* alliance_A, Alliance* alliance_B) :
	red(alliance_A),
	blue(alliance_B),
	match_time(0),
	gamePeriod(PERIOD_AUTON)
{}

int Match::get_match_time()
{ return match_time; }

GamePeriod Match::get_gamePeriod()
{ return gamePeriod; }

Match::~Match()
{
	delete red;
	delete blue;
}
