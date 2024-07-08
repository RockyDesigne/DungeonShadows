#pragma once

#include "Direction.h"

namespace Raylib
{
	#include <raylib.h>
}

using namespace Raylib;

class GameActor
{
public:
	virtual ~GameActor() = default;
	virtual void set_direction_left() = 0;
	virtual void set_direction_right() = 0;
	virtual void set_direction_up() = 0;
	virtual void set_direction_down() = 0;
	virtual void toggle_selected_item() = 0;
	virtual void move() = 0;
	virtual Raylib::Vector2 get_position() = 0;
	virtual Raylib::Vector2 get_size() = 0;
	virtual Raylib::Color get_color() = 0;
	virtual Direction get_direction() = 0;
};
