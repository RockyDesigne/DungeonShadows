#pragma once

#include "Tile.h"

namespace Raylib {
#include <raylib.h>
}

using namespace Raylib;

class Floor final : public Tile
{
public:
	Floor(const Raylib::Vector2 pos, const Raylib::Vector2 size) : Tile(pos, size, Raylib::WHITE) { }
};
