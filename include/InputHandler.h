#pragma once

#include "Command.h"

namespace Raylib
{
#include <raylib.h>
}

using namespace Raylib;

class InputHandler
{
public:

	InputHandler(Command* button_w, Command* button_a, Command* button_s, Command* button_d)
		: m_button_w(button_w), m_button_a(button_a), m_button_s(button_s), m_button_d(button_d)
	{}

	Command* handle_input()
	{
		if (IsKeyDown(KEY_W))
		{
			return m_button_w;
		}
		if (IsKeyDown(KEY_A))
		{
			return m_button_a;
		}
		if (IsKeyDown(KEY_S))
		{
			return m_button_s;
		}
		if (IsKeyDown(KEY_D))
		{
			return m_button_d;
		}

		return nullptr;
	}
private:
	Command* m_button_w;
	Command* m_button_a;
	Command* m_button_s;
	Command* m_button_d;
};
