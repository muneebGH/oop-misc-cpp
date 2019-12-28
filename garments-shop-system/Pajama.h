#ifndef PAJAMA_H
#define PAJAMA_H
#include"Lower.h"
class Pajama:public Lower
{
public:
	int calculatePrice();
	int getWaist();
	Pajama(CString n, int w);
	Pajama();
};
#endif // ! PAJAMA_H
