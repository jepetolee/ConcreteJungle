#pragma once

#include <SDL.h>
#include "stb_image.h"
#include "ScreenControl.h"


/*
0 - 종료
1 - 설정
2 - 게임
3 - 명령어
*/

int Menu() {

    // Create a window
    SDL_Window * window = initializeSDL();
    if (window == NULL) {
        return 1;
    }

    // Create a renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    const char* backgroundImageFile = "./images/background.png";
    const char* TitleImageFile = "./images/Title.png";
    const char* StartImageFile = "./images/Start.png";
    const char* CommandImageFile = "./images/Command.png";
    const char* SettingImageFile = "./images/Settings.png";
    const char* SelectImageFile = "./images/strict.png";


    // Convert the surface to a texture
    SDL_Texture* backgroundTexture = loadTextureFromPNG(renderer, backgroundImageFile);
    SDL_Texture* TitleTexture = loadTextureFromPNG(renderer, TitleImageFile); 
    SDL_Texture* StartTexture = loadTextureFromPNG(renderer, StartImageFile);
    SDL_Texture* CommandTexture = loadTextureFromPNG(renderer, CommandImageFile);
    SDL_Texture* SettingTexture = loadTextureFromPNG(renderer, SettingImageFile);
    SDL_Texture* SelectTexture = loadTextureWithMask(renderer, SelectImageFile, 255, 255, 255, 20);

    SDL_Rect backgroundRect = { 0, 0, 1920, 1080 };
    SDL_Rect titleRect = { (1920 - 1134) / 2, 150, 1134, 132 };
    SDL_Rect startRect = { (1920 - 542) / 2, 340, 542, 117 };
    SDL_Rect commandRect = { (1920 - 542) / 2, 590, 542, 117 };
    SDL_Rect settingRect = { (1920 - 542) / 2, 840, 542, 117 };

    SDL_Rect selectRect = startRect;
    // Main loop
    int quit = 0, choser = 0;
    SDL_Event e;

    while (!quit) {
        // Event handling
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            }
            else if (e.type == SDL_KEYDOWN) {
                // 키가 눌렸을 때
                if (e.key.keysym.sym == 1073741906) {
                    if (choser > 0)
                        choser--;
                }
                else if (e.key.keysym.sym == 1073741905) {
                    if (choser < 2)
                        choser++;
                }
                else if (e.key.keysym.sym == 27)
                    quit = 1;
                else if (e.key.keysym.sym == 13) {
                    if (choser == 0){
                                        
                        SDL_DestroyTexture(backgroundTexture);
                        SDL_DestroyTexture(TitleTexture);
                        SDL_DestroyTexture(StartTexture);
                        SDL_DestroyTexture(CommandTexture);
                        SDL_DestroyTexture(SettingTexture);
                        SDL_DestroyTexture(SelectTexture);

                        SDL_DestroyRenderer(renderer);
                        SDL_DestroyWindow(window);
                        SDL_Quit();
                        return 1;
                    }
                    else if (choser == 1)
                        selectRect = commandRect;
                    else if (choser == 2)
                        selectRect = settingRect;
                }

            }

        }

        if (choser == 0)
            selectRect = startRect;
        else if (choser == 1)
            selectRect = commandRect;
        else if (choser == 2)
            selectRect = settingRect;

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        // Clear the screen
        SDL_RenderClear(renderer);

        // 배경 이미지 그리기
       
        SDL_RenderCopy(renderer, backgroundTexture, NULL, &backgroundRect);
        SDL_RenderCopy(renderer, TitleTexture, NULL, &titleRect);
        SDL_RenderCopy(renderer, StartTexture, NULL, &startRect);
        SDL_RenderCopy(renderer, CommandTexture, NULL, &commandRect);
        SDL_RenderCopy(renderer, SettingTexture, NULL, &settingRect);
        SDL_RenderCopy(renderer, SelectTexture, NULL, &selectRect);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(backgroundTexture);
    SDL_DestroyTexture(TitleTexture);
    SDL_DestroyTexture(StartTexture);
    SDL_DestroyTexture(CommandTexture);
    SDL_DestroyTexture(SettingTexture);
    SDL_DestroyTexture(SelectTexture);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;//종료
}

