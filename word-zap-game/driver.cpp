#include"pch.h"
#include"WordZap.h"
using namespace std;

int main()
{
	int NOofPlayers = 0;
	int playerNo = 1;
	getNoOFPlayers(NOofPlayers);
	player * players = new player[NOofPlayers];
	getDataOfPlayers(players, NOofPlayers);
	bool what;
	bool what2;
	//play
	do
	{
		showTurn(players, playerNo);
		do
		{
			what = getInput(players, playerNo, NOofPlayers);
			what2 = win(players, playerNo);
			if (what2 == true)
			{
				break;
			}

		} while (what);
		what = win(players, playerNo);
		if (what == false)
		{
			switchPlayer(playerNo, NOofPlayers);
		}
	} while (what == false);

	cout << playerNo << " :" << players[playerNo - 1].name << " won" << endl;
}
