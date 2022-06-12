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

	char wall = '#';




	char map[SIZE][SIZE]
	{
		{'@','.','.','#','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.','.'},
		{'.','#','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.','.'}
	};

	int rows = sizeof(map) / sizeof(map[0]);
	int cols = sizeof(map[0]) / sizeof(map[0][0]);

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
		cout << "e - выход" << endl;
		cout << playerX << endl;
		cout << playerY << endl;
		cout << map[playerY][playerX - 1] << endl;



		cin >> check_mov;

		if (check_mov == "e")
		{
			return 0;
		}

		if (check_mov == "d")
		{
			if (map[playerY][playerX + 1] == wall) {

			}
			else if (playerX + 1 >= SIZE) {

			}
			else {
				char temp = map[y][x];
				map[y][x] = map[y][playerX + 1];
				map[y][playerX + 1] = temp;
				playerX++;
				x++;
			}
		}

		if (check_mov == "a")
		{
			if (map[playerY][playerX - 1] == wall) {

			}
			else if (playerX - 1 <= -1) {

			}
			else {
				char temp = map[y][x];
				map[y][x] = map[y][playerX - 1];
				map[y][playerX - 1] = temp;
				playerX--;
				x--;
			}
		}

		if (check_mov == "s")
		{
			if (map[playerY + 1][playerX] == wall) {

			}
			else if(map[playerY + 1][playerX] >= sizeof(map))
			{
				
			}
			else {
				char temp = map[y][x];
				map[y][x] = map[playerY + 1][x];
				map[playerY + 1][x] = temp;
				playerY++;
				y++;
			}

		}


		if (check_mov == "w")
		{
			if (map[playerY - 1][playerX] == wall) {

			}
			else if (map[playerY - 1][playerX] >= sizeof(map))
			{

			}
			else {
				char temp = map[y][x];
				map[y][x] = map[playerY - 1][x];
				map[playerY - 1][x] = temp;
				playerY--;
				y--;
			}

		}
		system("cls");
	}
}