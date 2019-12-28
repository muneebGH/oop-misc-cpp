#include"TicTacToe.h"
void TicTacToe::gamePlay()
{
	GameBoard GB;
	char symbolA, symbolB,pos;
	bool check;
	do
	{
		cout << "enter the character  for player 1 :  ";
		cin >> symbolA;
		check = GB.isValidPosition(symbolA);
	} while (check);

	do
	{
		cout << "enter the character  for player 2 :  ";
		cin >> symbolB;
		check = GB.isValidPosition(symbolA);
	} 
	while (check);

	system("cls");
	PlayerTurn PT = FIRST_PLAYER;
	GB.setGameStatus(IN_PROGRESS);
	GB.displayBoard();
	do
	{
	
		cout << "enter the position for player " << PT << " : ";
		cin >> pos;
		GB.markBoard(pos, symbolA);
		GB.displayBoard();
		int movesCount = GB.getValidMovesCount();
		if (movesCount== 9)
		{
			GB.setGameStatus(DRAW);
		}
		else if (GB.isWin())
		{
			GB.setGameStatus(WIN);
		}

		if (GB.getGameStatus() == IN_PROGRESS)
		{
			
			PT = SECOND_PLAYER;
			cout << "enter the position for player " << PT << "  :";
			cin >> pos;
			GB.markBoard(pos, symbolB);
			GB.displayBoard();
			int movesCount = GB.getValidMovesCount();
			if (movesCount== 9)
			{
				GB.setGameStatus(DRAW);
			}
			else if (GB.isWin())
			{
				GB.setGameStatus(WIN);
			}

		}
	}
	while (GB.getGameStatus() == IN_PROGRESS);

	if (GB.getGameStatus() == WIN)
	{
		cout << " player " << PT << " have won " << endl;
	}
	else
	{
		cout << "draw have occurred " << endl;
	}
}