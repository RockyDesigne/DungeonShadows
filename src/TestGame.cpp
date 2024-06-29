// TestGame.cpp : Defines the entry point for the application.
//

#include "TestGame.h"
#include "IItem.h"
#include "Player.h"
#include "Tile.h"
#include "TileMap.h"

namespace Raylib {
#include <raylib.h>
#include <raymath.h>
}

using namespace Raylib; // ar fi chill sa il bagam intr-un namespace pt a evita naming conflicts

#include <vector>
#include <memory>

constexpr int screenWidth = 800;
constexpr int screenHeight = 800;

bool check_if_player_on_tile(std::shared_ptr<Tile> tile, const Player& player)
{
	auto item = tile->get_item();
	if (item == nullptr)
	{
		return false;
	}

	Vector2 item_pos = item->get_position();

	//a hack, we should get the item size from the item itself
	//rn, I know the item size is 4 times smaller than the tile size
	Rectangle item_rec = { item_pos.x, item_pos.y, tile->get_size().x/4.f, tile->get_size().y / 4.f };

	return CheckCollisionPointRec(player.m_position, item_rec);
	
}

int main()
{
	//functia asta trebuie apelata mereu la inceput
	InitWindow(screenWidth, screenHeight, "TestGame"); //idk ne trebuie un nume

	SetWindowState(FLAG_VSYNC_HINT); //aici putem avea niste flags pt a seta chestii despre windo

	ClearBackground(Raylib::BLACK);

	TileMap tile_map;

	tile_map.init();

	Player player{{},{20.f,20.f},Raylib::RED};

	player.m_position = tile_map.get_player_position();

	SetTargetFPS(60); 

	Camera2D camera = { };
	camera.target = { player.m_position };
	camera.offset = { static_cast<float>(screenWidth) / 2,
		static_cast<float>(screenHeight) / 2 };
	camera.rotation = 0.0f;
	camera.zoom = 1.0f;

	while (!WindowShouldClose())
	{
		player.handle_input();
		camera.target = { player.m_position }; //camera urmareste playerul

		// Camera zoom controls
		camera.zoom += (GetMouseWheelMove() * 0.05f);

		//limitam zoomul
		if (camera.zoom > 3.0f) camera.zoom = 3.0f;
		else if (camera.zoom < 0.1f) camera.zoom = 0.1f;

		for (const auto& tile : tile_map.m_tiles)
		{
			if (check_if_player_on_tile(tile, player))
			{
				player.m_items.push_back(tile->get_item());
				tile->remove_item();
			}
		}

		BeginDrawing(); //tot ce este intre astea doua se intampla de 60 de ori pe secunda
			ClearBackground(Raylib::BLACK); //trb every frame

			BeginMode2D(camera);

				tile_map.draw();

				player.draw_player();

			EndMode2D();

		EndDrawing();
			
	}

	CloseWindow();

	return 0;
}
