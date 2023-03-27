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
	cout << "Tree time: ";
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
	cout << endl<<"Vector time: ";
	SetConsoleTextAttribute(hStdOut_2, GREEN);
	cout << (double)(end - start) / CLOCKS_PER_SEC;



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

		bool found;
		clock_t start = clock();

		found = plum.contains(val_choise);

		clock_t end = clock();
		double TreeTime = (double)(end - start) / CLOCKS_PER_SEC;

		SetConsoleTextAttribute(hStdOut_2, STD_COL);
		cout << endl << "Tree time: ";
		SetConsoleTextAttribute(hStdOut_2, GREEN);
		cout << (double)(end - start) / CLOCKS_PER_SEC;
		if (found)
			cout << "\tYes";
		else
			cout << "\tNo";
		vector<int> victor;


		for (int i = 0; i < count; i++)
		{
			victor.push_back((int)lcg());

		}

		start = clock();
		found = std::find(victor.begin(), victor.end(), val_choise) != victor.end();
		end = clock();

		double VictorTime = (double)(end - start) / CLOCKS_PER_SEC;

		SetConsoleTextAttribute(hStdOut_2, STD_COL);
		cout << endl << "Vector time: ";
		SetConsoleTextAttribute(hStdOut_2, GREEN);
		cout << (double)(end - start) / CLOCKS_PER_SEC;
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
	string TreeMenuAct[] = { "SPEED tets для поиска из 100 эл-тов", "SPEED tets для поиска из 1000 эл-тов", "SPEED tets для поиска из 10000 эл-тов", "Назад(ESC)" };
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
				checkmetr(100);
				break;
			case 1:
				checkmetr(1000);
				break;
			case 2:
				checkmetr(10000);
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

void todmetr(const int count)
{
	system("CLS");

	int val;

	Tree plum;
	clock_t start = clock();
	for (int i = 0; i < count; i++)
	{
		val = (int)lcg();
		if (!(plum.contains(val)))
			plum._insert(val);

	}
	plum.~Tree();
	clock_t end = clock();
	double TeeTime = (double)(end - start) / CLOCKS_PER_SEC;
	SetConsoleTextAttribute(hStdOut_2, STD_COL);
	cout << "Tree time: ";
	SetConsoleTextAttribute(hStdOut_2, GREEN);
	cout << TeeTime;


	vector<int> victor;

	start = clock();
	for (int i = 0; i < count; i++)
	{
		victor.push_back((int)lcg());

	}
	victor.clear();
	end = clock();

	double VictorTime = (double)(end - start) / CLOCKS_PER_SEC;

	SetConsoleTextAttribute(hStdOut_2, STD_COL);
	cout << endl << "Vector time: ";
	SetConsoleTextAttribute(hStdOut_2, GREEN);
	cout << (double)(end - start) / CLOCKS_PER_SEC;



	cout << endl << "Press any key...";
	_getch();
	return;
}

void HeyTod()
{
	system("CLS");
	string TreeMenuAct[] = { "SPEED tets для заполнения/удаления 100 эл-тов", "SPEED tets для заполнения/удаления 1000 эл-тов", "SPEED tets для заполнения/удаления 10000 эл-тов", "Назад(ESC)" };
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
				todmetr(100);
				break;
			case 1:
				todmetr(1000);
				break;
			case 2:
				todmetr(10000);
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
				HeyChuck();
				break;
			case 2:
				HeyTod();
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

