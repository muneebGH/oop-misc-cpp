#ifndef SHIP_H
#define SHIP_H
#include<iostream>
#include"CString.h"
using namespace std;
class Ship
{
private:
	CString name;
	CString year;
public:
	Ship(CString n="not set", CString year="not set");
	void setName(CString n);
	CString getName();
	void setYear(CString y);
	CString getYear();
	virtual void print();
};
#endif
