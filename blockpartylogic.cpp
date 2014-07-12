#include "blockpartylogic.h"

BlockPartyLogic::BlockPartyLogic()
{
	clear();
}

void BlockPartyLogic::calculate()
{
	int block_score = 0;
	block_score = blocks_floor; // 1pt per block
	block_score += 2* (blocks_inner_L+blocks_inner_R); // 2pts per block
	block_score += 3* (blocks_outer_L+blocks_outer_R); // 3pts per block
	if (auton_block_A == beacon_position) {
		block_score += 40;
	} else {
		switch (auton_block_A) {
			case BlockPartyLogic::AUTON_NONE :
				break; // no points
			case BlockPartyLogic::AUTON_FLOOR :
				block_score += 5;
				break;
			default : // we're already inside an `else` block
				block_score += 20;
				break;
		}
	}
	if (auton_block_B == beacon_position) {
		block_score += 40;
	} else {
		switch (auton_block_B) {
			case BlockPartyLogic::AUTON_NONE :
				break; // no points
			case BlockPartyLogic::AUTON_FLOOR :
				block_score += 5;
				break;
			default : // we're already inside an `else` block
				block_score += 20;
				break;
		}
	}
	determine_balance();
	if (is_balanced) {
		block_score = static_cast<int>(round(block_score*1.5)); // 50% pt bonus
	}

	num = block_score;
	if (is_hanging_A) {
		num += 50;
	}
	if (is_hanging_B) {
		num += 50;
	}
	switch(ramp_position_A) {
		case RAMP_PARTIAL :
			num += 10;
			break;
		case RAMP_COMPLETE :
			num += 20;
			break;
	}
	switch(ramp_position_B) {
		case RAMP_PARTIAL :
			num += 10;
			break;
		case RAMP_COMPLETE :
			num += 20;
			break;
	}
	switch(flag_position) {
		case FLAG_LOW :
			num += 20;
			break;
		case FLAG_HIGH :
			num += 35;
			break;
	}

	score_no_penalties = num;
	penalty_pts = penalties_major*50 + penalties_minor*10;

	num += penalty_pts;

	emit update_ui();
}

void BlockPartyLogic::update_internals()
{
	calculate();
}

void BlockPartyLogic::clear()
{
	beacon_position = BEACON_LO;
	auton_block_A = AUTON_NONE;
	auton_block_B = AUTON_NONE;
	blocks_outer_L = 0;
	blocks_inner_L = 0;
	blocks_inner_R = 0;
	blocks_outer_R = 0;
	blocks_floor = 0;
	ramp_position_A = RAMP_OFF;
	ramp_position_B = RAMP_OFF;
	flag_position = FLAG_NONE;
	is_hanging_A = false;
	is_hanging_B  = false;
	penalties_major = 0;
	penalties_minor = 0;
	determine_balance();
	calculate();
}

void BlockPartyLogic::determine_balance()
{
	is_balanced = true; //temp line
	pendulum_angle = 0.0; //temp line
	//MATHS
}

void BlockPartyLogic::calculate_angle()
{
	//MATHS
}
