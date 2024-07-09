#include "TileMap.h"

#include "Wall.h"
#include "Floor.h"
#include "Sword.h"
#include "Torch.h"

TileMap::TileMap(Vector2 tile_size, Vector2 torch_size) :
m_tile_size(tile_size), m_torch_size(torch_size)
{}

void TileMap::load_map(const std::string& file_name)
{
	m_map.clear();

	std::ifstream fin{ file_name };

	if (!fin.is_open())
	{
		const std::string msg = "Could not open file: " + file_name;
		throw std::exception(msg.data());
	}

	for (std::string line; std::getline(fin,line);)
	{
		m_map.emplace_back(line);
	}

	fin.close();

	map_height = static_cast<int>(m_map.size());
	map_width = static_cast<int>(m_map[0].size());

}


Raylib::Vector2 TileMap::get_player_position(Vector2 player_size) const
{
	Raylib::Vector2 player_pos = {};
	// Assuming a tile size of 20x20 as per your init method
	const float tileSize = 20.0f;

	for (int y = 0; y < map_height; y++)
	{
		for (int x = 0; x < map_width; x++)
		{
			if (m_map[y][x] == 'x')
			{
				// Calculate the center position for the player within the tile
				player_pos.x = static_cast<float>(x) * tileSize + (tileSize - player_size.x) / 2;
				player_pos.y = static_cast<float>(y) * tileSize + (tileSize - player_size.y) / 2;
				break;
			}
		}
	}
	return player_pos;
}

void TileMap::init()
{
	m_tiles.clear();

	for (int y = 0; y < map_height; y++)
	{
		for (int x = 0; x < map_width; x++)
		{
			if (m_map[y][x] == '#')
			{
				auto tile = std::make_shared<Wall>(
					Raylib::Vector2{ static_cast<float>(x) * m_tile_size.x, 
					static_cast<float>(y) * m_tile_size.y},
					m_tile_size);
				m_tiles.push_back(tile);
			}
			else if (m_map[y][x] == '.' || m_map[y][x] == 'x' || (m_map[y][x] >= 65 && m_map[y][x] <= 90))
			{
				auto tile = std::make_shared<Floor>(
					Raylib::Vector2{ static_cast<float>(x) * m_tile_size.x,
						static_cast<float>(y) * m_tile_size.y},
				                                    m_tile_size);

				Raylib::Vector2 itemPosition = {
						static_cast<float>(x) * m_tile_size.x + (m_tile_size.x - m_torch_size.x) / 2,
						static_cast<float>(y) * m_tile_size.y + (m_tile_size.y - m_torch_size.y) / 2
				};

				switch (m_map[y][x])
				{
				case 'T':
				{
						tile->set_item(std::make_shared<Torch>(itemPosition, m_torch_size, Raylib::YELLOW));
				} break;
				case 'S':
				{
						tile->set_item(std::make_shared<Sword>(itemPosition, m_torch_size, Raylib::PINK));
				}break;
				}
				m_tiles.push_back(tile);
			}
		}
	}
}

void TileMap::draw()
{


	for (int y = 0; y < map_height; y++)
	{
		for (int x = 0; x < map_width; x++)
		{
			m_tiles[y * map_width + x]->draw();
		}
	}

	/*
	for (const auto& tile : m_tiles)
	{
		tile->draw();
	}
	*/
}

//gives the position of the tile in the grid
Raylib::Vector2 TileMap::get_tile_pos_in_grid(const Raylib::Vector2 size, const Raylib::Vector2 pos) const
{
	//calculate the center of the entity

	Raylib::Vector2 center = { pos.x + size.x / 2, pos.y + size.y / 2 };

	return { std::floor(center.x / m_tile_size.x), std::floor(center.y / m_tile_size.y)};
}

bool TileMap::is_in_map(const Raylib::Vector2& pos) const
{
	return (pos.x >= 0 && pos.x < map_width && pos.y >= 0 && pos.y < map_height);
}

TileType TileMap::get_tile_type(const Raylib::Vector2& pos) const
{
	switch (m_map[static_cast<int>(pos.y)][static_cast<int>(pos.x)])
	{
		case '#':
			return TileType::WALL;
		default:
			return TileType::FLOOR;
	}
}

std::shared_ptr<Tile> TileMap::get_tile_object(const Raylib::Vector2& pos)
{
	//should never happen
	if (m_tiles.empty())
	{
		throw std::exception("No tiles in the map");
	}
	if (static_cast<int>(pos.y) * map_width + static_cast<int>(pos.x) >= m_tiles.size())
	{
		throw std::exception("Position out of map bounds");
	}
	return m_tiles[static_cast<int>(pos.y) * map_width + static_cast<int>(pos.x)];
}
