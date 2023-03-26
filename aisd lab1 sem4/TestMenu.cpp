#include <windows.h>
#include <conio.h>
#include<iostream>
#include <stdio.h>
#include <string>
#include <time.h>
#include<vector>
#include "BinaryTree.hpp"
#define ESC 27
#define UP 72
#define DOWN 80
#define ENTER 13
#define STD_ACT 6
#define STD_COL 15
#define PAS_ACT 4
#define PAS_PAS 8
#define RED 12
#define GREEN 10
void MainMenu();

using namespace std;

size_t lcg() {
	static size_t x = 0;
	x = (1021 * x + 24631) % 116640;
	return x;
}

void TestMenu();

HANDLE hStdOut_2 = GetStdHandle(STD_OUTPUT_HANDLE);

//void GoToXY(short x, short y);
void ConsoleCursorVisible(bool show, short size);

void cockometr(const int count)
{
	system("CLS");
	
	int val;

	Tree plum;
	clock_t start = clock();
	for (int i = 0; i < count; i++)
	{
		val = (int)lcg();
		if(!(plum.contains(val)))
		plum._insert(val);

	}
	clock_t end = clock();
	double TeeTime = (double)(end - start) / CLOCKS_PER_SEC;
	SetConsoleTextAttribute(hStdOut_2, STD_COL);
	cout << "Tee time: ";
	SetConsoleTextAttribute(hStdOut_2, GREEN);
	cout<< TeeTime;


	vector<int> victor;

	start = clock();
	for (int i = 0; i < count; i++)
	{
		victor.push_back((int)lcg()); 

	}
	end = clock();

	double VictorTime = (double)(end - start) / CLOCKS_PER_SEC;

	SetConsoleTextAttribute(hStdOut_2, STD_COL);
	cout << endl<<"Victor time: ";
	SetConsoleTextAttribute(hStdOut_2, RED);
	cout << (double)(end - start) / CLOCKS_PER_SEC;

	if (TeeTime < VictorTime)
	{
		//доделай изменения цветов
	}

	cout << endl<<"Press any key...";
	_getch();
	return;
}

void HeyPhil()
{
	system("CLS");
	string TreeMenuAct[] = { "SPEED tets для 100 эл-тов", "SPEED tets для 1000 эл-тов", "SPEED tets для 10000 эл-тов", "Назад(ESC)" };
	int active_menu = 0;
	char ch;


	while (true)
	{

		system("CLS");


		for (int i = 0; i < size(TreeMenuAct); i++)
		{
			if (i == active_menu) 	SetConsoleTextAttribute(hStdOut_2, STD_ACT);
			else 	SetConsoleTextAttribute(hStdOut_2, STD_COL);
			//GoToXY(x, y++);
			cout << TreeMenuAct[i] << endl;
		}

		ch = _getch();
		if (ch == -32) ch = _getch();
		switch (ch)
		{
		case ESC:
			MainMenu();
		case UP:
			if (active_menu > 0)
				--active_menu;
			//system("CLS");
			break;
		case DOWN:
			if (active_menu < size(TreeMenuAct) - 1)
				++active_menu;
			//system("CLS");
			break;
		case ENTER:
			switch (active_menu)
			{
			case 0:
				cockometr(100);
				break;
			case 1:
				cockometr(1000);
				break;
			case 2:
				cockometr(10000);
				break;
			case 3:

				TestMenu();

				break;
			}
		default:
			system("CLS");
			break;
		}

	}
}




void TestMenu()
{
	system("CLS");
	setlocale(0, "Rus");
	ConsoleCursorVisible(false, 100);

	string TreeMenuAct[] = { "SPEED test заполнеия", "SPEED test проверки наличия", "SPEED test заполнения и удаления", "Назад(ESC)" };
	int active_menu = 0;

	char ch;
	Tree plum;

	while (true)
	{

		system("CLS");
		

		for (int i = 0; i < size(TreeMenuAct); i++)
		{
			if (i == active_menu) 	SetConsoleTextAttribute(hStdOut_2, STD_ACT);
			else 	SetConsoleTextAttribute(hStdOut_2, STD_COL);
			//GoToXY(x, y++);
			cout << TreeMenuAct[i] << endl;
		}

		ch = _getch();
		if (ch == -32) ch = _getch();
		switch (ch)
		{
		case ESC:
			MainMenu();
		case UP:
			if (active_menu > 0)
				--active_menu;
			//system("CLS");
			break;
		case DOWN:
			if (active_menu < size(TreeMenuAct) - 1)
				++active_menu;
			//system("CLS");
			break;
		case ENTER:
			switch (active_menu)
			{
			case 0:
				HeyPhil();
				break;
			case 1:

				break;
			case 2:

				break;
			case 3:

				MainMenu();

				break;
			}
		default:
			system("CLS");
			break;
		}

	}
}

