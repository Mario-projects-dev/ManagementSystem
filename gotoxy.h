//created function to reuse gotoxy function
//it set console cursor to requested coordinates

#pragma once

#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;

void gotoxy(int x, int y)
{
    static HANDLE h = NULL;
    if (!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };
    SetConsoleCursorPosition(h, c);
}
