#include <cstdlib>
#include "consola.h"

#ifdef _WIN32
#include <windows.h>
#endif

void aplicarEstilo(){

#ifdef _WIN32
    HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consola, FOREGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
#endif

}

void initConsola(){
    aplicarEstilo();
}

void limpiarPantalla(){
    system("cls");
    aplicarEstilo();
}
