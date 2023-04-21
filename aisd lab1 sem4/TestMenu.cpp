#include <windows.h>
#include <conio.h>
#include<iostream>
#include <stdio.h>
#include <string>
#include <time.h>
#include<vector>
#include<fstream>
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

void Speed_filling_to_txt()
{
	ofstream outfile("filling_speed.csv");
	clock_t start, end;
	for (int i = 1000; i < 100001; i += 1000)
	{
		vector<int> vec;
		start = clock();
		for (int j = 0; j < i; j++)
		{
			vec.push_back((int)(lcg()));

		}
		end = clock();
		double vec_time = (double)(end - start) / CLOCKS_PER_SEC;

		double tree_time = 0;
		for (int j = 0; j < 100; j++)
		{
			Tree oak;
			start = clock();
			for (int k = 0; k < i; k++)
			{
				oak._insert((int)(lcg()));
			}
			end = clock();
			tree_time += (double)(end - start) / CLOCKS_PER_SEC;
		}
		tree_time /= 100;

		outfile << i << "," << vec_time << "," << tree_time << "\n";
		cout << i << " write" << endl;

	}

	outfile.close();
}

void Speed_finding_to_txt()
{
	ofstream outfile("finding_speed.csv");
	clock_t start, end;
	vector<int> vec;
	Tree plum;
	for (int i = 1000; i < 100001; i += 1000)
	{
		for (int j = 0; j < 1000; j++)
		{
			vec.push_back((int)(lcg()));

		}
		int ebbr;
		start = clock();
		auto place = find(vec.begin(), vec.end(), (int)(lcg()));
		end = clock();
		double vec_time = (double)(end - start) / CLOCKS_PER_SEC;

		double tree_time = 0;
		for (int j = 0; j < 1000; j++)
		{
			plum._insert((int)(lcg()));
		}

		for (int j = 0; j < 1000; j++)
		{
			start = clock();
			ebbr = plum.contains((int)(lcg()));
			end = clock();
			tree_time += (double)(end - start) / CLOCKS_PER_SEC;
		}
		tree_time /= 1000;

		outfile << i << "," << vec_time << "," << tree_time << "\n";
		cout << i << " write" << endl;

	}

	outfile.close();
}

void Speed_add_delete_to_txt()
{
	ofstream outfile("adding_deleting_speed.csv");
	clock_t start, end;
	vector<int> vec;
	Tree plum;
	for (int i = 1000; i < 100001; i += 1000)
	{
		for (int j = 0; j < 1000; j++)
		{
			vec.push_back((int)(lcg()));

		}
		int rand_val = (int)lcg();
		start = clock();
		vec.push_back(rand_val);
		vec.erase(remove(vec.begin(), vec.end(), rand_val), vec.end());
		end = clock();
		double vec_time = (double)(end - start) / CLOCKS_PER_SEC;

		double tree_time = 0;
		for (int j = 0; j < 1000; j++)
		{
			plum._insert((int)(lcg()));
		}

		for (int j = 0; j < 1000; j++)
		{
			rand_val = lcg();
			start = clock();
			plum._insert(rand_val);
			plum.erase(rand_val);
			end = clock();
			tree_time += (double)(end - start) / CLOCKS_PER_SEC;
		}
		tree_time /= 1000;

		outfile << i << "," << vec_time << "," << tree_time << "\n";
		cout << i << " write" << endl;

	}

	outfile.close();
}

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
				//HeyPhil();
				Speed_filling_to_txt();
				break;
			case 1:
				//HeyChuck();
				Speed_finding_to_txt();
				break;
			case 2:
				Speed_add_delete_to_txt();
				//HeyTod();
				
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

