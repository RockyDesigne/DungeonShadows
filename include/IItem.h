#pragma once

#include "Actions.h"

namespace Raylib
{
#include <raylib.h>	
}

using namespace Raylib;

//items interface
class IItem
{
public:
	virtual Actions action() = 0;
	virtual void draw() = 0;
	virtual int damage() = 0;
	virtual Raylib::Vector2 get_size() = 0;
	virtual Raylib::Vector2 get_position() = 0;
	virtual ~IItem() = default;
};
