#pragma once

#include <fstream>

#include "Tile.h"
#include "Torch.h"
#include "TileType.h"

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

	//gives player position in grid coords
	Raylib::Vector2 get_player_position(Vector2 player_size) const;

	void init();

	void draw();

	//tile position in grid coords
	Raylib::Vector2 get_tile_pos_in_grid(const Raylib::Vector2 size, const Raylib::Vector2 pos) const;

	//takes input position in grid coords
	//returns true if the position is in the map
	bool is_in_map(const Raylib::Vector2& pos) const;

	//takes as input position in grid coords
	//returns tile type
	TileType get_tile_type(const Raylib::Vector2& pos) const;

	//takes as input position in grid coords
	//returns a reference to the object
	std::shared_ptr<Tile> get_tile_object(const Raylib::Vector2& pos);
};
