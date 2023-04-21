#include <windows.h>
#include <conio.h>
#include<iostream>
#include <stdio.h>

#include <string>
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

HANDLE hStdOut_1 = GetStdHandle(STD_OUTPUT_HANDLE);

//void GoToXY(short x, short y);
void ConsoleCursorVisible(bool show, short size);



int MistakeAdd(const int mistake)
{

	

	string TreeMenuAct[] = { "Попробовать ввести снова", "Сдаться(ESC)" };
	int active_menu = 0;

	char ch;
	while (1)
	{
		system("CLS");
		if (mistake == 1)
		{
			SetConsoleTextAttribute(hStdOut_1, RED);
			cout << endl << "Вы ввели текст" << endl<<endl;
		}
		else
		{
			SetConsoleTextAttribute(hStdOut_1, RED);
			cout << endl << "Вы ввели не целое число" << endl<<endl;
		}
		for (int i = 0; i < size(TreeMenuAct); i++)
		{
			if (i == active_menu) 	SetConsoleTextAttribute(hStdOut_1, STD_ACT);
			else 	SetConsoleTextAttribute(hStdOut_1, STD_COL);
			cout << TreeMenuAct[i] << endl;
		}
		ch = _getch();
		if (ch == -32) ch = _getch();
		switch (ch)
		{
		case ESC:
			system("CLS");
			return 2;
		case UP:
			if (active_menu > 0)
				--active_menu;
			break;
		case DOWN:
			if (active_menu < size(TreeMenuAct) - 1)
				++active_menu;

			break;
		case ENTER:
			switch (active_menu)
			{
			case 0:
				system("CLS");
				return 1;
			case 1:
				system("CLS");
				return 2;
			}
			break;

		default:
			break;
		}
		
	}
}

void TreeMenuAdding(Tree& plum)
{
	double val;
	
	while (1)
	{
		system("CLS");
		SetConsoleTextAttribute(hStdOut_1, STD_COL);

		cout << "Введите значение: ";
		int choise = 0;
		while (!(cin >> val) || (cin.peek() != '\n'))
		{


			cin.clear();
			while (cin.get() != '\n');
			choise = MistakeAdd(1);

			break;
		}
		if (double(int(val)) != val)choise = MistakeAdd(2);

		if (choise == 1) continue;
		else if (choise == 2) return;
		else if(!(plum.contains(val))) plum._insert(val);
		return;
	}
}



void TreeMenuRemoving(Tree& plum)
{
	double val;

	while (1)
	{
		system("CLS");
		SetConsoleTextAttribute(hStdOut_1, STD_COL);

		cout << "Введите значение: ";

		while (!(cin >> val) || (cin.peek() != '\n'))
		{


			cin.clear();
			while (cin.get() != '\n');

			break;
		}
		if (double(int(val)) != val)
			continue;

		
		if ((plum.contains(val))) plum.erase(val);
		return;
	}
}

void TreeMenuContaining(Tree& plum)
{
	double val;

	while (1)
	{
		system("CLS");
		SetConsoleTextAttribute(hStdOut_1, STD_COL);

		cout << "Введите значение: ";

		while (!(cin >> val) || (cin.peek() != '\n'))
		{


			cin.clear();
			while (cin.get() != '\n');

			break;
		}
		if (double(int(val)) != val)
			continue;



		if (plum.contains(val))
		{
			
			system("CLS");
				SetConsoleTextAttribute(hStdOut_1, GREEN);
				cout << "такой эл-т есть";

			
		}
		else
		{
			system("CLS");
			SetConsoleTextAttribute(hStdOut_1, RED);
			cout << "такого эл-та нет";
		}
		SetConsoleTextAttribute(hStdOut_1, STD_COL);
		cout << endl << "Press any key...";
		_getch();
		return;
	}
}




int TreeMenu()
{
	system("CLS");
	setlocale(0, "Rus");
	ConsoleCursorVisible(false, 100);

	string TreeMenuAct[] = { "Добавить элемент", "Удалить элемент", "Проверить наличие","Создать нвое девево", "Назад(ESC)"};
	int active_menu = 0;

	char ch;
	Tree plum;

	while (true)
	{
		//int x = 0, y = 3;
		//GoToXY(x, y);
		system("CLS");
		if (!plum.get_root())
		{
			SetConsoleTextAttribute(hStdOut_1, RED);
			cout << "Дерево пустое" << endl << endl;
		}
		else
		{
			SetConsoleTextAttribute(hStdOut_1, GREEN);
			cout << "Дерево: ";
			plum.print();
			cout << endl << endl;;
		}

		for (int i = 0; i < size(TreeMenuAct); i++)
		{
			if (i == active_menu) 	SetConsoleTextAttribute(hStdOut_1, STD_ACT);
			else 	SetConsoleTextAttribute(hStdOut_1, STD_COL);
			if (plum.get_root() == NULL && (i == 1 || i == 2))
			{
				if (i == active_menu) 	SetConsoleTextAttribute(hStdOut_1, PAS_ACT);
				else 	SetConsoleTextAttribute(hStdOut_1, PAS_PAS);
			}
			//GoToXY(x, y++);
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
				
				TreeMenuAdding(plum);
				break;
			case 1:
				if (plum.get_root())
				TreeMenuRemoving(plum);
				break;
			case 2:
				if (plum.get_root())
				TreeMenuContaining(plum);
				break;
			case 3:
				return 1;
				//TreeMenu();
				break;
			case size(TreeMenuAct) -1:
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