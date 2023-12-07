#pragma once

#include <time.h>
#include <stdio.h>
#include <SDL.h>

#include "ScreenControl.h"
#define MAP_WIDTH  1920*9
#define MAP_HEIGHT 1080*9

void ShowGameScreen() {
    SDL_Window* window = initializeSDL();
    if (window == NULL) {
        return;
    }
    clock_t start_time, end_time;
    double elapsed_time;

    // 시작 시간 기록
    start_time = clock();

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Renderer creation failed: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }

    const char* backgroundImageFile = "./images/stage1.png";  // 이미지 파일 경로
    const char* characterImageFile1 = "./images/businessman1.png";
    const char* characterImageFile2 = "./images/businessman2.png";
    const char* characterImageFile3 = "./images/businessman3.png";

    SDL_Texture* backgroundTexture = loadTextureFromPNG(renderer, backgroundImageFile);
    SDL_Texture* characterTexture = loadTextureWithMask(renderer, characterImageFile1, 255, 255, 255, 20);

    if (backgroundTexture == NULL || characterTexture == NULL) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }

    int characterX = MAP_WIDTH / 2 - CHARACTERSIZE / 2;
    int characterY = MAP_HEIGHT / 2 - CHARACTERSIZE / 2;

    int quit = 0;

    int character_action = 0;
    int animation_temp = 0;



    while (!quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = 1;
            }
            else if (event.type == SDL_KEYDOWN) {
                // 키가 눌렸을 때
                if (event.key.keysym.sym == 1073741906) {
                    if (characterY >= 0)
                        characterY -= 5;
                }
                else if (event.key.keysym.sym == 1073741905) {
                    if (characterY <= MAP_WIDTH - CHARACTERSIZE)
                        characterY += 5;
                }
                else if (event.key.keysym.sym == 1073741904) {
                    if (characterX >= 0)
                        characterX -= 5;
                }
                else if (event.key.keysym.sym == 1073741903){
                    if (characterX <= MAP_WIDTH - CHARACTERSIZE)
                        characterX += 5;
                }
                else if (event.key.keysym.sym == 27){
                    quit = 1;
                }
            }
        }
        end_time = clock();
        elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

        if (elapsed_time >= 0.3 * character_action) {
            character_action++;

            if (animation_temp == 0) {
                animation_temp++;
                characterTexture = loadTextureWithMask(renderer, characterImageFile2, 255, 255, 255, 20);
            }
            else if (animation_temp == 1) {
                animation_temp++;
                characterTexture = loadTextureWithMask(renderer, characterImageFile2, 255, 255, 255, 20);
            }
            else if (animation_temp == 2) {
                animation_temp = 0;
                characterTexture = loadTextureWithMask(renderer, characterImageFile3, 255, 255, 255, 20);
            }

        }

        // 배경과 캐릭터를 그리기
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        int ShowingX = characterX % 1920;
        int ShowingY = characterY % 1080;
        characterRenderFrame(renderer, backgroundTexture, characterTexture, ShowingX, ShowingY);

        SDL_RenderPresent(renderer);

        if (elapsed_time > 2000) {
            start_time = clock();
            character_action = 0;
        }
    }

    SDL_DestroyTexture(backgroundTexture);
    SDL_DestroyTexture(characterTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return ;
}