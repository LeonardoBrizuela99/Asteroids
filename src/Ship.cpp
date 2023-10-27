#include "Ship.h"
#include"raylib.h"
#include <cmath>

const float SCREEN_WIDTH = 1024.0f;
const float SCREEN_HEIGTH = 768.0f;
 SpaceShip CreateShip()
{
	SpaceShip ship;
	ship.x= static_cast<float> (GetScreenWidth() / 2), static_cast<float> (GetScreenHeight() / 2);
	ship.y = static_cast<float>(GetScreenWidth() / 2), static_cast<float> (GetScreenHeight() / 2);
	ship.radius = 20.0f;
	ship.color = BLUE;
	ship.vidas = 3;
	ship.velocity = { 0, 0 };
	ship.acceleration = 100.0f;
    ship.maxSpeed = 230.0f;
   
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
 

 void MoveShip(SpaceShip& ship)
 {
     Vector2 mousePosition = GetMousePosition();
     Vector2 direction = { mousePosition.x - ship.x, mousePosition.y - ship.y };
     float speed = sqrt(ship.velocity.x * ship.velocity.x + ship.velocity.y * ship.velocity.y);
     float scale = ship.maxSpeed / speed;
	 
     if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON))
     {
         float length = sqrt(direction.x * direction.x + direction.y * direction.y);
         direction.x /= length;
         direction.y /= length;
         ship.velocity.x += direction.x*ship.acceleration * GetFrameTime();
         ship.velocity.y += direction.y*ship.acceleration  * GetFrameTime();

     }   

     
     if (speed >= ship.maxSpeed)
     {
         
         ship.velocity.x *= scale;//*GetFrameTime();
             ship.velocity.y *= scale;//*GetFrameTime();
     }

         ship.x += ship.velocity.x * GetFrameTime();
         ship.y += ship.velocity.y * GetFrameTime(); 
         DrawLine(static_cast<int>(ship.x), static_cast<int>(ship.y), static_cast<int>(ship.x) + static_cast<int>(ship.velocity.x) * 10, static_cast<int>(ship.y)+ static_cast<int>(ship.velocity.y) * 10, WHITE);
 }
 
 void UpdateShip(SpaceShip& ship)
 {
	 MoveShip(ship);
     Wall(ship);
 }

 void Wall(SpaceShip& ship)
 {
     
         
         if (ship.x > SCREEN_WIDTH + ship.radius)
         {
             ship.x = -ship.radius; //  aparece en el lado izquierdo
         }
        
         else if (ship.x < -ship.radius)
         {
             ship.x = SCREEN_WIDTH + ship.radius; // aparece en el lado derecho
         }
        
         if (ship.y > SCREEN_HEIGTH + ship.radius)
         {
             ship.y = -ship.radius; // aparece en la parte superior
         }
         
         else if (ship.y < -ship.radius)
         {
             ship.y = SCREEN_HEIGTH + ship.radius; // aparece en la parte inferior
         }
     
 }