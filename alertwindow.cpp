#include "alertwindow.h"
#include "ui_alertwindow.h"

AlertWindow::AlertWindow(QWidget *parent) :
    QDialog(parent),
	ui(new Ui::AlertWindow)
{
	ui->setupUi(this);
}

AlertWindow::AlertWindow(QWidget *parent, QString text) :
	QDialog(parent),
	ui(new Ui::AlertWindow),
	alert_text(text)
{
	ui->setupUi(this);
	ui->label_alert_text->setText(alert_text);
	// The following line is ridiculously long...
	ui->label_alert_text->resize(ui->label_alert_text->fontMetrics().width(ui->label_alert_text->text()), ui->label_alert_text->height());
}

AlertWindow::~AlertWindow()
{
	delete ui;
}

void AlertWindow::on_pushButton_close_clicked()
{
	this->close();
}
