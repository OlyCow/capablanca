#ifndef MATCH_H
#define MATCH_H

#include <QString>
#include "alliance.h"

enum GamePeriod {
	PERIOD_AUTON = 0,
	PERIOD_TELEOP,
	PERIOD_END,
	PERIOD_NUM
};

class Match
{
public:
	Match();
	Match(Alliance* alliance_A, Alliance* alliance_B);
	~Match();

	int get_match_time();
	GamePeriod get_gamePeriod();

	Alliance* red;
	Alliance* blue;

private :
	int match_time; // from beginning, in sec
	GamePeriod gamePeriod;
};

#endif // MATCH_H
