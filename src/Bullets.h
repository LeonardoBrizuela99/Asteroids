#include"raylib.h"

struct Bullet {
    Vector2 position;
    Vector2 velocity;
    float radius;
    Color color;
    bool active;
};
const int MaxBullets = 100;
void UpadateBullets(Bullet bullets[MaxBullets]);
void CreateBullets(Vector2 spawPositions, Bullet bullets[MaxBullets]);

