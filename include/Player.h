#pragma once

#include "IItem.h"
#include "Command.h"
#include "GameActor.h"
#include "Direction.h"

namespace Raylib
{
#include <raylib.h>
}

using namespace Raylib;

#include <vector>
#include <memory>

class Player : public GameActor
{
public:

	Player(const Raylib::Vector2 pos, const Raylib::Vector2 size, const Raylib::Color color);

	Raylib::Vector2 m_position;
	Raylib::Vector2 m_size;

	Raylib::Color m_color;

	float m_speed = 1.f;

	std::vector<std::shared_ptr<IItem>> m_items;

	void set_direction_left() override;
	void set_direction_right() override;
	void set_direction_up() override;
	void set_direction_down() override;

	Direction get_direction() override;

	void move() override;

	void draw_player();
private:
	Direction m_direction;
};
