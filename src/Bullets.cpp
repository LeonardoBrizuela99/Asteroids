#include "Bullets.h"
#include"WindowSize.h"
#include"raymath.h"

void CreateBullets(Vector2 spawPositions, Bullet bullets [MaxBullets])
{
    Vector2 mousePosition = GetMousePosition();

    
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {

        for (int i = 0; i < MaxBullets; i++) {
            if (!bullets[i].active) {
                bullets[i].position = {spawPositions};
                bullets[i].velocity = Vector2Normalize({ mousePosition.x - spawPositions.x, mousePosition.y - spawPositions.y });
                bullets[i].velocity.x *= 500;
                bullets[i].velocity.y *= 500;
                bullets[i].radius = 5.0f;
                bullets[i].color = WHITE;
                bullets[i].active = true;
                break;
            }
        }
      
    }
}


void UpadateBullets(Bullet bullets[MaxBullets])
{
    for (int i = 0; i < MaxBullets; i++) {
        if (bullets[i].active) {
            bullets[i].position.x += bullets[i].velocity.x * GetFrameTime();
            bullets[i].position.y += bullets[i].velocity.y * GetFrameTime();


            if (bullets[i].position.x < 0 || bullets[i].position.x > SCREEN_WIDTH ||
                bullets[i].position.y < 0 || bullets[i].position.y > SCREEN_HEIGTH) {
                bullets[i].active = false;
            }
            else {

                DrawCircleV(bullets[i].position, bullets[i].radius, bullets[i].color);
            }
        }
    }
}
