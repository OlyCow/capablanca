#ifndef RINGITUP_H
#define RINGITUP_H

#include <QMainWindow>

namespace Ui {
class RingItUp;
}

class RingItUp : public QMainWindow
{
	Q_OBJECT

public:
	explicit RingItUp(QWidget *parent = 0);
	~RingItUp();

private:
	Ui::RingItUp *ui;
};

#endif // RINGITUP_H
