#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QScrollBar>
#include "alertwindow.h"
#include "aboutwindow.h"
#include "ringitup.h"
#include "blockparty.h"

enum Season {
	SEASON_UNKNOWN = -1,
	SEASON_HALF_PIPE_HUSTLE = 0,
	SEASON_HANGIN_A_ROUND,
	SEASON_QUAD_QUANDARY,
	SEASON_FACE_OFF,
	SEASON_HOT_SHOT,
	SEASON_GET_OVER_IT,
	SEASON_BOWLED_OVER,
	SEASON_RING_IT_UP,
	SEASON_BLOCK_PARTY,
	SEASON_NUCLEAR_FALLOUT,
	SEASON_NUM
};

namespace Ui {
class StartWindow;
}

class StartWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit StartWindow(QWidget *parent = 0);
	~StartWindow();

	QPushButton* season_to_button(Season season);

private slots:
	void on_button_half_pipe_hustle_clicked();
	void on_button_hangin_a_round_clicked();
	void on_button_quad_quandary_clicked();
	void on_button_face_off_clicked();
	void on_button_hot_shot_clicked();
	void on_button_get_over_it_clicked();
	void on_button_bowled_over_clicked();
	void on_button_ring_it_up_clicked();
	void on_button_block_party_clicked();
	void on_button_nuclear_fallout_clicked();

	void on_button_about_released();

	void on_button_score_released();

	void on_button_report_bugs_clicked();

	void on_button_settings_clicked();

	void on_button_help_clicked();

private:
	Ui::StartWindow *ui;
	const Season default_season = SEASON_NUCLEAR_FALLOUT;
	Season current_season;
	AlertWindow* alertWindow;
	AboutWindow* aboutWindow;
	RingItUp* ringItUp;
	BlockParty* blockParty;

	void updateSeason();
	void updateSeason(Season season);
	void clearSeason();
};

#endif // STARTWINDOW_H
