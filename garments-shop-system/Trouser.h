#ifndef TROUSER_H
#define TROUSER_H
#include"Lower.h"
#include"CString.h"
class Trouser:public Lower 
{
public:
	Trouser(CString name, int waist);
	int calculatePrice();
	int getWaist();
	Trouser();

};
#endif 
