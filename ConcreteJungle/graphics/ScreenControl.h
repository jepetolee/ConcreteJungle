#pragma once


#include "stb_image.h"
#include <SDL.h>

#define CHARACTERSIZE 128




typedef struct Camera {
    int x;  // 카메라의 x 좌표
    int y;  // 카메라의 y 좌표
    int screenWidth;  // 화면의 너비
    int screenHeight;  // 화면의 높이
} Camera;

void initializeCamera(Camera* camera, int screenWidth, int screenHeight) {
    camera->x = 0;
    camera->y = 0;
    camera->screenWidth = screenWidth;
    camera->screenHeight = screenHeight;
}

SDL_Window* initializeSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL initialization failed: %s\n", SDL_GetError());
        return NULL;
    }

    SDL_Window* window = SDL_CreateWindow("Concrete Jungle",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        1920, 1080, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window creation failed: %s\n", SDL_GetError());
        SDL_Quit();
        return NULL;
    }

    return window;
}

SDL_Texture* loadTextureFromPNG(SDL_Renderer* renderer, const char* filePath) {
    int width, height, channels;
    unsigned char* imageData = stbi_load(filePath, &width, &height, &channels, STBI_rgb_alpha);
    if (!imageData) {
        printf("Failed to load image: %s\n", stbi_failure_reason());
        return NULL;
    }

    SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STATIC, width, height);
    if (!texture) {
        printf("Failed to create texture: %s\n", SDL_GetError());
        stbi_image_free(imageData);
        return NULL;
    }

    SDL_UpdateTexture(texture, NULL, imageData, width * 4);
    stbi_image_free(imageData);

    return texture;
}



void characterRenderFrame(SDL_Renderer* renderer, SDL_Texture* backgroundTexture, SDL_Texture* characterTexture, int characterX, int characterY) {
    // 배경 이미지 그리기
    SDL_Rect backgroundRect = { 0, 0, 1920, 1080 };
    SDL_RenderCopy(renderer, backgroundTexture, NULL, &backgroundRect);

    // 캐릭터 그리기
    SDL_Rect characterRect = { characterX, characterY, CHARACTERSIZE, CHARACTERSIZE };
    SDL_RenderCopy(renderer, characterTexture, NULL, &characterRect);
}

void makeColorTransparent(SDL_Surface* surface, Uint8 r, Uint8 g, Uint8 b, Uint8 tolerance) {
    Uint32 key = SDL_MapRGB(surface->format, r, g, b);
    Uint8* pixels = (Uint8*)surface->pixels;
    Uint32 pixelCount = surface->w * surface->h;

    for (Uint32 i = 0; i < pixelCount; ++i) {
        Uint32 pixel = *((Uint32*)pixels);
        Uint8 red, green, blue;
        SDL_GetRGB(pixel, surface->format, &red, &green, &blue);

        if (abs(red - r) <= tolerance && abs(green - g) <= tolerance && abs(blue - b) <= tolerance) {
            *((Uint32*)pixels) = SDL_MapRGBA(surface->format, 0, 0, 0, 0);  // Set pixel to transparent
        }

        pixels += sizeof(Uint32);
    }
}

SDL_Texture* loadTextureWithMask(SDL_Renderer* renderer, const char* filePath, Uint8 maskRed, Uint8 maskGreen, Uint8 maskBlue, Uint8 tolerance) {
    int width, height, channels;
    unsigned char* imageData = stbi_load(filePath, &width, &height, &channels, STBI_rgb_alpha);
    if (!imageData) {
        printf("Failed to load image: %s\n", stbi_failure_reason());
        return NULL;
    }

    SDL_Surface* imageSurface = SDL_CreateRGBSurfaceFrom(imageData, width, height, 32, width * 4, 0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000);
    if (!imageSurface) {
        printf("Failed to create surface: %s\n", SDL_GetError());
        stbi_image_free(imageData);
        return NULL;
    }

    makeColorTransparent(imageSurface, maskRed, maskGreen, maskBlue, tolerance);

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, imageSurface);
    SDL_FreeSurface(imageSurface);
    stbi_image_free(imageData);

    return texture;
}

