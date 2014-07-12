#ifndef TEAM_H
#define TEAM_H

#include <QString>

class Team
{
public:
	Team();
	Team(unsigned int number, QString name);

	unsigned int getTeamNumber();
	QString getTeamName();
	void setTeamNumber(unsigned int number);
	void setTeamName(QString name);

private:
	unsigned int team_number;
	QString team_name;
};

#endif // TEAM_H
