#ifndef BLOCKPARTYLOGIC_H
#define BLOCKPARTYLOGIC_H

#include <QObject>
#include <QWidget>
#include <QIntValidator>
#include <cmath>
#include "score.h"

class BlockPartyLogic : public Score
{
	Q_OBJECT
	friend class BlockParty;

public:
	enum RampPosition {
		RAMP_OFF = 0,
		RAMP_PARTIAL = 1,
		RAMP_COMPLETE = 2
	};
	enum FlagPosition {
		FLAG_NONE = 0,
		FLAG_LOW = 1,
		FLAG_HIGH = 2
	};
	enum BeaconPosition {
		AUTON_NONE = -1,
		BEACON_LO = 0,
		BEACON_LI = 1,
		BEACON_RI = 2,
		BEACON_RO = 3,
		AUTON_FLOOR = 4
	};

	BlockPartyLogic();
	void calculate();
	void update_internals();
	void clear();
	void determine_balance();
	void calculate_angle();

private:
	bool is_balanced;
	double pendulum_angle;
	BeaconPosition beacon_position;
	BeaconPosition auton_block_A;
	BeaconPosition auton_block_B;
	int blocks_outer_L;
	int blocks_inner_L;
	int blocks_inner_R;
	int blocks_outer_R;
	int blocks_floor;
	RampPosition ramp_position_A;
	RampPosition ramp_position_B;
	FlagPosition flag_position;
	bool is_hanging_A;
	bool is_hanging_B;
	int penalties_major;
	int penalties_minor;
	int penalty_pts;
	int score_no_penalties;
};

#endif // BLOCKPARTYLOGIC_H
