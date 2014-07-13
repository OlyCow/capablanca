#ifndef BLOCKPARTY_H
#define BLOCKPARTY_H

#include <QMainWindow>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDesktopServices>
#include <QUrl>
#include <QButtonGroup>
#include <QRadioButton>
#include <QLineEdit>
#include "match.h"
#include "team.h"
#include "blockpartylogic.h"
#include "hoverrepaint.h"
#include "checkboxgroup.h"

namespace Ui {
class BlockParty;
}

class BlockParty : public QMainWindow
{
	Q_OBJECT

public:
	explicit BlockParty(QWidget *parent = 0);
	~BlockParty();

	BlockPartyLogic* score_red;
	BlockPartyLogic* score_blue;
	Match* match;
	Team* home_team;

	void radioButton_team_clicked(QRadioButton* button, Team* team);
	void lineEdit_num_editingFinished(QLineEdit* line_num, QLineEdit* line_name, Team* team);
	void lineEdit_name_editingFinished(QLineEdit* lineEdit, Team* team);
	void verticalSlider_valueChanged();
	void comboBox_currentIndexChanged();

public slots:

private slots:
	void update_ui();

	void on_pushButton_close_clicked();

	void on_pushButton_manual_summary_clicked();
	void on_pushButton_manual_complete_clicked();

	void on_radioButton_red_A_clicked();
	void on_radioButton_red_B_clicked();
	void on_radioButton_blue_A_clicked();
	void on_radioButton_blue_B_clicked();

	void on_lineEdit_num_red_A_editingFinished();
	void on_lineEdit_num_red_B_editingFinished();
	void on_lineEdit_num_blue_A_editingFinished();
	void on_lineEdit_num_blue_B_editingFinished();
	void on_lineEdit_name_red_A_editingFinished();
	void on_lineEdit_name_red_B_editingFinished();
	void on_lineEdit_name_blue_A_editingFinished();
	void on_lineEdit_name_blue_B_editingFinished();

	void on_spinBox_blocks_red_LO_valueChanged(int val);
	void on_spinBox_blocks_red_LI_valueChanged(int val);
	void on_spinBox_blocks_red_RI_valueChanged(int val);
	void on_spinBox_blocks_red_RO_valueChanged(int val);
	void on_spinBox_blocks_red_floor_valueChanged(int val);
	void on_spinBox_blocks_blue_LO_valueChanged(int val);
	void on_spinBox_blocks_blue_LI_valueChanged(int val);
	void on_spinBox_blocks_blue_RI_valueChanged(int val);
	void on_spinBox_blocks_blue_RO_valueChanged(int val);
	void on_spinBox_blocks_blue_floor_valueChanged(int val);

	void on_checkBox_hanging_red_A_toggled(bool checked);
	void on_checkBox_hanging_red_B_toggled(bool checked);
	void on_checkBox_hanging_blue_A_toggled(bool checked);
	void on_checkBox_hanging_blue_B_toggled(bool checked);

	void on_verticalSlider_red_valueChanged();
	void on_verticalSlider_blue_valueChanged();

	void on_comboBox_red_A_currentIndexChanged();
	void on_comboBox_red_B_currentIndexChanged();
	void on_comboBox_blue_A_currentIndexChanged();
	void on_comboBox_blue_B_currentIndexChanged();

	void on_spinBox_penalty_major_red_valueChanged(int arg1);
	void on_spinBox_penalty_minor_red_valueChanged(int arg1);
	void on_spinBox_penalty_major_blue_valueChanged(int arg1);
	void on_spinBox_penalty_minor_blue_valueChanged(int arg1);

	void on_radioButton_auton_IR_LO_red_clicked();
	void on_radioButton_auton_IR_LI_red_clicked();
	void on_radioButton_auton_IR_RI_red_clicked();
	void on_radioButton_auton_IR_RO_red_clicked();
	void on_radioButton_auton_IR_LO_blue_clicked();
	void on_radioButton_auton_IR_LI_blue_clicked();
	void on_radioButton_auton_IR_RI_blue_clicked();
	void on_radioButton_auton_IR_RO_blue_clicked();

	void on_checkBox_auton_red_A_LO_clicked(bool checked);
	void on_checkBox_auton_red_A_LI_clicked(bool checked);
	void on_checkBox_auton_red_A_RI_clicked(bool checked);
	void on_checkBox_auton_red_A_RO_clicked(bool checked);
	void on_checkBox_auton_red_A_floor_clicked(bool checked);
	void on_checkBox_auton_red_B_LO_clicked(bool checked);
	void on_checkBox_auton_red_B_LI_clicked(bool checked);
	void on_checkBox_auton_red_B_RI_clicked(bool checked);
	void on_checkBox_auton_red_B_RO_clicked(bool checked);
	void on_checkBox_auton_red_B_floor_clicked(bool checked);
	void on_checkBox_auton_blue_A_LO_clicked(bool checked);
	void on_checkBox_auton_blue_A_LI_clicked(bool checked);
	void on_checkBox_auton_blue_A_RI_clicked(bool checked);
	void on_checkBox_auton_blue_A_RO_clicked(bool checked);
	void on_checkBox_auton_blue_A_floor_clicked(bool checked);
	void on_checkBox_auton_blue_B_LO_clicked(bool checked);
	void on_checkBox_auton_blue_B_LI_clicked(bool checked);
	void on_checkBox_auton_blue_B_RI_clicked(bool checked);
	void on_checkBox_auton_blue_B_RO_clicked(bool checked);
	void on_checkBox_auton_blue_B_floor_clicked(bool checked);

private:
	Ui::BlockParty *ui;
	QButtonGroup* auton_IR_red;
	QButtonGroup* auton_IR_blue;
	CheckboxGroup* auton_red_A;
	CheckboxGroup* auton_red_B;
	CheckboxGroup* auton_blue_A;
	CheckboxGroup* auton_blue_B;

	void update_internals();
	QString fetchTeamName(int number_input);
	void uncheck_red_A();
	void uncheck_red_B();
	void uncheck_blue_A();
	void uncheck_blue_B();
};

#endif // BLOCKPARTY_H
