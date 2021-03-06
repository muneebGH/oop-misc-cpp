#include"pch.h"
#include"WordZap.h"

void getNoOFPlayers(int & NOofPlayers)
{
	do
	{
		cout << "enter number of players " << endl;
		cin >> NOofPlayers;
	} while (NOofPlayers <= 0);

}

void getDataOfPlayers(player * players,int NoOfPlayers) 
{	
	char name[30];
	cin.ignore();
	for (int i = 0; i < NoOfPlayers; i++)
	{
		
		cout << " Enter the name of player " << i + 1 << endl;
		cin.getline(name,30);
		copyString(players[i].name, name);
		
	}
	
	srand(time(0));
	for (int i = 0; i < NoOfPlayers; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			
			int x=getRandomInRange(97, 122);
			players[i].playerLetters[j] =(char) x;
		}
		players[i].playerLetters[7] = '\0';
	}



}



void showTurn(player * players,int playerNo) {
	cout << players[playerNo-1].name << " : its your turn ";
	cout << "your letters are ";
	int i = 0;
	char ch = players[playerNo-1].playerLetters[i];
	cout << " { ";
	while (ch != '\0')
	{
		cout << ch;
		i=i+1;
		ch = players[playerNo-1].playerLetters[i];
	}
	cout << " } ";
}



bool getInput(player * players, int & playerNo, int NoOfPlayers)
{
	char inLetters[200];
	int counter = 0;
	int k = 0;
	int indexes[200];
	int z = 0;
	int l = 0;
	cout << " enter a word to play (or press enter to pass )" << endl;
	cin.getline(inLetters, 200);
	int lengthInLetters = getLength(inLetters);
	int lengthPlayerLetters = getLength(players[playerNo - 1].playerLetters);
	if (inLetters[0] == '\0')
	{
		srand(time(0));
		int x = getRandomInRange(97, 122);
		players[playerNo - 1].playerLetters[lengthPlayerLetters] = x;
		players[playerNo - 1].playerLetters[lengthPlayerLetters + 1] = '\0';
		return false;
	}
	else
	{
		for (int i = 0; i < lengthInLetters; i++)
		{
			for (int j = l; j < lengthPlayerLetters; j++)
			{

				if (inLetters[i] == players[playerNo - 1].playerLetters[j])
				{

					char temp = players[playerNo - 1].playerLetters[j];
					players[playerNo - 1].playerLetters[j] = players[playerNo - 1].playerLetters[k];
					players[playerNo - 1].playerLetters[k] = temp;
					k++;
					counter++;
					l++;
					break;
				}

			}

		}
		if (counter == lengthInLetters)
		{
			for (int i = 0; i < counter; i++)
			{
				removeElement(players, playerNo, 0);
			}
			return true;
		}
		else
		{
			return false;
		}
		
	}

}



void removeElement(player * players, int playerNo, int index)
{
	int length = getLength(players[playerNo - 1].playerLetters);

	for (int i = index; i < length; i++)
	{
		players[playerNo - 1].playerLetters[i] = players[playerNo - 1].playerLetters[i+ 1];
	}
	players[playerNo - 1].playerLetters[length - 1] = '\0';
}



bool win(player * players, int playerNo)
{
	int length = getStringLength(players[playerNo - 1].playerLetters);
	if (length==0)
	{
		return true;

	}
	return false;
}
int getRandomInRange(int lowerBound, int upperBound) {
	return lowerBound + rand() % (upperBound - lowerBound + 1);
}

void switchPlayer(int & playerNo, int NoOfPlayers) {
	if (playerNo == NoOfPlayers)
	{
		playerNo = 1;
	}
	else
	{
		playerNo++;
	}
}


int getLength(char * destination) {
	int i = 0;
	int length = 0;
	char ch;
	ch = destination[i];
	while (ch != '\0')
	{
		length++;
		i++;
		ch = destination[i];
	}
	return length;
}






