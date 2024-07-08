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
	void toggle_selected_item() override;

	//getters
	Raylib::Vector2 get_position() override;
	Raylib::Vector2 get_size() override;
	Raylib::Color get_color() override;

	std::shared_ptr<IItem> get_selected_item();
	std::vector<Actions> m_actions;

	Direction get_direction() override;

	void move() override;

	void draw_player();
private:
	int m_selected_item = 0;
	Direction m_direction;
};
