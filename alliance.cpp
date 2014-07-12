#include "alliance.h"

Alliance::Alliance() :
	team1(new Team()),
	team2(new Team())
{}

Alliance::Alliance(Team* team_A, Team* team_B) :
	team1(team_A),
	team2(team_B)
{}

Alliance::~Alliance()
{
	delete team1;
	delete team2;
}
