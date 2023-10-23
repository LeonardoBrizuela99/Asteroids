#pragma once
#include"Game.h"
#include"raylib.h"
#include<iostream>
#include"Menu.h"

using namespace std;
/*static*/ void Update();
/*static*/ void Draw();
/*static*/ void DrawCredit();
void GameLoop();
void WindowInstructions();
void UpdateMenu();
void CreditsWindow();

const float SCREEN_WIDTH = 1024.0f;
const float SCREEN_HEIGTH = 768.0f;

namespace game
{
	void RunGame();
}