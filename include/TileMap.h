#pragma once

#include <fstream>

#include "Tile.h"
#include "Torch.h"

namespace Raylib {
#include <raylib.h>
}

using namespace Raylib;

#include <vector>
#include <memory>
#include <string>

class TileMap
{
public:

	//o mapa simpla de tiles

	/*
	* legenda:
	* # - tile pe care nu poti pasi
	* . - tile pe care poti pasi
	* x - player
	* A-Z - items
	*/

	int map_width{};
	int map_height{};

	std::vector<std::string> m_map;

	void load_map(const std::string& file_name);

	TileMap(Vector2 tile_size, Vector2 torch_size);

	Vector2 m_tile_size;
	Vector2 m_torch_size;

	std::vector<std::shared_ptr<Tile>> m_tiles;

	Raylib::Vector2 get_player_position(Vector2 player_size) const;

	void init();

	void draw();
};
