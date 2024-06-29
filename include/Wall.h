#pragma once

#include "Tile.h"

namespace Raylib {
#include <raylib.h>
}

using namespace Raylib;

class Wall final : public Tile
{
public:

	Wall(const Raylib::Vector2 pos, const Raylib::Vector2 size) : Tile(pos, size, Raylib::GRAY) { }

};
