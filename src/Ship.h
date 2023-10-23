#include "raylib.h"

struct Circle
{
    Vector2 position;
    float radius;
};

struct SpaceShip
{
    float x;
    float y;
    float radius; 
    int vidas;
    Color color;
};

SpaceShip CreateShip();
Circle GetCircle(SpaceShip& ship);
void DrawShip(SpaceShip& ship);
void UpdateShip(SpaceShip& ship);
void MoveShip(SpaceShip& ship);
