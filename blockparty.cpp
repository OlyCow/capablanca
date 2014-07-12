#include "blockparty.h"
#include "ui_blockparty.h"

BlockParty::BlockParty(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::BlockParty),
	auton_red_A(new QButtonGroup()),
	auton_red_B(new QButtonGroup()),
	auton_blue_A(new QButtonGroup()),
	auton_blue_B(new QButtonGroup()),
	score_red(new BlockPartyLogic()),
	score_blue(new BlockPartyLogic()),
	match(new Match())
{
	ui->setupUi(this);
	home_team = match->red->team1;

	ui->lineEdit_num_red_A->setValidator(new QIntValidator(1, 9999, this));
	ui->lineEdit_num_red_B->setValidator(new QIntValidator(1, 9999, this));
	ui->lineEdit_num_blue_A->setValidator(new QIntValidator(1, 9999, this));
	ui->lineEdit_num_blue_B->setValidator(new QIntValidator(1, 9999, this));

	QButtonGroup* auton_IR_red = new QButtonGroup();
	auton_IR_red->addButton(ui->radioButton_auton_IR_LO_red);
	auton_IR_red->addButton(ui->radioButton_auton_IR_LI_red);
	auton_IR_red->addButton(ui->radioButton_auton_IR_RI_red);
	auton_IR_red->addButton(ui->radioButton_auton_IR_RO_red);
	QButtonGroup* auton_IR_blue = new QButtonGroup();
	auton_IR_blue->addButton(ui->radioButton_auton_IR_LO_blue);
	auton_IR_blue->addButton(ui->radioButton_auton_IR_LI_blue);
	auton_IR_blue->addButton(ui->radioButton_auton_IR_RI_blue);
	auton_IR_blue->addButton(ui->radioButton_auton_IR_RO_blue);

	QObject::connect(score_red, SIGNAL(update_ui()), this, SLOT(update_ui()));
	QObject::connect(score_blue, SIGNAL(update_ui()), this, SLOT(update_ui()));

	update_ui();
}

BlockParty::~BlockParty()
{
	delete ui;
	delete score_red;
	delete score_blue;
	delete home_team;
	delete match;
}

void BlockParty::on_pushButton_close_clicked()
{
	this->close();
}

void BlockParty::on_pushButton_manual_summary_clicked()
{
	QDesktopServices::openUrl(QUrl::fromLocalFile("../help/game-manuals/Block Party! summary.pdf"));
}

void BlockParty::on_pushButton_manual_complete_clicked()
{
	QDesktopServices::openUrl(QUrl::fromLocalFile("../help/game-manuals/Block Party! complete.pdf"));
}

void BlockParty::radioButton_team_clicked(QRadioButton *button, Team *team)
{
	if (button->isChecked()) {
		home_team = team;
	}
	update_ui();
}
void BlockParty::on_radioButton_red_A_clicked()
{
	radioButton_team_clicked(ui->radioButton_red_A, match->red->team1);
}
void BlockParty::on_radioButton_red_B_clicked()
{
	radioButton_team_clicked(ui->radioButton_red_B, match->red->team2);
}
void BlockParty::on_radioButton_blue_A_clicked()
{
	radioButton_team_clicked(ui->radioButton_blue_A, match->blue->team1);
}
void BlockParty::on_radioButton_blue_B_clicked()
{
	radioButton_team_clicked(ui->radioButton_blue_B, match->blue->team2);
}

void BlockParty::lineEdit_num_editingFinished(QLineEdit* line_num, QLineEdit* line_name, Team* team)
{
	int team_number = line_num->text().toInt();
	team->setTeamNumber(team_number);
	if (line_name->text().isEmpty()) {
		line_name->setText(fetchTeamName(team_number));
		line_name->setCursorPosition(0);
	}
	update_ui();
}
void BlockParty::on_lineEdit_num_red_A_editingFinished()
{
	lineEdit_num_editingFinished(ui->lineEdit_num_red_A, ui->lineEdit_name_red_A, match->red->team1);
}
void BlockParty::on_lineEdit_num_red_B_editingFinished()
{
	lineEdit_num_editingFinished(ui->lineEdit_num_red_B, ui->lineEdit_name_red_B, match->red->team2);
}
void BlockParty::on_lineEdit_num_blue_A_editingFinished()
{
	lineEdit_num_editingFinished(ui->lineEdit_num_blue_A, ui->lineEdit_name_blue_A, match->red->team1);
}
void BlockParty::on_lineEdit_num_blue_B_editingFinished()
{
	lineEdit_num_editingFinished(ui->lineEdit_num_blue_B, ui->lineEdit_name_blue_B, match->red->team2);
}

