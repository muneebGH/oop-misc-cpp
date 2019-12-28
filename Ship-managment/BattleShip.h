#ifndef	BATTLESHIP_H
#define	BATTLESHIP_H
#include"Ship.h"
class BattleShip :public Ship
{
private:
	int missiles;
public:
	BattleShip(CString n, CString y, int m);
	void setMissiles(int m);
	int getMissiles();
	void print();
};
#endif 
