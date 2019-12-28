#include"Ship.h"
Ship::Ship(CString n, CString y) :name(n), year(y)
{

}

void Ship::setName(CString n)
{
	if (!n.isEmpty())
	{
		name = n;
	}
}

void Ship::setYear(CString y)
{
	if (!y.isEmpty())
	{
		year = y;
	}
}

CString Ship::getName()
{
	return name;
}

CString Ship::getYear()
{
	return year;
}


void Ship::print()
{
	cout << "name :"; name.display(); cout << endl;
	cout << "year : "; year.display(); cout << endl;

}