QString BlockParty::fetchTeamName(int number_input)
{
	QString number_input_str = QString::number(number_input);
	QFile names_list(":/team_name_database.txt");
	names_list.open(QIODevice::ReadOnly | QIODevice::Text);
	QTextStream input(&names_list);
	QString line = "";
	QString name = "";
	while(!input.atEnd()) {
		line = input.readLine();
		if (line.startsWith(number_input_str+":")) {
			line.remove(0, number_input_str.length());
			line.remove(0, 1); // remove colon
			while (line.at(0) == '\t') {
				line.remove(0, 1); // remove tabs
			}
			name = line;
			break;
		}
	}
	return name;
}

void BlockParty::update_internals()
{
	score_red->update_internals();
	score_blue->update_internals();
}

void BlockParty::update_ui()
{
	ui->label_score_red->setText(QString::number(score_red->get()));
	ui->label_score_blue->setText(QString::number(score_blue->get()));

	QString home_red = "QLineEdit { \
		color: white; \
		background-color: red; }";
	QString home_blue = "QLineEdit { \
		color: white; \
		background-color: blue; }";
	QString norm_red = "QLineEdit { \
		color: red; \
		background-color: white; }";
	QString norm_blue = "QLineEdit { \
		color: blue; \
		background-color: white; }";
	if (home_team == match->red->team1) {
		ui->lineEdit_num_red_A->setStyleSheet(home_red);
		ui->lineEdit_name_red_A->setStyleSheet(home_red);
	} else {
		ui->lineEdit_num_red_A->setStyleSheet(norm_red);
		ui->lineEdit_name_red_A->setStyleSheet(norm_red);
	}
	if (home_team == match->red->team2) {
		ui->lineEdit_num_red_B->setStyleSheet(home_red);
		ui->lineEdit_name_red_B->setStyleSheet(home_red);
	} else {
		ui->lineEdit_num_red_B->setStyleSheet(norm_red);
		ui->lineEdit_name_red_B->setStyleSheet(norm_red);
	}
	if (home_team == match->blue->team1) {
		ui->lineEdit_num_blue_A->setStyleSheet(home_blue);
		ui->lineEdit_name_blue_A->setStyleSheet(home_blue);
	} else {
		ui->lineEdit_num_blue_A->setStyleSheet(norm_blue);
		ui->lineEdit_name_blue_A->setStyleSheet(norm_blue);
	}
	if (home_team == match->blue->team2) {
		ui->lineEdit_num_blue_B->setStyleSheet(home_blue);
		ui->lineEdit_name_blue_B->setStyleSheet(home_blue);
	} else {
		ui->lineEdit_num_blue_B->setStyleSheet(norm_blue);
		ui->lineEdit_name_blue_B->setStyleSheet(norm_blue);
	}

	ui->spinBox_blocks_red_LO->setValue(score_red->blocks_outer_L);
	ui->spinBox_blocks_red_LI->setValue(score_red->blocks_inner_L);
	ui->spinBox_blocks_red_RO->setValue(score_red->blocks_outer_R);
	ui->spinBox_blocks_red_RI->setValue(score_red->blocks_inner_R);
	ui->spinBox_blocks_red_floor->setValue(score_red->blocks_floor);

	ui->spinBox_blocks_blue_LO->setValue(score_blue->blocks_outer_L);
	ui->spinBox_blocks_blue_LI->setValue(score_blue->blocks_inner_L);
	ui->spinBox_blocks_blue_RO->setValue(score_blue->blocks_outer_R);
	ui->spinBox_blocks_blue_RI->setValue(score_blue->blocks_inner_R);
	ui->spinBox_blocks_blue_floor->setValue(score_blue->blocks_floor);

	ui->label_penalty_score_red->setText(QString::number(score_red->penalty_pts));
	ui->label_penalty_score_blue->setText(QString::number(score_blue->penalty_pts));
	ui->label_no_penalty_score_red->setText(QString::number(score_red->score_no_penalties));
	ui->label_no_penalty_score_blue->setText(QString::number(score_blue->score_no_penalties));
}

