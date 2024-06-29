#pragma once

namespace Raylib
{
#include <raylib.h>	
}

using namespace Raylib;

//items interface
class IItem
{
public:
	virtual void action() = 0;
	virtual void draw() = 0;
	virtual Raylib::Vector2 get_position() = 0;
	virtual ~IItem() = default;
};
