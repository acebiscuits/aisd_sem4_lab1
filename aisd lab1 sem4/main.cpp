#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>;
#include<windows.h>

using namespace std;

/*ANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); // Получаем дескриптор консоли
// Текстовый курсор в точку x,y
void GoToXY(short x, short y)
{
	SetConsoleCursorPosition(hStdOut, { x, y });
}*/



void MainMenu();

int main()
{
	setlocale(LC_ALL, "ru");

	SetConsoleTitle(L"Lab 1");
	
	MainMenu();
}