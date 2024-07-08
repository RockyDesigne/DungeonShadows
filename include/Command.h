#pragma once

#include "GameActor.h"

class Command
{
	public:

	virtual ~Command() = default;

	virtual void execute(GameActor& actor) = 0;
};

class MoveLeftCommand : public Command
{
	public:

	void execute(GameActor& actor) override
	{
		actor.set_direction_left();
		actor.move();
	}
};

class MoveRightCommand : public Command
{
	public:

	void execute(GameActor& actor) override
	{
		actor.set_direction_right();
		actor.move();
	}
};

class MoveUpCommand : public Command
{
	public:

	void execute(GameActor& actor) override
	{
		actor.set_direction_up();
		actor.move();
	}
};

class MouseLeftClickCommand : public Command
{
	public:

	void execute(GameActor& actor) override
	{
		actor.toggle_selected_item();
	}
};

class MoveDownCommand : public Command
{
	public:

	void execute(GameActor& actor) override
	{
		actor.set_direction_down();
		actor.move();
	}
};
