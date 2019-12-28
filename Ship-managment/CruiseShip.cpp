#include"CruiseShip.h"
CruiseShip::CruiseShip(CString n, CString y, int mp) :Ship(n, y)
{
	if (mp > 0)
	{
		maxPassengers = mp;
	}
	else
	{
		maxPassengers = 0;
	}
}

void CruiseShip::setMaxPassengers(int mp)
{
	if (mp > 0)
	{
		maxPassengers = mp;
	}
	else
	{
		maxPassengers = 0;
	}
}

int CruiseShip::getMaxPassengers()
{
	return maxPassengers;
}

void CruiseShip::print()
{
	Ship::print();
	cout << "maximum passengers " << maxPassengers << endl;
}
