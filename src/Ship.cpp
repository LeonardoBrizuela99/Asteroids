#include "Ship.h"
#include"raylib.h"

 SpaceShip CreateShip()
{
	SpaceShip ship;
	ship.x= static_cast<float> (GetScreenWidth() / 2), static_cast<float> (GetScreenHeight() / 2);
	ship.y = static_cast<float>(GetScreenWidth() / 2), static_cast<float> (GetScreenHeight() / 2);
	ship.radius = 20.0f;
	ship.color = BLUE;
	ship.vidas = 3;
	return ship;

}

 Circle GetCircle(SpaceShip& ship)
{
	return Circle{ ship.x,ship.y, ship.radius };
}
 
 void DrawShip(SpaceShip& ship)
 {
	 DrawCircleV({ ship.x,ship.y },ship.radius, ship.color);
 }
 
 void UpdateShip(SpaceShip& ship)
 {
	 MoveShip(ship);
 }

 void MoveShip(SpaceShip& ship)
 {
	 ship.x += ship.x * GetFrameTime();
	 ship.y += ship.y * GetFrameTime();
 }
