#include "Ship.h"
#include"raylib.h"

 SpaceShip InitShip()
{
	SpaceShip ship;
	ship.circle.position.x = GetScreenWidth() / 2, GetScreenHeight() / 2;
	ship.circle.position.y = GetScreenWidth() / 2, GetScreenHeight() / 2;
	ship.circle.radius = 20.0f;
	ship.circle.color = RED;
	ship.vidas = 3;
	return ship;

}

 Circle GetCircle(SpaceShip& ship)
{
	return Circle{ ship.circle.position.x,ship.circle.position.y, ship.circle.radius,ship.circle.color };
}
