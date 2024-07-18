#include "Player.h"

#include <string>

Player::Player(const Raylib::Vector2 pos, const Raylib::Vector2 size, const Raylib::Color color):
	m_position(pos), m_size(size), m_color(color)
{
}

void Player::set_direction_down()
{
	m_direction = Direction::DOWN;
}

std::shared_ptr<IItem> Player::get_selected_item()
{
	if (m_items.empty())
	{
		return nullptr;
	}

	if (m_selected_item < 0 || m_selected_item >= m_items.size())
	{
		std::string msg = "selected item index out of bounds: ";
		msg += "selected item is: " + std::to_string(m_selected_item);
		msg += " and the size of the items vector is: " + std::to_string(m_items.size());

		throw std::exception(msg.data());
	}

	return m_items[m_selected_item];
}

void Player::toggle_selected_item()
{
	auto item = get_selected_item();
	if (item)
	{
		m_actions.push(item->action());
	}
}

void Player::receive_damage(int damage)
{
	if (health > 0)
	{
		health -= damage;
	}
}

int Player::get_damage()
{
	return get_selected_item()->damage();
}

int Player::get_health()
{
	return health;
}

Raylib::Vector2 Player::get_position()
{
	return m_position;
}

Raylib::Vector2 Player::get_size()
{
	return m_size;
}

Raylib::Color Player::get_color()
{
	return m_color;
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

void Player::draw()
{
	DrawRectangleV(m_position, m_size, m_color);
}
