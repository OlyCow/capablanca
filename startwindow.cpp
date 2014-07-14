#include "startwindow.h"
#include "ui_startwindow.h"

StartWindow::StartWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::StartWindow),
	aboutWindow(new AboutWindow(this)),
	ringItUp(new RingItUp(this)),
	blockParty(new BlockParty(this))
{
	ui->setupUi(this);

	updateSeason(default_season);
	ui->scrollArea->horizontalScrollBar()->setValue(season_to_button(default_season)->x());
}

StartWindow::~StartWindow()
{
	delete ringItUp;
	delete blockParty;
	delete aboutWindow;
	delete ui;
}

QPushButton* StartWindow::season_to_button(Season season)
{
	QPushButton* button;
	switch (season)
	{
		case SEASON_HALF_PIPE_HUSTLE :
			button = ui->button_half_pipe_hustle;
			break;
		case SEASON_HANGIN_A_ROUND :
			button = ui->button_hangin_a_round;
			break;
		case SEASON_QUAD_QUANDARY :
			button = ui->button_quad_quandary;
			break;
		case SEASON_FACE_OFF :
			button = ui->button_face_off;
			break;
		case SEASON_HOT_SHOT :
			button = ui->button_hot_shot;
			break;
		case SEASON_GET_OVER_IT :
			button = ui->button_get_over_it;
			break;
		case SEASON_BOWLED_OVER :
			button = ui->button_bowled_over;
			break;
		case SEASON_RING_IT_UP :
			button = ui->button_ring_it_up;
			break;
		case SEASON_BLOCK_PARTY :
			button = ui->button_block_party;
			break;
		case SEASON_NUCLEAR_FALLOUT :
			button = ui->button_nuclear_fallout;
			break;
		default :
			button = NULL;
			break;
	}
	return button;
}

void StartWindow::updateSeason()
{
	for(int i=(static_cast<int>(SEASON_UNKNOWN))+1; i<static_cast<int>(SEASON_NUM); ++i) {
		if (i == static_cast<int>(current_season)) {
			season_to_button(static_cast<Season>(i))->setChecked(true);
		} else {
			season_to_button(static_cast<Season>(i))->setChecked(false);
		}
	}
}

void StartWindow::updateSeason(Season season)
{
	current_season = season;
	updateSeason();
}

void StartWindow::clearSeason()
{
	updateSeason(SEASON_UNKNOWN);
}

void StartWindow::on_button_half_pipe_hustle_clicked()
{
	if (ui->button_half_pipe_hustle->isChecked()) {
		updateSeason(SEASON_HALF_PIPE_HUSTLE);
	} else {
		clearSeason();
	}
}

void StartWindow::on_button_hangin_a_round_clicked()
{
	if (ui->button_hangin_a_round->isChecked()) {
		updateSeason(SEASON_HANGIN_A_ROUND);
	} else {
		clearSeason();
	}
}

void StartWindow::on_button_quad_quandary_clicked()
{
	if (ui->button_quad_quandary->isChecked()) {
		updateSeason(SEASON_QUAD_QUANDARY);
	} else {
		clearSeason();
	}
}

void StartWindow::on_button_face_off_clicked()
{
	if (ui->button_face_off->isChecked()) {
		updateSeason(SEASON_FACE_OFF);
	} else {
		clearSeason();
	}
}

void StartWindow::on_button_hot_shot_clicked()
{
	if (ui->button_hot_shot->isChecked()) {
		updateSeason(SEASON_HOT_SHOT);
	} else {
		clearSeason();
	}
}

void StartWindow::on_button_get_over_it_clicked()
{
	if (ui->button_get_over_it->isChecked()) {
		updateSeason(SEASON_GET_OVER_IT);
	} else {
		clearSeason();
	}
}

void StartWindow::on_button_bowled_over_clicked()
{
	if (ui->button_bowled_over->isChecked()) {
		updateSeason(SEASON_BOWLED_OVER);
	} else {
		clearSeason();
	}
}

void StartWindow::on_button_ring_it_up_clicked()
{
	if (ui->button_ring_it_up->isChecked()) {
		updateSeason(SEASON_RING_IT_UP);
	} else {
		clearSeason();
	}
}

void StartWindow::on_button_block_party_clicked()
{
	if (ui->button_block_party->isChecked()) {
		updateSeason(SEASON_BLOCK_PARTY);
	} else {
		clearSeason();
	}
}

void StartWindow::on_button_nuclear_fallout_clicked()
{
	if (ui->button_nuclear_fallout->isChecked()) {
		updateSeason(SEASON_NUCLEAR_FALLOUT);
	} else {
		clearSeason();
	}
}

void StartWindow::on_button_about_released()
{
	aboutWindow->show();
}

void StartWindow::on_button_score_released()
{
	switch (current_season) {
		case SEASON_UNKNOWN :
			alertWindow = new AlertWindow(this, QString("Choose a season to score first."));
			alertWindow->show();
			break;
		case SEASON_RING_IT_UP :
			ringItUp->show();
			break;
		case SEASON_BLOCK_PARTY :
			blockParty->show();
			break;
		default :
			alertWindow = new AlertWindow(this, QString("The scoring for this game hasn't been implemented yet."));
			alertWindow->show();
			break;
	}
}

void StartWindow::on_button_report_bugs_clicked()
{
	alertWindow = new AlertWindow(this, QString("Sorry, we're not accepting bug reports yet."));
	alertWindow->show();
	alertWindow->setAttribute(Qt::WA_DeleteOnClose);
}

void StartWindow::on_button_settings_clicked()
{
	alertWindow = new AlertWindow(this, QString("There aren't even settings to change yet!"));
	alertWindow->show();
	alertWindow->setAttribute(Qt::WA_DeleteOnClose);
}

void StartWindow::on_button_help_clicked()
{
	alertWindow = new AlertWindow(this, QString("Help? Help. Help! HELP!!!!"));
	alertWindow->show();
	alertWindow->setAttribute(Qt::WA_DeleteOnClose);
}
