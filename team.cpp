#include "team.h"

Team::Team() :
	team_number(0),
	team_name("")
{}

Team::Team(unsigned int number, QString name) :
	team_number(number),
	team_name(name)
{}

unsigned int Team::getTeamNumber()
{ return team_number; }

QString Team::getTeamName()
{ return team_name; }

void Team::setTeamNumber(unsigned int number)
{ team_number = number; }

void Team::setTeamName(QString name)
{ team_name = name; }
