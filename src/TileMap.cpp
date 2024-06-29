#include "TileMap.h"

#include "Wall.h"
#include "Floor.h"
#include "Torch.h"

Raylib::Vector2 TileMap::get_player_position() const
{
	Raylib::Vector2 player = {};
	for (int y = 0; y < map_height; y++)
	{
		for (int x = 0; x < map_width; x++)
		{
			if (map[y][x] == 'x')
			{
				player.x = static_cast<float>(x);
				player.y = static_cast<float>(y);
				break;
			}
		}
	}
	return player;
}

void TileMap::init()
{
	for (int y = 0; y < map_height; y++)
	{
		for (int x = 0; x < map_width; x++)
		{
			if (map[y][x] == '#')
			{
				auto tile = std::make_shared<Wall>(Raylib::Vector2{ static_cast<float>(x), static_cast<float>(y) },
				                                   Raylib::Vector2{ 20.f, 20.f });
				m_tiles.push_back(tile);
			}
			else if (map[y][x] == '.' || map[y][x] == 'x' || (map[y][x] >= 65 && map[y][x] <= 90))
			{
				auto tile = std::make_shared<Floor>(Raylib::Vector2{ static_cast<float>(x), static_cast<float>(y) },
				                                    Raylib::Vector2{ 20.f, 20.f });

				if (map[y][x] >= 65 && map[y][x] <= 90)
				{
					tile->set_item(std::make_shared<Torch>(Raylib::Vector2{ static_cast<float>(x), static_cast<float>(y) },
					                                       Raylib::Vector2{ 20.f, 20.f }, Raylib::YELLOW));
				}
				m_tiles.push_back(tile);
			}
		}
	}
}

void TileMap::draw()
{
	for (const auto& tile : m_tiles)
	{
		tile->draw();
	}
}
