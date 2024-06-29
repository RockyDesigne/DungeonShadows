#include "Tile.h"


Tile::Tile(const Raylib::Vector2 pos, const Raylib::Vector2 size, const Raylib::Color color):
	m_position(pos), m_size(size), m_color(color)
{ }

Raylib::Vector2 Tile::get_position() const
{ return m_position; }

Raylib::Vector2 Tile::get_size() const
{ return m_size; }

Raylib::Color Tile::get_color() const
{ return m_color; }

void Tile::set_color(const Raylib::Color color)
{ m_color = color; }

void Tile::set_item(std::shared_ptr<IItem> item)
{ m_items.push_back(item); }

std::shared_ptr<IItem> Tile::get_item() const
{
	if (!m_items.empty()) {
		return m_items.front();
	}
	return nullptr;
}

void Tile::remove_item()
{
	if (!m_items.empty()) {
		m_items.pop_front();
	}
}

void Tile::draw()
{
	Raylib::DrawRectangleV({ m_position.x * m_size.x,m_position.y * m_size.y }, m_size, m_color);
	for (const auto& item : m_items)
	{
		item->draw();
	}
}
