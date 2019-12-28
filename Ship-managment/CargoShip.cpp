#include"CargoShip.h"
CargoShip::CargoShip(CString n, CString y, int c) :Ship(n, y)
{
	if (c > 0)
	{
		capacity = c;
	}
	else
	{
		capacity = 0;
	}
}

void CargoShip::setCapacity(int c)
{
	if (c > 0)
	{
		capacity= c;
	}
	else
	{
		capacity = 0;
	}
}

int CargoShip::getCapacity()
{
	return capacity;
}


void CargoShip::print()
{

	cout << "ship name"; Ship::getName().display(); cout << endl;
	cout <<"ship capacity " << capacity << endl;
}


