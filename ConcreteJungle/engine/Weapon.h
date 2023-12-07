
#pragma once
typedef struct Weapon {
    char name[50];
    int damage[10];
    double speed[10];
    int size[10];
    int level;
} Weapon;



Weapon Pistol;


Weapon Mess;


Weapon Keyboard;


Weapon WaterCannon;


Weapon Dagger;



void InitialWeapons() {
    Pistol.name = "Pistol";
    Pistol.damage = { 2,4,6,8,10,12,16,26,32,38 };
    Pistol.speed = { 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 };
    Pistol.size = { 1,1,1,1,1,1,1,1,1,1 };
    Pistol.level = 1;

    Mess.name = "Mess";
    Mess.damage = { 1,2,3,4,5,10,28,33,38,44 };
    Mess.speed = { 1, 1, 1, 1, 1, 1, 1, 2, 2, 2 };
    Mess.size = { 2,2,2,2,2,2,2,2,2,2 };
    Mess.level = 1;
    
    Keyboard.name = "Keyboard";
    Keyboard.damage = { 8,12,16,20,25,30,35,40,48,56 };
    Keyboard.speed = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 2 };
    Keyboard.size = { 2,2,2,2,2,2,2,2,2,2 };
    Keyboard.level = 1;
    
    WaterCannon.name = "WaterCannon";
    WaterCannon.damage = { 1,3,4,6,8,10,12,20,25,30 };
    WaterCannon->speed = { 6, 6, 6, 6, 6, 6, 6, 8, 10, 12 };
    WaterCannon->size = { 2,2,2,2,4,4,4,4,4,4 };
    WaterCannon->level = 1;
    
    Dagger->name = "Dagger";
    Dagger->damage = { 12,16,20,24,28,32,36,40,44,48 };
    Dagger->speed = { 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 1, 1, 1.5 };
    Dagger->size = { 3,3,3,3,3, 3,3,3,3,3 };
    Dagger->level = 1;
}