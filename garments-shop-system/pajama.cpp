#include"Pajama.h"
int Pajama::getWaist()
{
	return Lower::getWaist() - 2;
}

int Pajama::calculatePrice()
{
	return getWaist() * 15 + 50;
}


Pajama::Pajama(CString n, int cz) :Lower(n, cz)
{

}

Pajama::Pajama()
{

}
