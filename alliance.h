#ifndef ALLIANCE_H
#define ALLIANCE_H

#include "team.h"

class Alliance
{
public:
	Alliance();
	Alliance(Team* team_A, Team* team_B);
	~Alliance();

	Team* team1;
	Team* team2;
};

#endif // ALLIANCE_H
