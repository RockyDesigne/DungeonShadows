// TestGame.cpp : Defines the entry point for the application.
//

#include "TestGame.h"

namespace Raylib {
#include "raylib.h"
}

using namespace Raylib; // ar fi chill sa il bagam intr-un namespace pt a evita naming conflicts

constexpr int screenWidth = 800;
constexpr int screenHeight = 800;

//un exemplu 
class Player
{
public:
	int m_x; //m_* pentru membrii de clasa
	int m_y;

	int m_size;

	Color m_color;

	void draw_player()
	{
		DrawRectangle(m_x,
			m_y,
			m_size,
			m_size,
			m_color);
	}

	void handle_input()
	{
		if (IsKeyDown(KEY_RIGHT)) m_x += 2;
		if (IsKeyDown(KEY_LEFT)) m_x -= 2;
		if (IsKeyDown(KEY_UP)) m_y -= 2;
		if (IsKeyDown(KEY_DOWN)) m_y += 2;
	}

};

//o mapa simpla de tiles

/*
 * legenda:
 * # - tile pe care nu poti pasi
 * . - tile pe care poti pasi
 * x - player
 */

char map[5][5] = {
	".##.",
	"#x..",
	"..##",
	".###",
	".###",
};

int main()
{
	//functia asta trebuie apelata mereu la inceput
	InitWindow(screenWidth, screenHeight, "TestGame"); //idk ne trebuie un nume

	SetWindowState(FLAG_VSYNC_HINT); //aici putem avea niste flags pt a seta chestii despre windo

	ClearBackground(Raylib::BLACK);

	Player player{ screenWidth / 2,
			screenHeight / 2,
			10,
			Raylib::RED };

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (map[i][j] == 'x')
			{
				player.m_x = j * 20;
				player.m_y = i * 20;
				break;
			}
		}
	} //initialize player pos

	SetTargetFPS(60); 

	Camera2D camera = { };
	camera.target = { static_cast<float>(player.m_x) + 20,
		static_cast<float>(player.m_y) + 20 };
	camera.offset = { static_cast<float>(screenWidth) / 2,
		static_cast<float>(screenHeight) / 2 };
	camera.rotation = 0.0f;
	camera.zoom = 1.0f;

	while (!WindowShouldClose())
	{
		player.handle_input();
		camera.target = { static_cast<float>(player.m_x) + 20,
		static_cast<float>(player.m_y) + 20 }; //camera urmareste playerul

		// Camera zoom controls
		camera.zoom += ((float)GetMouseWheelMove() * 0.05f);

		//limitam zoomul
		if (camera.zoom > 3.0f) camera.zoom = 3.0f;
		else if (camera.zoom < 0.1f) camera.zoom = 0.1f;

		BeginDrawing(); //tot ce este intre astea doua se intampla de 60 de ori pe secunda
			ClearBackground(Raylib::BLACK); //trb every frame

			BeginMode2D(camera);

				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						if (map[i][j] == '#')
						{
							DrawRectangle(j * 20, i * 20, 20, 20, Raylib::GRAY);
						}
						else if (map[i][j] == '.')
						{
							DrawRectangle(j * 20, i * 20, 20, 20, Raylib::WHITE);
						}
					}
				}

				player.draw_player();

			EndMode2D();

		EndDrawing();
			
	}

	CloseWindow();

	return 0;
}
