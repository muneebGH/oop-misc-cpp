#include"Trouser.h"
#include"CString.h"
int Trouser::calculatePrice()
{
	return getWaist() * 20 + 100;
}

int Trouser::getWaist()
{
	return Lower::getWaist() - 3;
}

Trouser::Trouser(CString name, int w):Lower(name,w)
{

}

Trouser::Trouser()
{

}