void BlockParty::lineEdit_name_editingFinished(QLineEdit* lineEdit, Team* team)
{
	team->setTeamName(lineEdit->text());
	update_ui();
}
void BlockParty::on_lineEdit_name_red_A_editingFinished()
{
	lineEdit_name_editingFinished(ui->lineEdit_name_red_A, match->red->team1);
}
void BlockParty::on_lineEdit_name_red_B_editingFinished()
{
	lineEdit_name_editingFinished(ui->lineEdit_name_red_B, match->red->team2);
}
void BlockParty::on_lineEdit_name_blue_A_editingFinished()
{
	lineEdit_name_editingFinished(ui->lineEdit_name_blue_A, match->blue->team1);
}
void BlockParty::on_lineEdit_name_blue_B_editingFinished()
{
	lineEdit_name_editingFinished(ui->lineEdit_name_blue_B, match->blue->team2);
}

void BlockParty::on_spinBox_blocks_red_LO_valueChanged(int val)
{
	score_red->blocks_outer_L = val;
	score_red->update_internals();
}
void BlockParty::on_spinBox_blocks_red_LI_valueChanged(int val)
{
	score_red->blocks_inner_L = val;
	score_red->update_internals();
}
void BlockParty::on_spinBox_blocks_red_RI_valueChanged(int val)
{
	score_red->blocks_inner_R = val;
	score_red->update_internals();
}
void BlockParty::on_spinBox_blocks_red_RO_valueChanged(int val)
{
	score_red->blocks_outer_R = val;
	score_red->update_internals();
}
void BlockParty::on_spinBox_blocks_red_floor_valueChanged(int val)
{
	score_red->blocks_floor = val;
	score_red->update_internals();
}
void BlockParty::on_spinBox_blocks_blue_LO_valueChanged(int val)
{
	score_blue->blocks_outer_L = val;
	score_blue->update_internals();
}
void BlockParty::on_spinBox_blocks_blue_LI_valueChanged(int val)
{
	score_blue->blocks_inner_L = val;
	score_blue->update_internals();
}
void BlockParty::on_spinBox_blocks_blue_RI_valueChanged(int val)
{
	score_blue->blocks_inner_R = val;
	score_blue->update_internals();
}
void BlockParty::on_spinBox_blocks_blue_RO_valueChanged(int val)
{
	score_blue->blocks_outer_R = val;
	score_blue->update_internals();
}
void BlockParty::on_spinBox_blocks_blue_floor_valueChanged(int val)
{
	score_blue->blocks_floor = val;
	score_blue->update_internals();
}

void BlockParty::on_checkBox_hanging_red_A_toggled(bool checked)
{
	score_red->is_hanging_A = checked;
	score_red->update_internals();
}
void BlockParty::on_checkBox_hanging_red_B_toggled(bool checked)
{
	score_red->is_hanging_B = checked;
	score_red->update_internals();
}
void BlockParty::on_checkBox_hanging_blue_A_toggled(bool checked)
{
	score_blue->is_hanging_A = checked;
	score_blue->update_internals();
}
void BlockParty::on_checkBox_hanging_blue_B_toggled(bool checked)
{
	score_blue->is_hanging_B = checked;
	score_blue->update_internals();
}

void BlockParty::verticalSlider_valueChanged(BlockPartyLogic* score, int value)
{
	switch (value) {
		case 0 :
			score->flag_position = BlockPartyLogic::FLAG_NONE;
			break;
		case 1 :
			score->flag_position = BlockPartyLogic::FLAG_LOW;
			break;
		case 2 :
			score->flag_position = BlockPartyLogic::FLAG_HIGH;
			break;
	}
	score->update_internals();
}
void BlockParty::on_verticalSlider_red_valueChanged(int value)
{
	verticalSlider_valueChanged(score_red, value);
}
void BlockParty::on_verticalSlider_blue_valueChanged(int value)
{
	verticalSlider_valueChanged(score_blue, value);
}

