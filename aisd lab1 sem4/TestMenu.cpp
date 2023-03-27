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
//void MainMenu();

using namespace std;

size_t lcg() {
	static size_t x = 0;
	x = (1021 * x + 24631) % 116640;
	return x;
}

int TestMenu();

HANDLE hStdOut_2 = GetStdHandle(STD_OUTPUT_HANDLE);

//void GoToXY(short x, short y);
void ConsoleCursorVisible(bool show, short size);

void cockometr(const int count)
{
	system("CLS");
	
	int val;
	double all_time = 0;
	Tree plum;
	clock_t start;
	clock_t end;
	for (int i = 0; i < 100; i++)
	{
		start = clock();
		for (int i = 0; i < count; i++)
		{
			val = (int)lcg();
			if (!(plum.contains(val)))
				plum._insert(val);

		}
		end = clock();
		all_time+= (double)(end - start) / CLOCKS_PER_SEC;
	}
	
	double avg_time = all_time / 100;
	SetConsoleTextAttribute(hStdOut_2, STD_COL);
	cout << "Tree time: ";
	SetConsoleTextAttribute(hStdOut_2, GREEN);
	cout<< avg_time;
	all_time = 0;

	vector<int> victor;
	for (int i = 0; i < 100; i++)
	{
		start = clock();
		for (int i = 0; i < count; i++)
		{
			victor.push_back((int)lcg());

		}
		end = clock();
		all_time += (double)(end - start) / CLOCKS_PER_SEC;
	}

	avg_time = all_time / 100;

	SetConsoleTextAttribute(hStdOut_2, STD_COL);
	cout << endl<<"Vector time: ";
	SetConsoleTextAttribute(hStdOut_2, GREEN);
	cout << avg_time;



	cout << endl<<"Press any key...";
	_getch();
	return;
}

void HeyPhil()
{
	system("CLS");
	string TreeMenuAct[] = { "SPEED tets для 1000 эл-тов", "SPEED tets для 10000 эл-тов", "SPEED tets для 100000 эл-тов", "Назад(ESC)" };
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
				cockometr(100);
				break;
			case 1:
				cockometr(1000);
				break;
			case 2:
				cockometr(10000);
				break;
			case 3:

				return;

				break;
			}
		default:
			system("CLS");
			break;
		}

	}
}

void checkmetr(const int count)
{
	system("CLS");

	int val;

	Tree plum;
	
	for (int i = 0; i < count; i++)
	{
		val = (int)lcg();
		if (!(plum.contains(val)))
			plum._insert(val);

	}

	double val_choise;

	while (1)
	{
		system("CLS");
		SetConsoleTextAttribute(hStdOut_2, STD_COL);

		cout << "Введите значение: ";
		while (!(cin >> val_choise) || (cin.peek() != '\n'))
		{


			cin.clear();
			while (cin.get() != '\n');
			system("CLS");
			SetConsoleTextAttribute(hStdOut_2, RED);
			cout << "Введен текст";
			SetConsoleTextAttribute(hStdOut_2, STD_COL);
			cout << endl << "Press any key...";
			_getch();
			return;
		}
		while (double(int(val_choise)) != val_choise)
		{
			system("CLS");
			SetConsoleTextAttribute(hStdOut_2, RED);
			cout << "Введено не целое число";
			SetConsoleTextAttribute(hStdOut_2, STD_COL);
			cout << endl << "Press any key...";
			_getch();
			return;
		}
		clock_t start;
		clock_t end;
		double all_time = 0;
		bool found = 0;
		for (int i = 0; i < 100; i++)
		{
			start = clock();

			if(plum.contains(val_choise)) found = true;

			end = clock();
			all_time+= (double)(end - start) / CLOCKS_PER_SEC;

		}
		double AvgTime = all_time/100;

		SetConsoleTextAttribute(hStdOut_2, STD_COL);
		cout << endl << "Tree time: ";
		SetConsoleTextAttribute(hStdOut_2, GREEN);
		cout << AvgTime;
		if (found)
			cout << "\tYes";
		else
			cout << "\tNo";
		vector<int> victor;

		all_time = 0;
		for (int i = 0; i < count; i++)
		{
			victor.push_back((int)lcg());

		}
		found = 0;
		for (int i = 0; i < 100; i++)
		{
			start = clock();
			if(std::find(victor.begin(), victor.end(), val_choise) != victor.end())found = true;
			end = clock();
			all_time += (double)(end - start) / CLOCKS_PER_SEC;
		}
		AvgTime = all_time / 100;

		SetConsoleTextAttribute(hStdOut_2, STD_COL);
		cout << endl << "Vector time: ";
		SetConsoleTextAttribute(hStdOut_2, GREEN);
		cout << AvgTime;
		if (found)
			cout << "\tYes";
		else
			cout << "\tNo";



		cout << endl << "Press any key...";
		_getch();
		return;
	}
}

void HeyChuck()
{

	system("CLS");
	string TreeMenuAct[] = { "SPEED tets для поиска из 1000 эл-тов", "SPEED tets для поиска из 10000 эл-тов", "SPEED tets для поиска из 100000 эл-тов", "Назад(ESC)" };
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
				checkmetr(100);
				break;
			case 1:
				checkmetr(1000);
				break;
			case 2:
				checkmetr(10000);
				break;
			case 3:

				return;

				break;
			}
		default:
			system("CLS");
			break;
		}

	}
}

void todmetr(const int count)
{
	system("CLS");

	int val;
	double all_time = 0;
	Tree plum;
	clock_t start;
	clock_t end;

	for (int i = 0; i < 100; i++)
	{

		start = clock();
		for (int i = 0; i < count; i++)
		{
			val = (int)lcg();
			if (!(plum.contains(val)))
				plum._insert(val);

		}
		plum.~Tree();
		end = clock();
		all_time+= (double)(end - start) / CLOCKS_PER_SEC;
	}
	double avg_time = all_time / 100;
	
	double TeeTime = avg_time;
	SetConsoleTextAttribute(hStdOut_2, STD_COL);
	cout << "Tree time: ";
	SetConsoleTextAttribute(hStdOut_2, GREEN);
	cout << TeeTime;
	all_time = 0;

	vector<int> victor;
	for (int i = 0; i < 100; i++)
	{
		start = clock();
		for (int i = 0; i < count; i++)
		{
			victor.push_back((int)lcg());

		}
		victor.clear();
		end = clock();
		all_time += (double)(end - start) / CLOCKS_PER_SEC;
	}
	avg_time = all_time / 100;

	SetConsoleTextAttribute(hStdOut_2, STD_COL);
	cout << endl << "Vector time: ";
	SetConsoleTextAttribute(hStdOut_2, GREEN);
	cout << avg_time;



	cout << endl << "Press any key...";
	_getch();
	return;
}

void HeyTod()
{
	system("CLS");
	string TreeMenuAct[] = { "SPEED tets для заполнения/удаления 1000 эл-тов", "SPEED tets для заполнения/удаления 10000 эл-тов", "SPEED tets для заполнения/удаления 100000 эл-тов", "Назад(ESC)" };
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
				todmetr(1000);
				break;
			case 1:
				todmetr(10000);
				break;
			case 2:
				todmetr(100000);
				break;
			case 3:

				return;

				break;
			}
		default:
			system("CLS");
			break;
		}

	}
}

int TestMenu()
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
				HeyPhil();
				break;
			case 1:
				HeyChuck();
				break;
			case 2:
				HeyTod();
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

