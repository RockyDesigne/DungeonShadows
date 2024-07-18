#include "Skeleton.h"

Skeleton::Skeleton(const Raylib::Vector2 pos, const Raylib::Vector2 size, const Raylib::Color color)
	: m_pos(pos), m_size(size), m_color(color)
{}

void Skeleton::set_direction_left()
{
	m_direction = Direction::LEFT;
}

void Skeleton::set_direction_right()
{
		m_direction = Direction::RIGHT;
}

void Skeleton::set_direction_up()
{
	m_direction = Direction::UP;
}

void Skeleton::set_direction_down()
{
	m_direction = Direction::DOWN;
}

void Skeleton::toggle_selected_item()
{

}

void Skeleton::move()
{
	switch (m_direction)
	{
	case Direction::UP:
		m_pos.y -= m_speed;
		break;
	case Direction::DOWN:
		m_pos.y += m_speed;
		break;
	case Direction::LEFT:
		m_pos.x -= m_speed;
		break;
	case Direction::RIGHT:
		m_pos.x += m_speed;
		break;
	}
}

void Skeleton::draw()
{
	DrawRectangleV(m_pos, m_size, m_color);
}

int Skeleton::get_health()
{
	return health;
}

void Skeleton::receive_damage(int damage)
{
	if (health > 0)
	{
		health -= damage;
	}
}

int Skeleton::get_damage()
{
		return 0;
}

Raylib::Vector2 Skeleton::get_position()
{
	return m_pos;
}

Raylib::Vector2 Skeleton::get_size()
{
	
	return m_size;

}

Raylib::Color Skeleton::get_color()
{
		return m_color;

}

Direction Skeleton::get_direction()
{
	return m_direction;
}

Skeleton::~Skeleton()
{
}


