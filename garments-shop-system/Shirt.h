#ifndef SHIRT_H
#define SHIRT_H
#include"Upper.h"
class Shirt:public Upper
{
public:
	int calculatePrice();
	int getCollarSize();
	Shirt(CString n, int cz);
	Shirt();
};
#endif // !SHIRT_H
