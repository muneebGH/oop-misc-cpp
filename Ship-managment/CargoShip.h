#ifndef CARGOSHIP_H
#define	CARGOSHIP_H
#include"Ship.h"
class CargoShip :public Ship
{
private:
	int capacity;
public:
	CargoShip(CString n, CString y, int c);
	void setCapacity(int c);
	int getCapacity();
	void print();
};
#endif 
