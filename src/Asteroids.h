#include"raylib.h"
#define MAX_BIG_METEORS 5
 struct Meteor {
    Vector2 position;
    Vector2 speed;
    float radius;
    bool active;
    Color color;
};

const int screenWidth = 1024;
const int screenHeigth = 768;

Meteor CreateMeteor();
void UpdateMeteor(Meteor&bigMeteor);
void DrawMeteor(Meteor bigMeteor);

