#include <string.h>
#include "Weapon.h"

typedef struct Coordinates {
    int x;
    int y;
} Coordinates;

typedef struct Character {
    int health;
    Weapon weaponList[5];
    char name[20];
    Coordinates position;  // ÁÂÇ¥ Ãß°¡
} Character;

void initializeCharacter(Character* character, int health,  const char* name, int x, int y,Weapon deaultWeapon) {
    character->health = health;
    strcpy(character->name, name);
    character->position.x = x;
    character->position.y = y;
    character->weaponList[0] = deaultWeapon;
}