#include "Torch.h"

#include <exception>

Raylib::Vector2 Torch::get_position()
{ return m_pos; }

Torch::Torch(const Raylib::Vector2 pos, const Raylib::Vector2 size, const Raylib::Color color):
	m_pos(pos), m_size(size), m_color(color)
{ }

Actions Torch::action()
{
	return Actions::TORCH_TOGGLE;
}

Raylib::Vector2 Torch::get_size()
{ return m_size; }

void Torch::draw()
{
	DrawRectangleV(m_pos, m_size, m_color);
}
