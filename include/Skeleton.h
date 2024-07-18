#pragma once

#include "GameActor.h"

class Skeleton : public GameActor
{
public:

	Raylib::Vector2 m_pos;
	Raylib::Vector2 m_tile_position;
	Raylib::Vector2 m_size;

	Raylib::Color m_color;

	float m_speed = 1.f;
	int health = 50;

	Skeleton(const Raylib::Vector2 pos, const Raylib::Vector2 size, const Raylib::Color color);
	void set_direction_left() override;
	void set_direction_right() override;
	void set_direction_up() override;
	void set_direction_down() override;
	void toggle_selected_item() override;
	void move() override;
	void draw() override;
	int get_health() override;
	void receive_damage(int damage) override;
	int get_damage() override;
	Raylib::Vector2 get_position() override;
	Raylib::Vector2 get_size() override;
	Raylib::Color get_color() override;
	Direction get_direction() override;
	~Skeleton() override;
private:
	int m_selected_item = 0;
	Direction m_direction;
};
