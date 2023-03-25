#include <windows.h>
#include <conio.h>
#include<iostream>
#include <stdio.h>
#include <string>
#define ESC 27
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13
#define STD_ACT 6
#define STD_COL 15

using namespace std;

void TreeMenu();

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

void GoToXY(short x, short y)
{
	SetConsoleCursorPosition(hStdOut, { x, y });
}

void ConsoleCursorVisible(bool show, short size)
{
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = show; // изменяем видимость курсора
		structCursorInfo.dwSize = size; // изменяем размер курсора
		SetConsoleCursorInfo(hStdOut, &structCursorInfo);
}

void MainMenu()
{
	system("CLS");
	setlocale(0, "Rus");
	ConsoleCursorVisible(false, 100);

	string Menu[] = { "Создать дерево", "Выход(ESC)" };
	int active_menu = 0;


	char ch;
	while (true)
	{

		int x = 0, y = 0;
		GoToXY(x, y);

		for (int i = 0; i < size(Menu); i++)
		{
			if (i == active_menu) 	SetConsoleTextAttribute(hStdOut, STD_ACT);
			else 	SetConsoleTextAttribute(hStdOut, STD_COL);
			GoToXY(x, y++);
			cout << Menu[i] << endl;
		}

		ch = _getch();
		if (ch == -32) ch = _getch(); // Отлавливаем стрелочки
		switch (ch)
		{
		case ESC:
			exit(0);
		case UP:
			if(active_menu>0)
			--active_menu;
			break;
		case DOWN:
			if (active_menu < size(Menu) - 1)
			++active_menu;
			break;
		case ENTER:
			switch (active_menu)
			{
			case 0:
				system("CLS");
				GoToXY(0, 0);
				TreeMenu();
				break;;
			case (size(Menu) - 1):
				exit(0);
			}
			break;
		default:
			break;
		}
	}

	
//	_getch();

}
