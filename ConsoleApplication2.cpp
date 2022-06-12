#include <iostream>
#include<ctime>
#include<string.h>
#include <Windows.h>
#include <chrono>
#include <thread>
using namespace std;



int main()
{

	using namespace std::this_thread;
	using namespace std::chrono;

	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	bool rec = false;

	const int SIZE = 10;
	string check_mov;
	int playerX = 0;
	int playerY = 0;
	int x = 0;
	int y = 0;

	int sleepBeforeMove = 100;

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


		if (check_mov == "e")
		{
			return 0;
		}

		if (GetKeyState('D') & 0x8000)
		{
			if (map[playerY][playerX + 1] == wall) {

			}
			else if (playerX + 1 >= SIZE) {

			}
			else {
				sleep_for(milliseconds(sleepBeforeMove));
				char temp = map[y][x];
				map[y][x] = map[y][playerX + 1];
				map[y][playerX + 1] = temp;
				playerX++;
				x++;
			}
		}

		if (GetKeyState('A') & 0x8000)
		{
			if (map[playerY][playerX - 1] == wall) {

			}
			else if (playerX - 1 <= -1) {

			}
			else {
				sleep_for(milliseconds(sleepBeforeMove));
				char temp = map[y][x];
				map[y][x] = map[y][playerX - 1];
				map[y][playerX - 1] = temp;
				playerX--;
				x--;
			}
		}

		if (GetKeyState('S') & 0x8000)
		{
			if (map[playerY + 1][playerX] == wall) {

			}
			else if(map[playerY + 1][playerX] >= sizeof(map))
			{
				
			}
			else {
				sleep_for(milliseconds(sleepBeforeMove));
				char temp = map[y][x];
				map[y][x] = map[playerY + 1][x];
				map[playerY + 1][x] = temp;
				playerY++;
				y++;
			}

		}


		if (GetKeyState('W') & 0x8000)
		{
			if (map[playerY - 1][playerX] == wall) {

			}
			else if (map[playerY - 1][playerX] >= sizeof(map))
			{

			}
			else {
				sleep_for(milliseconds(sleepBeforeMove));
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