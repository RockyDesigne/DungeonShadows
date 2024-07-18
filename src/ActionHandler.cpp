#include "ActionHandler.h"
#include "Direction.h"
#include <exception>

void ActionHandler::handle_action(Actions action, GameActor& actor)
{
	switch (action)
	{
	case Actions::TORCH_TOGGLE:
		//toggle torch
		break;
	case Actions::SWORD_ATTACK:
		{
		sword_slash(actor);
		} break;
	default:
		throw std::exception("Unhandled action!");
	}
}

void ActionHandler::sword_slash(GameActor& actor)
{
    //defaults
    auto default_sword_color = Raylib::PINK;
    Raylib::Vector2 sword_size = { 10, 10 };

    auto pos = actor.get_position();
    auto size = actor.get_size();

    Raylib::Vector2 sword_pos;
    switch (actor.get_direction())
    {
    case Direction::UP:
        sword_pos = { pos.x + size.x/2 - sword_size.x/2, pos.y - sword_size.y };
        break;
    case Direction::DOWN:
        sword_pos = { pos.x + size.x / 2 - sword_size.x / 2, pos.y + size.y };
        break;
    case Direction::LEFT:
        sword_pos = { pos.x - sword_size.x, pos.y + size.y / 2 - sword_size.y / 2 };
        break;
    case Direction::RIGHT:
        sword_pos = { pos.x + size.x, pos.y + size.y / 2 - sword_size.y / 2 };
        break;
    }

    DrawRectangleV(sword_pos, sword_size, default_sword_color);
}


void ActionHandler::torch_toggle(GameActor& actor)
{
	throw std::exception("Not implemented!");
}
