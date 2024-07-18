#pragma once

#include "Actions.h"
#include "GameActor.h"
#include "AnimationActions.h"

#include <vector>

class ActionHandler
{
public:
	void handle_action(Actions action, GameActor& actor);
private:
	void sword_slash(GameActor& actor);
	void torch_toggle(GameActor& actor);
};
