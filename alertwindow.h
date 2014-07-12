#ifndef ALERTWINDOW_H
#define ALERTWINDOW_H

#include <QDialog>
#include <QString>

namespace Ui {
class AlertWindow;
}

class AlertWindow : public QDialog
{
	Q_OBJECT

public:
	AlertWindow(QWidget *parent, QString t);
	~AlertWindow();

private slots:
	void on_pushButton_close_clicked();

private:
	Ui::AlertWindow *ui;
	QString alert_text;

	explicit AlertWindow(QWidget *parent = 0);
};

#endif // ALERTWINDOW_H
