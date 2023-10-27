#include"Game.h"
#include"raylib.h"
#include<iostream>
#include"Menu.h"

using namespace std;

static void Init();
static void MainLoop();
static void Close();
 void Update();
 void DrawPause();
/*static void Draw();
static void DrawCredit();
void GameLoop();
void WindowInstructions();
void UpdateMenu();
void CreditsWindow();
void InitializTexts();*/

 SpaceShip ship;
 

/*static*/ bool exitWindow = false;
/*static*/ bool pause = false;
/*static*/ bool salir = false;

namespace game
{
	void RunGame()
	{
		Init();
		MainLoop();
		Close();
	}
}

static void Init()
{
	InitWindow(static_cast<int>(SCREEN_WIDTH), static_cast<int>(SCREEN_HEIGTH), "ASTEROIDS");
	SetExitKey(KEY_NULL);
	InitializeTexts();
	ship = CreateShip();
}

/*static*/ void MainLoop()
{
	while (!exitWindow)
	{
		while (!WindowShouldClose()&& !salir)
		{
			ScenesSwitch();
			exitWindow = true;
		}
	}
}

void Update()
{
	/*if (IsKeyPressed(KEY_P) || IsKeyPressed(KEY_ESCAPE))
	{
		pause = !pause;
	}

	if (!pause)*/
	//{
		UpdateShip(ship);
	//}
}

/*static*/ void Close()
{
	CloseWindow();
}

/*static*/ void Draw()
{
	BeginDrawing();
	ClearBackground(RED);
	DrawRectangle(0, 0, 5, GetScreenHeight(), Fade(WHITE, 1.0f));
	DrawRectangle(GetScreenWidth() - 5, 0, 5, GetScreenHeight(), Fade(WHITE, 1.0f));

	if (pause)
	{
		DrawPause();
	}
	else
	{
		DrawShip(ship);
	}
	
	EndDrawing();
}
/*static*/ void DrawCredit()
{
	DrawText(TextFormat("Credit: Leonardo Brizuela"), GetScreenWidth() / 2 - 300, GetScreenHeight() / 2 + 100, 40, WHITE);
}

/*static*/ void GameLoop()
{
	if (IsKeyPressed(KEY_ESCAPE)||IsKeyPressed(KEY_P))
	{
		pause = !pause;
		cout << "pause" << endl;
		cout << pause << endl;
		//DrawPause();
	}

	if (!pause)
	{
		Update();
	}
	else
	{	
		DrawPause();
		
		if (IsKeyPressed(KEY_R))
		{
			ship = CreateShip();  
			pause = false; 
			cout << "restart" << endl;
			cout << pause << endl;
		}
		else if (IsKeyPressed(KEY_ESCAPE))
		{
			ship = CreateShip();
			
			menu = MenuScenes::MainMenu;  
			pause = false;               
			cout << pause << endl;
		}
	}

	Draw();
}

void WindowInstructions()
{
	BeginDrawing();

	DrawRectangleGradientV(GetScreenWidth() / 2 - 512, GetScreenHeight() / 2 - 384, 1024, 768, BEIGE, Fade(RED, 1.0f));
	DrawText("Use Up/Down to move rigth paddles", GetScreenWidth() / 2 - 350, GetScreenHeight() / 2 - 10, 40, WHITE);
	DrawText("Use W/S to move left paddles", GetScreenWidth() / 2 - 300, GetScreenHeight() / 2 - 100, 40, WHITE);
	//DrawText("(ESC) Back", GetScreenWidth() / 2 - 350, GetScreenHeight() / 2 + 200, 40, WHITE);
	
	DrawBack();
	CheckBack();
	EndDrawing();

	backMenu();
}

 void UpdateMenu()
{
	 CheckSinglePlayer();
	 CheckInstructions();
	 CheckCredits();
	 CheckBack();
	 CheckQuit();
}

 void CreditsWindow()
{
	BeginDrawing();

	DrawRectangleGradientV(GetScreenWidth() / 2 - 512, GetScreenHeight() / 2 - 384, 1024, 768, BEIGE, Fade(RED, 1.0f));
	DrawText("Code by: Leonardo Brizuela", GetScreenWidth() / 2 - 300, GetScreenHeight() / 2 - 10, 40, WHITE);
	//DrawText("(ESC) Back", GetScreenWidth() / 2 - 350, GetScreenHeight() / 2 + 200, 40, WHITE);
	DrawBack();
	CheckBack();
	EndDrawing();
	backMenu();
	
	
}

void backMenu()
{
	if (IsKeyPressed(KEY_ESCAPE))
	{
		menu = MenuScenes::MainMenu;
	}
}

void DrawPause()
{
	BeginDrawing();
	
		DrawRectangleGradientV(GetScreenWidth() / 2 - 512, GetScreenHeight() / 2 - 384, 1024, 768, BEIGE, Fade(RED, 1.0f));
		DrawText("Pause", GetScreenWidth() / 2 - 140, GetScreenHeight() / 2 - 250, 100, WHITE);
		DrawText("Press (P) to continue the game ", GetScreenWidth() / 2 - 330, GetScreenHeight() / 2, 38, WHITE);
		DrawText("Press (R) to restart the game ", GetScreenWidth() / 2 - 330, GetScreenHeight() / 2-100, 38, WHITE);
		DrawText("Press (ESC) back to menu ", GetScreenWidth() / 2 - 330, GetScreenHeight() / 2-50, 38, WHITE);
		DrawBack();
		DrawCredit();
	
	EndDrawing();
}

void ButtomPause()
{
	
	
}