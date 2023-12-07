#pragma once

#define _CRT_SECURE_NO_WARNINGS 
#define STB_IMAGE_IMPLEMENTATION


#include <stdio.h>
#include <conio.h>
#include <SDL.h>
#include <windows.h>

#include "graphics/Menu.h"
#include "graphics/GameScreen.h"

#define CHARACTERSIZE 128

int main() {
    int value = Menu();
    if (value) {
        ShowGameScreen("./images/stage1.png");
    }
    
   /*thread1 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)threadFunction1, NULL, 0, NULL);
    thread2 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)threadFunction2, NULL, 0, NULL);

    // 각 스레드의 실행이 끝날 때까지 대기
    WaitForSingleObject(thread1, INFINITE);
    WaitForSingleObject(thread2, INFINITE);

    // 스레드 핸들 닫기
    CloseHandle(thread1);
    CloseHandle(thread2);*/ 
   

    return 0;
}
