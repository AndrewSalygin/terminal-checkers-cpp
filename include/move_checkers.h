#ifndef MOVE_CHECKERS_H
#define MOVE_CHECKERS_H

#include "rules.h"

bool move_checkers(Desk *desk, std::string &step, Figure_Color &color_passage,
					bool &player_draw, Desk *copy_desk,
					Figure_Color &copy_color_passage, std::fstream &save_moves);

#endif