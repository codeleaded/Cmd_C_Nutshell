#if defined __linux__
#error "Linux not supported!"
#elif defined _WINE || defined _WIN32
#include <windows.h>
#include <stdio.h>

int WINAPI WinMain(HINSTANCE hInst,HINSTANCE hPrev,LPSTR lpCmdLine,int nCmdShow){
    printf("Hello World!!!\n");
    return 0;
}
#endif