#pragma once

#include "Direction.h"

class GameActor
{
public:
	virtual ~GameActor() = default;
	virtual void set_direction_left() = 0;
	virtual void set_direction_right() = 0;
	virtual void set_direction_up() = 0;
	virtual void set_direction_down() = 0;
	virtual void move() = 0;
	virtual Direction get_direction() = 0;
};
