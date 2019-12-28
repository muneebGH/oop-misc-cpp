#ifndef CRUISESHIP_H
#define	CRUISESHIP_H
#include"Ship.h"
class CruiseShip:public Ship
{
private:
	int maxPassengers;
public:
	CruiseShip(CString n, CString y, int mp);
	void setMaxPassengers(int mp);
	int getMaxPassengers();
	void print();
};
#endif 
