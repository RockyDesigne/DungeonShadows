#pragma once

#include "IItem.h"

#include  "Actions.h"

namespace Raylib
{
#include <raylib.h>
#include <raymath.h>
}

using namespace Raylib;

class Torch : public IItem
{
public:
	Raylib::Vector2 get_position() override;

	Torch(const Raylib::Vector2 pos, const Raylib::Vector2 size, const Raylib::Color color);

	Raylib::Vector2 get_size() override;

	Actions action() override;

	void draw() override;

	int damage() override { return 0; }

private:
	Raylib::Vector2 m_pos;
	Raylib::Vector2 m_size;
	Raylib::Color m_color;
};
