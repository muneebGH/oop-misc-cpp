#include"Shirt.h"
int Shirt::calculatePrice()
{
	return getCollarSize() * 20 + 10;
}


int Shirt::getCollarSize()
{
	return Upper::getCollarSize()-1;
}

Shirt::Shirt(CString n, int cz) :Upper(n, cz)
{

}

Shirt::Shirt()
{

}