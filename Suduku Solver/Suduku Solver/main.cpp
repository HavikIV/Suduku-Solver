// This program is for solving sudoku puzzles

#include <iostream>

using namespace std;

//(&p)[9][9]
bool solvePuzzle(int p[][9]);
bool withinRow(int x, int row, int p[][9]);
bool withinColumn(int x, int col, int p[][9]);
bool withinSquare(int x, int row, int col, int p[][9]);
bool canAdd(int x, int row, int col, int p[][9]);
bool FindUnassignedLocation(int grid[][9], int &row, int &col);
void printGrid(int p[][9]);

int main()
{
	// create a 2 dimensional array to represent the sudoku puzzle
	int sPuzzle[9][9] = { NULL };

	// add the given values
	// first row
	sPuzzle[0][2] = 4;
	sPuzzle[0][3] = 2;
	sPuzzle[0][5] = 1;
	// second row
	sPuzzle[1][2] = 6;
	sPuzzle[1][4] = 4;
	sPuzzle[1][8] = 5;
	// third row
	sPuzzle[2][2] = 1;
	sPuzzle[2][4] = 9;
	sPuzzle[2][8] = 4;
	// fourth row
	sPuzzle[3][1] = 9;
	sPuzzle[3][2] = 2;
	sPuzzle[3][8] = 6;
	// fifth row
	sPuzzle[4][1] = 4;
	sPuzzle[4][3] = 6;
	sPuzzle[4][5] = 3;
	sPuzzle[4][7] = 5;
	// sixth row
	sPuzzle[5][0] = 6;
	sPuzzle[5][6] = 1;
	sPuzzle[5][7] = 2;
	// seventh row
	sPuzzle[6][0] = 8;
	sPuzzle[6][4] = 3;
	sPuzzle[6][6] = 5;
	// eighth row
	sPuzzle[7][0] = 2;
	sPuzzle[7][4] = 5;
	sPuzzle[7][6] = 9;
	// ninth row
	sPuzzle[8][3] = 9;
	sPuzzle[8][5] = 8;
	sPuzzle[8][6] = 7;

	int grid[9][9] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
	{ 5, 2, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 8, 7, 0, 0, 0, 0, 3, 1 },
	{ 0, 0, 3, 0, 1, 0, 0, 8, 0 },
	{ 9, 0, 0, 8, 6, 3, 0, 0, 5 },
	{ 0, 5, 0, 0, 9, 0, 6, 0, 0 },
	{ 1, 3, 0, 0, 0, 0, 2, 5, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 7, 4 },
	{ 0, 0, 5, 2, 0, 6, 3, 0, 0 } };

	printGrid(sPuzzle);
	cout << "Solving the puzzle..." << endl;

	// function call to solve the puzzle
	if (solvePuzzle(sPuzzle) == true)
	{
		printGrid(sPuzzle);
	}
	else
	{
		cout << "NO SOLUTION!" << endl;
	}
}

bool solvePuzzle(int p[][9])
{
	int row, col;
	if (!FindUnassignedLocation(p, row, col))
	{
		return true;
	}
	for (int num = 1; num < 10; num++)
	{
		if (canAdd(num, row, col, p))
		{
			p[row][col] = num;
			if (solvePuzzle(p))
			{
				return true;
			}
			p[row][col] = NULL;
		}
	}
	return false;
}

bool FindUnassignedLocation(int grid[][9], int &row, int &col)
{
	for (row = 0; row < 9; row++)
	{
		for (col = 0; col < 9; col++)
		{
			if (grid[row][col] == NULL)
			{
				return true;
			}
		}
	}
	return false;
}

bool withinRow(int x, int row, int p[][9])
{
	for (int col = 0; col < 9; col++)
	{
		if (p[row][col] == x)
		{
			return true;
		}
	}
	return false;
}

bool withinColumn(int x, int col, int p[][9])
{
	for (int row = 0; row < 9; row++)
	{
		if (p[row][col] == x)
		{
			return true;
		}
	}
	return false;
}

bool withinSquare(int x, int startRow, int startCol, int p[][9])
{
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			if (p[row + startRow][col + startCol] == x)
			{
				return true;
			}
		}
	}
	return false;
}

bool canAdd(int x, int row, int col, int p[][9])
{
	return !withinRow(x, row, p) && !withinColumn(x, col, p)
		&& !withinSquare(x, row - (row % 3), col - (col % 3), p);
}

void printGrid(int p[][9])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << p[i][j] << " ";
		}
		cout << endl;
	}
}