void BlockParty::on_comboBox_red_A_currentIndexChanged(int index)
{
	switch (index) {
		case 0 :
			score_red->ramp_position_A = BlockPartyLogic::RAMP_OFF;
			break;
		case 1 :
			score_red->ramp_position_A = BlockPartyLogic::RAMP_PARTIAL;
			break;
		case 2 :
			score_red->ramp_position_A = BlockPartyLogic::RAMP_COMPLETE;
			break;
	}
	score_red->update_internals();
}
void BlockParty::on_comboBox_red_B_currentIndexChanged(int index)
{
	switch (index) {
		case 0 :
			score_red->ramp_position_B = BlockPartyLogic::RAMP_OFF;
			break;
		case 1 :
			score_red->ramp_position_B = BlockPartyLogic::RAMP_PARTIAL;
			break;
		case 2 :
			score_red->ramp_position_B = BlockPartyLogic::RAMP_COMPLETE;
			break;
	}
	score_red->update_internals();
}
void BlockParty::on_comboBox_blue_A_currentIndexChanged(int index)
{
	switch (index) {
		case 0 :
			score_blue->ramp_position_A = BlockPartyLogic::RAMP_OFF;
			break;
		case 1 :
			score_blue->ramp_position_A = BlockPartyLogic::RAMP_PARTIAL;
			break;
		case 2 :
			score_blue->ramp_position_A = BlockPartyLogic::RAMP_COMPLETE;
			break;
	}
	score_blue->update_internals();
}
void BlockParty::on_comboBox_blue_B_currentIndexChanged(int index)
{
	switch (index) {
		case 0 :
			score_blue->ramp_position_B = BlockPartyLogic::RAMP_OFF;
			break;
		case 1 :
			score_blue->ramp_position_B = BlockPartyLogic::RAMP_PARTIAL;
			break;
		case 2 :
			score_blue->ramp_position_B = BlockPartyLogic::RAMP_COMPLETE;
			break;
	}
	score_blue->update_internals();
}

void BlockParty::on_spinBox_penalty_major_red_valueChanged(int arg1)
{
	score_blue->penalties_major = arg1;
	score_blue->update_internals();
}
void BlockParty::on_spinBox_penalty_minor_red_valueChanged(int arg1)
{
	score_blue->penalties_minor = arg1;
	score_blue->update_internals();
}
void BlockParty::on_spinBox_penalty_major_blue_valueChanged(int arg1)
{
	score_red->penalties_major = arg1;
	score_red->update_internals();
}
void BlockParty::on_spinBox_penalty_minor_blue_valueChanged(int arg1)
{
	score_red->penalties_minor = arg1;
	score_red->update_internals();
}

void BlockParty::on_radioButton_auton_IR_LO_red_clicked()
{
	ui->radioButton_auton_IR_RO_blue->setChecked(true);
	score_red->beacon_position = BlockPartyLogic::BEACON_LO;
	score_blue->beacon_position = BlockPartyLogic::BEACON_RO;
	score_red->update_internals();
	score_blue->update_internals();
}
void BlockParty::on_radioButton_auton_IR_LI_red_clicked()
{
	ui->radioButton_auton_IR_RI_blue->setChecked(true);
	score_red->beacon_position = BlockPartyLogic::BEACON_LI;
	score_blue->beacon_position = BlockPartyLogic::BEACON_RI;
	score_red->update_internals();
	score_blue->update_internals();
}
void BlockParty::on_radioButton_auton_IR_RI_red_clicked()
{
	ui->radioButton_auton_IR_LI_blue->setChecked(true);
	score_red->beacon_position = BlockPartyLogic::BEACON_RI;
	score_blue->beacon_position = BlockPartyLogic::BEACON_LI;
	score_red->update_internals();
	score_blue->update_internals();
}
void BlockParty::on_radioButton_auton_IR_RO_red_clicked()
{
	ui->radioButton_auton_IR_LO_blue->setChecked(true);
	score_red->beacon_position = BlockPartyLogic::BEACON_RO;
	score_blue->beacon_position = BlockPartyLogic::BEACON_LO;
	score_red->update_internals();
	score_blue->update_internals();
}
void BlockParty::on_radioButton_auton_IR_LO_blue_clicked()
{
	ui->radioButton_auton_IR_RO_red->setChecked(true);
	score_red->beacon_position = BlockPartyLogic::BEACON_LO;
	score_blue->beacon_position = BlockPartyLogic::BEACON_RO;
	score_red->update_internals();
	score_blue->update_internals();
}
void BlockParty::on_radioButton_auton_IR_LI_blue_clicked()
{
	ui->radioButton_auton_IR_RI_red->setChecked(true);
	score_red->beacon_position = BlockPartyLogic::BEACON_LI;
	score_blue->beacon_position = BlockPartyLogic::BEACON_RI;
	score_red->update_internals();
	score_blue->update_internals();
}
void BlockParty::on_radioButton_auton_IR_RI_blue_clicked()
{
	ui->radioButton_auton_IR_LI_red->setChecked(true);
	score_red->beacon_position = BlockPartyLogic::BEACON_RI;
	score_blue->beacon_position = BlockPartyLogic::BEACON_LI;
	score_red->update_internals();
	score_blue->update_internals();
}
void BlockParty::on_radioButton_auton_IR_RO_blue_clicked()
{
	ui->radioButton_auton_IR_LO_red->setChecked(true);
	score_red->beacon_position = BlockPartyLogic::BEACON_RO;
	score_blue->beacon_position = BlockPartyLogic::BEACON_LO;
	score_red->update_internals();
	score_blue->update_internals();
}

