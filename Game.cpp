#include"Game.h"
#include"raylib.h"
#include<iostream>

using namespace std;
static void Init();
static void MainLoop();
static void Close();
static void Update();
static void Draw();
static void DrawCredit();
static void GameLoop();

const float SCREEN_WIDTH =1024.0f ;
const float SCREEN_HEIGTH =700.0f ;

static bool exitWindow = false;
static bool pause = false;
static bool salir = false;

void game::RunGame()
{
	Init();
	MainLoop();
	Close();
}

static void Init()
{
	InitWindow(static_cast<int>(SCREEN_WIDTH), static_cast<int>(SCREEN_HEIGTH), "ASTEROIDS");
	SetExitKey(KEY_NULL);
}

static void MainLoop()
{
	while (!exitWindow)
	{
		while (!WindowShouldClose()&& !salir)
		{
			GameLoop();
			exitWindow = true;
		}
	}
}

static void Update()
{
	if (IsKeyPressed('p')|| IsKeyPressed(KEY_ESCAPE))
	{
		pause = !pause;
	}

}

static void Close()
{
	CloseWindow();
}

static void Draw()
{
	BeginDrawing();
	ClearBackground(RED);
	DrawRectangle(0, 0, 5, GetScreenHeight(), Fade(WHITE, 1.0f));
	DrawRectangle(GetScreenWidth() - 5, 0, 5, GetScreenHeight(), Fade(WHITE, 1.0f));
	if (pause)
	{
		DrawRectangleGradientV(GetScreenWidth() / 2 - 400, GetScreenHeight() / 2 - 300, 850, 600, BEIGE, Fade(RED, 1.0f));
		DrawText("Pause", GetScreenWidth() / 2 - 140, GetScreenHeight() / 2 - 250, 100, WHITE);
		DrawText("Press (P) (ESC) to continue the game ", GetScreenWidth() / 2 - 360, GetScreenHeight() / 2, 38, WHITE);
		DrawCredit();
	}
}
static void DrawCredit()
{
	DrawText(TextFormat("Credit: Leonardo Brizuela"), GetScreenWidth() / 2 - 300, GetScreenHeight() / 2 + 100, 40, WHITE);
}

static void GameLoop()
{
	if (IsKeyPressed(KEY_ESCAPE)) 
    {
		salir = true;

    }else
	{
	Update();
	}
	Draw();
}