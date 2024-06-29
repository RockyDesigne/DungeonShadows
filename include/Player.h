#pragma once

#include "IItem.h"

namespace Raylib
{
#include <raylib.h>
}

using namespace Raylib;

#include <vector>
#include <memory>

class Player
{
public:

	Player(const Raylib::Vector2 pos, const Raylib::Vector2 size, const Raylib::Color color);

	Raylib::Vector2 m_position;
	Raylib::Vector2 m_size;

	Raylib::Color m_color;

	float m_speed = 0.2f;

	std::vector<std::shared_ptr<IItem>> m_items;

	void draw_player();

	void handle_input();
};
