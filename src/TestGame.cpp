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

bool check_if_player_on_item(const std::shared_ptr<Tile> tile, const Player& player)
{
	auto item = tile->get_item();
	if (item == nullptr)
	{
		return false;
	}

	// Use the actual item size for the bounding box
	Vector2 item_pos = item->get_position();
	Vector2 item_size = item->get_size(); // Assuming get_size() is implemented

	Rectangle item_rec = { item_pos.x, item_pos.y, item_size.x, item_size.y };

	// Adjust player's bounding box to be centered
	Rectangle player_rec = {
		player.m_position.x,
		player.m_position.y,
		player.m_size.x,
		player.m_size.y
	};

	return CheckCollisionRecs(player_rec, item_rec);
	
}

bool within_map(Rectangle obj, float map_width, float map_height, float tile_size) {
	// Calculate the total map size in pixels
	float mapWidthInPixels = (map_width -1)* tile_size;
	float mapHeightInPixels = (map_height) * tile_size;

	return (obj.x >= 0 && 
			obj.x + obj.width < mapWidthInPixels &&
			obj.y >= 0 && 
			obj.y + obj.height < mapHeightInPixels);
	
}

bool is_player_on_wall(const Player& player, const std::shared_ptr<Tile> tile)
{
	const Rectangle player_rec = {
		player.m_position.x,
		player.m_position.y,
		player.m_size.x,
		player.m_size.y
	};

	const Rectangle tile_rec = {
		tile->get_position().x,
		tile->get_position().y,
		tile->get_size().x,
		tile->get_size().y
	};

	return CheckCollisionRecs(player_rec, tile_rec);
}

// Function to check if a position is within bounds and is a walkable tile

bool is_same_color(const Color& c1, const Color& c2)
{
	return (c1.a == c2.a &&
			c1.b == c2.b &&
			c1.r == c2.r &&
			c1.g == c2.g);
}

bool can_step(const Player& player, const TileMap& tile_map)
{
	Rectangle player_rec = {
		player.m_position.x,
		player.m_position.y,
		player.m_size.x,
		player.m_size.y
	};

	if (!within_map(player_rec, tile_map.map_width, tile_map.map_height, tile_map.m_tile_size.x))
	{
		return false;
	}

	for (const auto& tile : tile_map.m_tiles)
	{
		if (is_same_color(tile->get_color(), Raylib::GRAY))
		{
			if (is_player_on_wall(player, tile))
			{
				return false;
			}
		}
	}

	return true;
}

int main()
{
	//functia asta trebuie apelata mereu la inceput
	InitWindow(screenWidth, screenHeight, "TestGame"); //idk ne trebuie un nume

	SetWindowState(FLAG_VSYNC_HINT); //aici putem avea niste flags pt a seta chestii despre windo

	ClearBackground(Raylib::BLACK);

	TileMap tile_map { {20.f,20.f}, {5.f,5.f} };

	tile_map.init();

	Player player{{},{15.f,15.f},Raylib::RED};

	player.m_position = tile_map.get_player_position(player.m_size);

	SetTargetFPS(60); 

	Camera2D camera = { };
	camera.target = { player.m_position };
	camera.offset = { static_cast<float>(screenWidth) / 2,
		static_cast<float>(screenHeight) / 2 };
	camera.rotation = 0.0f;
	camera.zoom = 3.0f;

	while (!WindowShouldClose())
	{
		auto prev_pos = player.m_position;

		player.handle_input();
		
		if (!can_step(player, tile_map))
		{
			player.m_position = prev_pos;
		}

		camera.target = { player.m_position }; //camera urmareste playerul

		// Camera zoom controls
		camera.zoom += (GetMouseWheelMove() * 0.05f);

		//limitam zoomul
		if (camera.zoom > 3.0f) camera.zoom = 3.0f;
		else if (camera.zoom < 0.1f) camera.zoom = 0.1f;

		//pickup items
		for (const auto& tile : tile_map.m_tiles)
		{
				if (check_if_player_on_item(tile, player))
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
