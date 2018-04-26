#include <iostream>
#include <ctime>
using namespace std;

int rows = 2;
int columns = 10;
int maxMines = 10;
int matrix[10][10];

void Clear(int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			matrix[i][j] = 0;
		}
	}
}

void Draw(int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int NumberOfMines(int r, int c)
{
	int counter = 0;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (matrix[i][j] == 1);
			counter++;
		}
	}
}

void SetMines(int r, int c)
{
	int m = 0;
	while (m < maxMines)
	{
		int x = rand() % c;
		int y = rand() % r;
		if (matrix[x][y] != 1)
		{
			m++;
			matrix[x][y] = 1;
		}
	}
}

bool Attack(int x, int y)
{
	if (matrix[x][y] == 1)
	{
		matrix[x][y] = 2;
		return true;
	}
	return false;
}

int main()
{
	int pos1, pos2;
	char prompt;

	srand(time(NULL));
	cout << "Enter the number of rows..." << endl;
	cin >> rows;
	cout << "Enter the number of columns..." << endl;
	cin >> columns;
	cout << "Enter the number of mines..." << endl;
	cin >> maxMines;

	Clear(rows, columns);
	Draw(rows, columns);
	SetMines(rows, columns);

	while (1)
	{
		cout << "Enter input location...";
		cin >> pos1 >> pos2;
		if (Attack(pos1, pos2))
		{
			Draw(rows, columns);
			cout << "Game is Over!!" << endl;
			cout << "You are on the mine!" << endl;
			break;
		}
		else
		{
			cout << "There is no mine in this location..." << endl;
			cout << "Number of left mines is: " << NumberOfMines(rows, columns) << endl;
		}
	}

	system("pause");
	return 0;
}