#include "aboutwindow.h"
#include "ui_aboutwindow.h"

AboutWindow::AboutWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutWindow)
{
	ui->setupUi(this);

	QFile build_info(":/data/build_info.txt");
	build_info.open(QIODevice::ReadOnly | QIODevice::Text);
	QTextStream input(&build_info);
	QString line = "";
	const QString major_rev_label = "Major Version";
	QString major_rev = "";
	const QString minor_rev_label = "Minor Version";
	QString minor_rev = "";
	const QString rev_type_label = "Version Status";
	QString rev_type = "";
	const QString build_num_label = "Build Number";
	QString build_num = "";
	while (!input.atEnd()) {
		line = input.readLine();
		major_rev += getLabeledInfo(line, major_rev_label);
		minor_rev += getLabeledInfo(line, minor_rev_label);
		rev_type += getLabeledInfo(line, rev_type_label);
		build_num += getLabeledInfo(line, build_num_label);
	}

	QString label_version_text = "v" + major_rev + "." + minor_rev + "-" + rev_type;
	ui->label_version->setText(label_version_text);
	build_num = build_num.rightJustified(4, '0'); // MAGIC_NUM (4)
	QString label_build_text = "Build " + build_num;
	ui->label_build_num->setText(label_build_text);
}

AboutWindow::~AboutWindow()
{
	delete ui;
}

void AboutWindow::on_button_close_released()
{
	this->close();
}

void AboutWindow::on_button_donate_released()
{
	QDesktopServices::openUrl(QUrl("http://stempals.org/stem-programs/robotics/volunteer-or-donate/make-a-donation-2/?need=FTC%20Team%206424", QUrl::TolerantMode));
}

void AboutWindow::on_button_suggest_released()
{
	QDesktopServices::openUrl(QUrl("mailto:mooovingforward@gmail.com?subject=[CAPABLANCA] Suggestion for improvement", QUrl::TolerantMode));
}

QString AboutWindow::getLabeledInfo(QString input, QString label)
{
	QString result = "";
	if (input.startsWith(label)) {
		result = input;
		result.remove(0, (label+": ").length());
	}
	return result;
}

