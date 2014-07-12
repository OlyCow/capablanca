#include "ringitup.h"
#include "ui_ringitup.h"

RingItUp::RingItUp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RingItUp)
{
	ui->setupUi(this);
}

RingItUp::~RingItUp()
{
	delete ui;
}
