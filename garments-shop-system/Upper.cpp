#include"Upper.h"
int Upper::getCollarSize()
{
	return collarSize;
}

Upper::Upper(int cz)
{
	collarSize = cz;
}


Upper::Upper(CString n, int cz) :Garments(n), collarSize(cz)
{

}