void BlockParty::uncheck_red_A()
{
	ui->checkBox_auton_red_A_LO->setChecked(false);
	ui->checkBox_auton_red_A_LI->setChecked(false);
	ui->checkBox_auton_red_A_RI->setChecked(false);
	ui->checkBox_auton_red_A_RO->setChecked(false);
	ui->checkBox_auton_red_A_floor->setChecked(false);
}
void BlockParty::uncheck_red_B()
{
	ui->checkBox_auton_red_B_LO->setChecked(false);
	ui->checkBox_auton_red_B_LI->setChecked(false);
	ui->checkBox_auton_red_B_RI->setChecked(false);
	ui->checkBox_auton_red_B_RO->setChecked(false);
	ui->checkBox_auton_red_B_floor->setChecked(false);
}
void BlockParty::uncheck_blue_A()
{
	ui->checkBox_auton_blue_A_LO->setChecked(false);
	ui->checkBox_auton_blue_A_LI->setChecked(false);
	ui->checkBox_auton_blue_A_RI->setChecked(false);
	ui->checkBox_auton_blue_A_RO->setChecked(false);
	ui->checkBox_auton_blue_A_floor->setChecked(false);
}
void BlockParty::uncheck_blue_B()
{
	ui->checkBox_auton_blue_B_LO->setChecked(false);
	ui->checkBox_auton_blue_B_LI->setChecked(false);
	ui->checkBox_auton_blue_B_RI->setChecked(false);
	ui->checkBox_auton_blue_B_RO->setChecked(false);
	ui->checkBox_auton_blue_B_floor->setChecked(false);
}

void BlockParty::on_checkBox_auton_red_A_LO_clicked(bool checked)
{
	uncheck_red_A();
	if (checked) {
		score_red->auton_block_A = BlockPartyLogic::BEACON_LO;
	} else {
		score_red->auton_block_A = BlockPartyLogic::AUTON_NONE;
	}
	score_red->update_internals();
}
void BlockParty::on_checkBox_auton_red_A_LI_clicked(bool checked)
{
	uncheck_red_A();
	if (checked) {
		score_red->auton_block_A = BlockPartyLogic::BEACON_LI;
	} else {
		score_red->auton_block_A = BlockPartyLogic::AUTON_NONE;
	}
	score_red->update_internals();
}
void BlockParty::on_checkBox_auton_red_A_RI_clicked(bool checked)
{
	uncheck_red_A();
	if (checked) {
		score_red->auton_block_A = BlockPartyLogic::BEACON_RI;
	} else {
		score_red->auton_block_A = BlockPartyLogic::AUTON_NONE;
	}
	score_red->update_internals();
}
void BlockParty::on_checkBox_auton_red_A_RO_clicked(bool checked)
{
	uncheck_red_A();
	if (checked) {
		score_red->auton_block_A = BlockPartyLogic::BEACON_RO;
	} else {
		score_red->auton_block_A = BlockPartyLogic::AUTON_NONE;
	}
	score_red->update_internals();
}
void BlockParty::on_checkBox_auton_red_A_floor_clicked(bool checked)
{
	uncheck_red_A();
	if (checked) {
		score_red->auton_block_A = BlockPartyLogic::AUTON_FLOOR;
	} else {
		score_red->auton_block_A = BlockPartyLogic::AUTON_NONE;
	}
	score_red->update_internals();
}
void BlockParty::on_checkBox_auton_red_B_LO_clicked(bool checked)
{
	uncheck_red_B();
	if (checked) {
		score_red->auton_block_B = BlockPartyLogic::BEACON_LO;
	} else {
		score_red->auton_block_B = BlockPartyLogic::AUTON_NONE;
	}
	score_red->update_internals();
}
void BlockParty::on_checkBox_auton_red_B_LI_clicked(bool checked)
{
	uncheck_red_B();
	if (checked) {
		score_red->auton_block_B = BlockPartyLogic::BEACON_LI;
	} else {
		score_red->auton_block_B = BlockPartyLogic::AUTON_NONE;
	}
	score_red->update_internals();
}
void BlockParty::on_checkBox_auton_red_B_RI_clicked(bool checked)
{
	uncheck_red_B();
	if (checked) {
		score_red->auton_block_B = BlockPartyLogic::BEACON_RI;
	} else {
		score_red->auton_block_B = BlockPartyLogic::AUTON_NONE;
	}
	score_red->update_internals();
}
void BlockParty::on_checkBox_auton_red_B_RO_clicked(bool checked)
{
	uncheck_red_B();
	if (checked) {
		score_red->auton_block_B = BlockPartyLogic::BEACON_RO;
	} else {
		score_red->auton_block_B = BlockPartyLogic::AUTON_NONE;
	}
	score_red->update_internals();
}
void BlockParty::on_checkBox_auton_red_B_floor_clicked(bool checked)
{
	uncheck_red_B();
	if (checked) {
		score_red->auton_block_B = BlockPartyLogic::AUTON_FLOOR;
	} else {
		score_red->auton_block_B = BlockPartyLogic::AUTON_NONE;
	}
	score_red->update_internals();
}

