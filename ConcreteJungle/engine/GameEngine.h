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

    
    printf("콘크리트 정글 게임 엔진 (v: 0.1.0)\n");
    printf("원하시는 명령을 입력해주세요.");

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
                // 사용자가 엔터 키를 누르면 종료
                input[index] = '\0';
                break;
            }
            else if (index < MAX_INPUT_LENGTH - 1) {
                // 입력된 문자를 저장
                input[index] = ch;
                ++index;
                input[index] = '\0';  // 문자열 끝에 null 문자 추가
            }
        }


    }


}
