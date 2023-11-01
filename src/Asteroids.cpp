#include "Asteroids.h"
#include "raylib.h"
#include <iostream>


//using namespace std;

Meteor CreateMeteor()
{
    meteorCount = MAX_BIG_METEORS;

    int meteorSpeed = 150;

    // Inicialización de asteroides grandes
    for (int i = 0; i < MAX_BIG_METEORS; i++) {
        int posx, posy;
        bool correctRange = false;
        posx = GetRandomValue(0, screenWidth);
        while (!correctRange) {
            if (posx > screenWidth / 2 - 150 && posx < screenWidth / 2 + 150)
                posx = GetRandomValue(0, screenWidth);
            else
                correctRange = true;
        }
        correctRange = false;
        posy = GetRandomValue(0, screenHeigth);
        while (!correctRange) {
            if (posy > screenHeigth / 2 - 150 && posy < screenHeigth / 2 + 150)
                posy = GetRandomValue(0, screenHeigth);
            else
                correctRange = true;
        }
        bigMeteor[i].position = { (float)posx, (float)posy };
        bigMeteor[i].speed = { (float)meteorSpeed, (float)meteorSpeed };
        if (GetRandomValue(0, 1) == 0) {
            bigMeteor[i].speed.x *= -1;
        }
        if (GetRandomValue(0, 1) == 0) {
            bigMeteor[i].speed.y *= -1;
        }
        bigMeteor[i].radius = 40;
        bigMeteor[i].active = true;
        bigMeteor[i].color = BLUE;
    }
}

void UpdateMeteor(Meteor& bigMeteor)
{
    // Mueve los asteroides grandes según el tiempo transcurrido
    for (int i = 0; i < meteorCount; i++)
    {
        if (bigMeteor[i].active)
        {
            // Actualiza la posición de los asteroides en función de la velocidad y el tiempo de cuadro
            bigMeteor[i].position.x += bigMeteor[i].speed.x * GetFrameTime();
            bigMeteor[i].position.y += bigMeteor[i].speed.y * GetFrameTime();

            // Aplica la lógica de movimiento suave al reaparecer en el lado opuesto
            if (bigMeteor[i].position.x > screenWidth + bigMeteor[i].radius) bigMeteor[i].position.x = -(bigMeteor[i].radius);
            else if (bigMeteor[i].position.x < 0 - bigMeteor[i].radius) bigMeteor[i].position.x = screenWidth + bigMeteor[i].radius;
            if (bigMeteor[i].position.y > screenHeigth + bigMeteor[i].radius) bigMeteor[i].position.y = -(bigMeteor[i].radius);
            else if (bigMeteor[i].position.y < 0 - bigMeteor[i].radius) bigMeteor[i].position.y = screenHeigth + bigMeteor[i].radius;
        }
    }
}

void DrawMeteor(Meteor bigMeteor)
{
    for (int i = 0; i < meteorCount; i++) {
        if (bigMeteor[i].active) {
            DrawCircleV(bigMeteor[i].position, bigMeteor[i].radius, bigMeteor[i].color);
        }
    }
}
