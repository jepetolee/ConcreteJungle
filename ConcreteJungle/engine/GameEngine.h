#pragma once

#include "Weapon.h"
#include "Character.h"
#include <conio.h>


Character SelectedCharacter;


int levelupCounter = 1;


void GameEngine() {
    Character Businessman, Doctor, Influencer, Firefighter;

    initializeCharacter(&Businessman, 20,  "Businessman", 960, 540, Pistol);
    initializeCharacter(&Doctor, 25, "Doctor", 960, 540, Mess);
    initializeCharacter(&Influencer, 15, "Ralo", 960, 540, Keyboard);
    initializeCharacter(&Firefighter, 35, "Firefighter", 960, 540, WaterCannon);

    
    printf("��ũ��Ʈ ���� ���� ���� (v: 0.1.0)\n");
    printf("���Ͻô� ����� �Է����ּ���.");

    while (1) {
        if (SelectedCharacter->health == 0) {
          
            levelupCounter = 1;
            //load_finished;
        }
        if (character->experience / 100 > levelupCounter) {
        
            levelupCounter++;
            //show item settings
        }
        for (int i = 0; i < 5; i++) {

        }

        if (_kbhit()) {
            char ch = _getch();

            if (ch == '\r') {
                // ����ڰ� ���� Ű�� ������ ����
                input[index] = '\0';
                break;
            }
            else if (index < MAX_INPUT_LENGTH - 1) {
                // �Էµ� ���ڸ� ����
                input[index] = ch;
                ++index;
                input[index] = '\0';  // ���ڿ� ���� null ���� �߰�
            }
        }


    }


}
