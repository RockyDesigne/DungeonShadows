#include "Sword.h"

Sword::Sword(const Raylib::Vector2 pos, const Raylib::Vector2 size, const Raylib::Color color)
	: m_pos(pos), m_size(size), m_color(color)
{}

Raylib::Vector2 Sword::get_position()
{
	return m_pos;
}

Raylib::Vector2 Sword::get_size()
{
	return m_size;
}

Actions Sword::action()
{
	return Actions::SWORD_ATTACK;
}

void Sword::draw()
{
	DrawRectangleV(m_pos, m_size, m_color);
}
