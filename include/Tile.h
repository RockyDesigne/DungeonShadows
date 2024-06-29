#pragma once

#include "IItem.h"

namespace Raylib {
#include <raylib.h>
#include <raymath.h>
}

using namespace Raylib;

#include <list>
#include <memory>

class Tile
{
public:
	Tile(const Raylib::Vector2 pos, const Raylib::Vector2 size, const Raylib::Color color);
	Raylib::Vector2 get_position() const;
	Raylib::Vector2 get_size() const;
	Raylib::Color get_color() const;
	void set_color(const Raylib::Color color);
	void set_item(std::shared_ptr<IItem> item);

	std::shared_ptr<IItem> get_item() const;

	void remove_item();

	void draw();

	virtual ~Tile() = default;

private:
	Raylib::Vector2 m_position;
	Raylib::Vector2 m_size;
	Raylib::Color m_color;
	std::list<std::shared_ptr<IItem>> m_items{};
};
