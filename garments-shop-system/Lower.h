#ifndef LOWER_H
#define LOWER_H
#include"Garments.h"
class Lower:public Garments
{
private:
	int waist;
public:
	Lower(CString n="not set",int w=0);
	virtual int getWaist() = 0;
};
#endif // !LOWER_H
