#include <iostream>
#include<ctime>
#include<string.h>

using namespace std;



int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	bool rec = false;

	const int SIZE = 10;
	string check_mov;
	int playerX = 0;
	int playerY = 0;
	int x = 0;
	int y = 0;

	char map[SIZE][SIZE]
	{
		{'@','.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.','.'}
	};
	while (!rec)
	{
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				cout << map[i][j];
			}
			cout << endl;
		}

		cout << "\nваше действие:" << endl;
		cout << "w- движение вверх" << endl;
		cout << "s - движение в низ" << endl;
		cout << "a - движение в лево" << endl;
		cout << "d - движение в право" << endl;
		cout << "esc - выход" << endl;
		
		

		cin >> check_mov;

		if (check_mov == "esc")
		{
			break;
		}

		if (check_mov == "d")
		{
			char temp = map[y][x];
			map[y][x] = map[y][playerX + 1];
			map[y][playerX + 1] = temp;
			playerX++;
			x++;
		}

		if (check_mov == "a")
		{
			char temp = map[y][x];
			map[y][x] = map[y][playerX - 1];
			map[y][playerX - 1] = temp;
			playerX--;
			x--;
		}

		if (check_mov == "s")
		{
			char temp = map[y][x];
			map[y][x] = map[playerY + 1][x];
			map[playerY + 1][x] = temp;
			playerY++;
			y++;
		}


		if (check_mov == "w")
		{
			char temp = map[y][x];
			map[y][x] = map[playerY - 1][x];
			map[playerY - 1][x] = temp;
			playerY--;
			y--;
		}

		system("cls");
	}
}