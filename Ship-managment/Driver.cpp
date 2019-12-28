#include"BattleShip.h"
#include"CargoShip.h"
#include"CruiseShip.h"
int main()
{
	CruiseShip cs("cruise ship", "2018", 25);
	CargoShip cs2("cargo ship", "2019", 25);
	BattleShip bs("battle ship", "2020", 25);
	Ship ** p = new Ship *[3];
	p[0] = &cs;
	p[1] = &cs2;
	p[2] = &bs;
	for (int i = 0; i < 3; i = i + 1)
	{
		p[i]->print();
	}
		system("pause");
	return 0;
}