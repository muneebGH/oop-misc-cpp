#ifndef UPPER_H
#define UPPER_H

#include"Garments.h"
class Upper:public Garments
{
private:
	int collarSize;
public:
	Upper(CString n="not set", int cz=0);
	Upper(int cz);
	virtual int getCollarSize() = 0;
};

#endif