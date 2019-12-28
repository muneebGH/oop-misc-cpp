#include"TicTacToePresentation.h"

void displayWinner(int x)
{
	if (x == 1)
	{
		cout << " player 1 won : " << endl;

	}
	else if (x == 2)
	{
		cout << "playe 2 won :" << endl;
	}
	else if (x == 3)
	{
		cout << "tie have occured " << endl;
	}
}


void draw(char(*p)[3])

{
	cout << " ____________\n";
	cout << "|            |" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "|";
		for (int j = 0; j < 3; j++)
		{
			cout << " " << p[i][j] << "  ";
		}
		cout << "|";
		cout << "\n";
	}
	cout << "|____________|" << endl;

}
