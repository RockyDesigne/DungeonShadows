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

	constexpr static int map_width = 5;
	constexpr static int map_height = 5;

	char map[map_width][map_height] = {
	".##.",
	"#x..",
	".T##",
	".###",
	".###",
	};

	std::vector<std::shared_ptr<Tile>> m_tiles;

	Raylib::Vector2 get_player_position() const;

	void init();

	void draw();
};
