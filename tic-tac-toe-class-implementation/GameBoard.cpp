#include"GameBoard.h";


GameBoard::GameBoard()
{
	int digit = 49;
	for (int i = 0; i < 3; i = i + 1)
	{
		for (int j = 0; j < 3; j = j + 1)
		{
			data[i][j] = digit;
			digit = digit + 1;
		}
	}
}

void GameBoard::displayBoard()
{
	cout << " ____________\n";
	cout << "|            |" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "|";
		for (int j = 0; j < 3; j++)
		{
			cout << " " << data[i][j] << "  ";
		}
		cout << "|";
		cout << "\n";
	}
	cout << "|____________|" << endl;
}


void GameBoard::markBoard(char pos, char playerSymbol)
{
	while (!isValidPosition(pos))
	{
		cout << " the position is invalid  : enter again ";
		cin >> pos;
	}

	while (isAlreadyMarked(pos))
	{
		cout << " its already marked : enter again ";
		cin >> pos;
	}
	int boxNum = (int)pos-48;
	int i, j, y;
	int x = boxNum- 3;
	if (x <= 0)
	{
		i = 0;
		j = x + 2;
	}
	else
	{
		y = x - 4;
		if (y < 0)
		{
			i = 1;
			j = x - 1;
		}
		else
		{
			j = y;
			i = 2;
		}
	}

	data[i][j] = playerSymbol;
	validMovesCount = validMovesCount + 1;
}


bool GameBoard::isValidPosition(char pos)
{
	if ((((int)pos) - 48) >= 1 && (((int)pos) - 48) <= 9)
	{
		return true;
	}
	else
	{
		return false;
	}
}



bool GameBoard::isAlreadyMarked(char pos)
{
	int boxNum = (int)pos;
	boxNum = boxNum - 48;
	int i, j, y;
	int x = boxNum - 3;
	if (x <= 0)
	{
		i = 0;
		j = x + 2;
	}
	else
	{
		y = x - 4;
		if (y < 0)
		{
			i = 1;
			j = x - 1;
		}
		else
		{
			j = y;
			i = 2;
		}
	}

	if (((int)data[i][j] - 48) >= 1 && ((int)data[i][j] - 48) <= 9)
	{
		return false;
	}
	else
	{
		return true;
	}
}


bool GameBoard::isWin()
{
	int counter = 0;
	int j = 0;

	//row win check
	for (int i = 0; i < 3; i = i + 1)
	{
		if (data[i][j] == data[i][j + 1])
		{
			counter = counter + 1;

		}
		if (data[i][j + 1] == data[i][j + 2] && counter == 1)
		{
			return true;
		}
		counter = 0;

	}
	counter = 0;
	//col win check
	for (int i = 0; i < 3; i = i + 1)
	{
		if (data[i][j] == data[i+1][j])
		{
			counter = counter + 1;

		}
		if (data[i+1][j] == data[i+2][j] && counter == 1)
		{
			return true;
		}
		counter = 0;

	}
	counter = 0;
	//diagonal win check 1

	if (data[0][0] == data[1][1])
	{
		counter = counter + 1;
	}
	if (data[1][1] == data[2][2] && counter == 1)
	{
		return true;
	}
	counter = 0;
	//diagonal win check 2

	if (data[0][2] == data[1][1])
	{
		counter = counter + 1;
	}
	if (data[1][1] == data[2][0] && counter == 1)
	{
		return true;
	}

	
	return false;
}



int GameBoard::getValidMovesCount()
{
	return validMovesCount;
}


GameStatus GameBoard::getGameStatus()
{
	return gameStatus;
}


void GameBoard::setGameStatus(GameStatus gs)
{
	gameStatus = gs;
}

