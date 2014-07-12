#ifndef SCORE_H
#define SCORE_H

#include <QObject>

class Score : public QObject
{
	Q_OBJECT

public:
	Score();
	Score(int init);

	int get();
	virtual void calculate();
	virtual void update_internals();
	virtual void clear();

signals:
	void update_ui();

protected:
	int num;
};

#endif // SCORE_H
