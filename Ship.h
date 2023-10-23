#include "raylib.h"

struct Circle
{
    Vector2 position;
    float radius;
    Color color;
};

struct SpaceShip
{
    Circle circle;
    int vidas;
};

SpaceShip InitShip();
Circle GetCircle(SpaceShip& ship);