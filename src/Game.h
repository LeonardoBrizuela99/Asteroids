#pragma once
#include"Game.h"
#include"raylib.h"
#include<iostream>
#include"Menu.h"
#include"Ship.h"
#include"WindowSize.h"

using namespace std;
/*static*/ void Update();
/*static*/ void Draw();
/*static*/ void DrawCredit();
void GameLoop();
void WindowInstructions();
void UpdateMenu();
void CreditsWindow();
void backMenu();



namespace game
{
	void RunGame();
}