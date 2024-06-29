#include "Torch.h"

#include <exception>

Raylib::Vector2 Torch::get_position()
{ return m_pos; }

Torch::Torch(const Raylib::Vector2 pos, const Raylib::Vector2 size, const Raylib::Color color):
	m_pos(pos), m_size(size), m_color(color)
{ }

void Torch::action()
{
	throw std::exception("action method for Torch not implemented");
}

void Torch::draw()
{
	float scale = 1 / 4.f; // Scale factor for the item
	Raylib::Vector2 top_left_tile_corner = Raylib::Vector2Scale(m_pos, m_size.x);

	// Calculate the size of the item
	Raylib::Vector2 small_square_size = Raylib::Vector2Scale(m_size, scale);

	// oofset by half the size of the item
	Raylib::Vector2 center_tile = {
		top_left_tile_corner.x + (m_size.x - small_square_size.x) / 2.f,
		top_left_tile_corner.y + (m_size.y - small_square_size.y) / 2.f
	};

	DrawRectangleV(center_tile, small_square_size, m_color);
}
