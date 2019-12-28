#include"BattleShip.h"
BattleShip::BattleShip(CString n, CString y, int m) :Ship(n, y)
{
	if (m > 0)
	{
		missiles = m;
	}
	else
	{
		missiles = 0;
	}
}

void BattleShip::setMissiles(int m)
{
	if (m > 0)
	{
		missiles = m;
	}
	else
	{
		missiles = 0;
	}
}

int BattleShip::getMissiles()
{
	return missiles;
}


void BattleShip::print()
{

	cout << "ship name"; Ship::getName().display(); cout << endl;
	cout << "missiles" << missiles << endl;
}
