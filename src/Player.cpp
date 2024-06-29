#include "Player.h"

Player::Player(const Raylib::Vector2 pos, const Raylib::Vector2 size, const Raylib::Color color):
	m_position(pos), m_size(size), m_color(color)
{
}

void Player::draw_player()
{
	DrawRectangleV({ m_position.x * m_size.x,m_position.y * m_size.y }, m_size, m_color);
}

void Player::handle_input()
{
	if (Raylib::IsKeyDown(Raylib::KEY_RIGHT)) m_position.x += m_speed;
	if (Raylib::IsKeyDown(Raylib::KEY_LEFT))  m_position.x -= m_speed;
	if (Raylib::IsKeyDown(Raylib::KEY_UP))    m_position.y -= m_speed;
	if (Raylib::IsKeyDown(Raylib::KEY_DOWN))  m_position.y += m_speed;
}
