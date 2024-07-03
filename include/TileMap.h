#pragma once

#include "Tile.h"
#include "Torch.h"

namespace Raylib {
#include <raylib.h>
}

using namespace Raylib;

#include <vector>
#include <memory>

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

	constexpr static int map_width = 9;
	constexpr static int map_height = 10;

	char map[map_height][map_width] = {
	"###..###",
	"#x...###",
	"#T##.###",
	"####.###",
	"####.###",
	"####.###",
	"####.###",
	"####.###",
	"####.###",
	"####.###",
	};

	TileMap(Vector2 tile_size, Vector2 torch_size);

	Vector2 m_tile_size;
	Vector2 m_torch_size;

	std::vector<std::shared_ptr<Tile>> m_tiles;

	Raylib::Vector2 get_player_position(Vector2 player_size) const;

	void init();

	void draw();
};
