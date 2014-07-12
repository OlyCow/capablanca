#ifndef ABOUTWINDOW_H
#define ABOUTWINDOW_H

#include <QDialog>
#include <QDesktopServices>
#include <QUrl>
#include <QFile>
#include <QTextStream>

namespace Ui {
class AboutWindow;
}

class AboutWindow : public QDialog
{
	Q_OBJECT

public:
	explicit AboutWindow(QWidget *parent = 0);
	~AboutWindow();

private slots:
	void on_button_close_released();
	void on_button_donate_released();
	void on_button_suggest_released();

private:
	Ui::AboutWindow *ui;

	QString getLabeledInfo(QString input, QString label);
};

#endif // ABOUTWINDOW_H
