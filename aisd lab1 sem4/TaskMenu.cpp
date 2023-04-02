#include <windows.h>
#include <conio.h>
#include<iostream>
#include <stdio.h>
#include <string>
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
//void MainMenu();

using namespace std;

HANDLE hStdOut_3 = GetStdHandle(STD_OUTPUT_HANDLE);

//void GoToXY(short x, short y);
void ConsoleCursorVisible(bool show, short size);

int GetVal()
{
	double val;
	int flag;
	while (1)
	{
		flag = 0;
		system("CLS");
		SetConsoleTextAttribute(hStdOut_3, STD_COL);

		cout << "Введите значение: ";
		

		while (!(cin >> val) || (cin.peek() != '\n'))
		{


			cin.clear();
			while (cin.get() != '\n');
			flag = 1;
			break;
		}
		if (double(int(val)) != val)
			continue;
		if (flag)
			continue;
		else
			break;
	}

	return (int)val;
}

void Task()
{
	system("CLS");
	string TreeMenuAct[] = { "Добавить элемент", "Назад(ESC)" };
	int active_menu = 0;
	char ch;
	std::vector<int> vec, res_vec;
	Tree plum, oak;
	int adding_val;
	while (true)
	{

		system("CLS");
		
		if (vec.empty())
		{
			SetConsoleTextAttribute(hStdOut_3, RED);
			cout << "Вектор пуст"<<endl<<endl;
		}
		else
		{
			SetConsoleTextAttribute(hStdOut_3, STD_COL);
			cout << "Вектор: ";
			SetConsoleTextAttribute(hStdOut_3, GREEN);
			for (int i = 0; i < vec.size(); i++) 
			{
				std::cout << vec.at(i) << ' ';

			}
			cout << endl;
			SetConsoleTextAttribute(hStdOut_3, STD_COL);
			cout << "Все повторяющиеся элементы в векторе: ";
			SetConsoleTextAttribute(hStdOut_3, GREEN);
			for (int i = 0; i < res_vec.size(); i++)
			{
				std::cout << res_vec.at(i) << ' ';

			}
			SetConsoleTextAttribute(hStdOut_3, STD_COL);
			cout << endl << endl;
		}
		




		for (int i = 0; i < size(TreeMenuAct); i++)
		{
			if (i == active_menu) 	SetConsoleTextAttribute(hStdOut_3, STD_ACT);
			else 	SetConsoleTextAttribute(hStdOut_3, STD_COL);
			//GoToXY(x, y++);
			cout << TreeMenuAct[i] << endl;
		}

		ch = _getch();
		if (ch == -32) ch = _getch();
		switch (ch)
		{
		case ESC:
			vec.erase(vec.begin(), vec.end());
			vec.shrink_to_fit();
			return;
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
				adding_val = GetVal();
				vec.push_back(adding_val);
				if (!plum.contains(adding_val))
				{
					plum._insert(adding_val);
				}
				else
				{
					if (!oak.contains(adding_val))
					{
						oak._insert(adding_val);

						res_vec.push_back(adding_val);
					}
				}
				break;

			case 1:

				return;

				break;
			}
		default:
			system("CLS");
			break;
		}

	}
}

int TaskMenu() 
{
	system("CLS");
	setlocale(0, "Rus");
	ConsoleCursorVisible(false, 100);

	string TreeMenuAct[] = { "Задать вектор", "Назад(ESC)" };
	int active_menu = 0;

	

	char ch;
	Tree plum;

	while (true)
	{

		system("CLS");

		for (int i = 0; i < size(TreeMenuAct); i++)
		{
			if (i == active_menu) 	SetConsoleTextAttribute(hStdOut_3, STD_ACT);
			else 	SetConsoleTextAttribute(hStdOut_3, STD_COL);
			cout << TreeMenuAct[i] << endl;
		}

		ch = _getch();
		if (ch == -32) ch = _getch();
		switch (ch)
		{
		case ESC:
			system("CLS");
			return -1;
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
				Task();

				break;
			case (size(TreeMenuAct) -1):
				system("CLS");
				return -1;
				break;
			}
		default:
			system("CLS");
			break;
		}

	}
}