#include "Player.h"

Player::Player(const Raylib::Vector2 pos, const Raylib::Vector2 size, const Raylib::Color color):
	m_position(pos), m_size(size), m_color(color)
{
}

void Player::set_direction_down()
{
	m_direction = Direction::DOWN;
}

void Player::set_direction_left()
{
	m_direction = Direction::LEFT;
}

void Player::set_direction_right()
{
	m_direction = Direction::RIGHT;
}

void Player::set_direction_up()
{
	m_direction = Direction::UP;
}

Direction Player::get_direction()
{
	return m_direction;
}

void Player::move()
{
	switch (m_direction)
	{
		case Direction::UP:
			m_position.y -= m_speed;
			break;
		case Direction::DOWN:
			m_position.y += m_speed;
			break;
		case Direction::LEFT:
			m_position.x -= m_speed;
			break;
		case Direction::RIGHT:
			m_position.x += m_speed;
			break;
	}
}

void Player::draw_player()
{
	DrawRectangleV(m_position, m_size, m_color);
}
