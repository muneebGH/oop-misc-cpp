
#include"TicTacToe.h"

void play(char(*box)[3])
{
	
	
	int playerNo = 2;
	char player = 'O';
	draw(box);
	int x;
	// start playing
	do
	{
		switchPlayer(player, playerNo);
		input(box, player, playerNo);
		system("cls");
		draw(box);

		x = checkWinner(box);

	} 
	while (x == 0);
	displayWinner(x);
	system("pause");
}


void switchPlayer(char &ch, int &PN)
{
	if (ch == 'X') 
	{
		ch = 'O';
		PN = 2;
	}
	else 
	{
		ch = 'X';
		PN = 1;
	}
}

void input(char(*p)[3], char ch, int PN) 
{
	int ascii;
	int i;
	int j;
	int x;
	int y;
	char input[20];
	bool validator1,validator2;
	int boxNum;
	do
	{

		do
		{
			cout << "Player " << PN << " : enter the number of box " << endl;
			cin.getline(input, 20);
			boxNum = convertToInteger(input);
			
			if (boxNum>=1 && boxNum<=9)
			{
				validator1 = true;
			}
			else
			{
				validator1 = false;
			}
		}
		while (validator1 == false);

		
		x = boxNum - 3;
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
		if ((int)p[i][j] >= 48 && (int)p[i][j] <= 57)
		{
			validator2 = true;
		}
		else
		{
			validator2 = false;
		}
	}
	while (validator2 == false);
	p[i][j] = ch;
}

int checkWinner(char(*p)[3])
{
	int counter = 0;
	int j = 0;
	int x;
	//rows checker

	x = rowChecker(p);
	if (x != 0) 
	{
		return x;
	}
	//coloumn check
	x = coloumnChecker(p);
	if (x != 0)
	{
		return x;
	}
	//diagonal one check
	x = diagonalOneCheck(p);
	if (x != 0)
	{
		return x;
	}

	//diagonal 2 check

	x = diagonalTwoCheck(p);
	if (x != 0) 
	{
		return x;
	}
	//tie check
	x = tieCheck(p);
	if (x != 0)
	{
		return x;
	}
	return 0;
}



int rowChecker(char(*p)[3]) 
{
	int counter = 0;
	int j = 0;
	for (int i = 0; i < 3; i++)
	{
		if (p[i][j] == p[i][j + 1]) 
		{
			counter = counter + 1;
		}if (p[i][j + 1] == p[i][j + 2])
		{
			counter = counter + 1;
		}
		if (p[i][j] == 'X') 
		{
			if (counter == 2) 
			{
				return 1;
			}
		}
		else if (p[i][j] == 'O')
		{
			if (counter == 2) 
			{
				return 2;
			}
		}
		else 
		{
			counter = 0;
		}
		counter = 0;
	}
	return 0;
}


int coloumnChecker(char(*p)[3]) 
{
	int counter = 0;
	int j = 0;
	for (int i = 0; i < 3; i++) 
	{
		if (p[j][i] == p[j + 1][i])
		{
			counter = counter + 1;
		}
		if (p[j][i] == p[j + 2][i]) 
		{
			counter = counter + 1;
		}
		if (counter == 2 && p[j][i] == 'X')
		{
			return 1;
		}
		else if (counter == 2 && p[j][i] == 'O')
		{
			return 2;
		}
		else
		{
			counter = 0;
		}counter = 0;
	}
	return 0;
}


int diagonalOneCheck(char(*p)[3])
{
	int counter = 0;
	int j = 0;
	if (p[0][0] == p[1][1])
	{
		counter = counter + 1;
	}
	if (p[0][0] == p[2][2]) 
	{
		counter = counter + 1;
	}
	if (counter == 2 && p[0][0] == 'X')
	{
		return 1;
	}
	else if (counter == 2 && p[0][0] == 'O')
	{
		return 2;
	}
	else
	{
		counter = 0;
	}
	return 0;
}

int diagonalTwoCheck(char(*p)[3])
{
	int counter = 0;
	int j = 0;

	if (p[0][2] == p[1][1]) 
	{
		counter = counter + 1;
	}
	if (p[0][2] == p[2][0]) 
	{
		counter = counter + 1;
	}
	if (counter == 2 && p[0][2] == 'X')
	{
		return 1;
	}
	else if (counter == 2 && p[0][2] == 'O') 
	{
		return 2;
	}
	else 
	{
		counter = 0;
	}
	return 0;
}

int tieCheck(char(*p)[3])
{
	int counter = 0;
	int j = 0;
	for (int i = 0; i < 3; i++) 
	{
		for (int k = 0; k < 3; k++)
		{
			if (p[i][k] == 'X' || p[i][k] == 'O') 
			{
				counter = counter + 1;
			}
		}
	}
	if (counter == 9) 
	{
		return 3;
	}
	else 
	{
		counter = 0;
	}
	return 0;
}