void BlockParty::on_checkBox_auton_blue_A_LO_clicked(bool checked)
{
	uncheck_blue_A();
	if (checked) {
		score_blue->auton_block_A = BlockPartyLogic::BEACON_LO;
	} else {
		score_blue->auton_block_A = BlockPartyLogic::AUTON_NONE;
	}
	score_blue->update_internals();
}
void BlockParty::on_checkBox_auton_blue_A_LI_clicked(bool checked)
{
	uncheck_blue_A();
	if (checked) {
		score_blue->auton_block_A = BlockPartyLogic::BEACON_LI;
	} else {
		score_blue->auton_block_A = BlockPartyLogic::AUTON_NONE;
	}
	score_blue->update_internals();
}
void BlockParty::on_checkBox_auton_blue_A_RI_clicked(bool checked)
{
	uncheck_blue_A();
	if (checked) {
		score_blue->auton_block_A = BlockPartyLogic::BEACON_RI;
	} else {
		score_blue->auton_block_A = BlockPartyLogic::AUTON_NONE;
	}
	score_blue->update_internals();
}
void BlockParty::on_checkBox_auton_blue_A_RO_clicked(bool checked)
{
	uncheck_blue_A();
	if (checked) {
		score_blue->auton_block_A = BlockPartyLogic::BEACON_RO;
	} else {
		score_blue->auton_block_A = BlockPartyLogic::AUTON_NONE;
	}
	score_blue->update_internals();
}
void BlockParty::on_checkBox_auton_blue_A_floor_clicked(bool checked)
{
	uncheck_blue_A();
	if (checked) {
		score_blue->auton_block_A = BlockPartyLogic::AUTON_FLOOR;
	} else {
		score_blue->auton_block_A = BlockPartyLogic::AUTON_NONE;
	}
	score_blue->update_internals();
}
void BlockParty::on_checkBox_auton_blue_B_LO_clicked(bool checked)
{
	uncheck_blue_B();
	if (checked) {
		score_blue->auton_block_B = BlockPartyLogic::BEACON_LO;
	} else {
		score_blue->auton_block_B = BlockPartyLogic::AUTON_NONE;
	}
	score_blue->update_internals();
}
void BlockParty::on_checkBox_auton_blue_B_LI_clicked(bool checked)
{
	uncheck_blue_B();
	if (checked) {
		score_blue->auton_block_B = BlockPartyLogic::BEACON_LI;
	} else {
		score_blue->auton_block_B = BlockPartyLogic::AUTON_NONE;
	}
	score_blue->update_internals();
}
void BlockParty::on_checkBox_auton_blue_B_RI_clicked(bool checked)
{
	uncheck_blue_B();
	if (checked) {
		score_blue->auton_block_B = BlockPartyLogic::BEACON_RI;
	} else {
		score_blue->auton_block_B = BlockPartyLogic::AUTON_NONE;
	}
	score_blue->update_internals();
}
void BlockParty::on_checkBox_auton_blue_B_RO_clicked(bool checked)
{
	uncheck_blue_B();
	if (checked) {
		score_blue->auton_block_B = BlockPartyLogic::BEACON_RO;
	} else {
		score_blue->auton_block_B = BlockPartyLogic::AUTON_NONE;
	}
	score_blue->update_internals();
}
void BlockParty::on_checkBox_auton_blue_B_floor_clicked(bool checked)
{
	uncheck_blue_B();
	if (checked) {
		score_blue->auton_block_B = BlockPartyLogic::AUTON_FLOOR;
	} else {
		score_blue->auton_block_B = BlockPartyLogic::AUTON_NONE;
	}
	score_blue->update_internals();
}
