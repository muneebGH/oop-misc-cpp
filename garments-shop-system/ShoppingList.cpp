#include"ShoppingList.h"
ShoppingList::ShoppingList()
{
	p = nullptr;
	noe = 0;
	cap = 0;
}


ShoppingList::ShoppingList(int c)
{
	cap = c > 0 ? c : 0;

	p = new Garments * [cap];
	noe = 0;
}

void ShoppingList::addPajama(CString n, int w)
{
	if (noe<cap)
	{
		p[noe] = new Pajama(n, w);
		noe = noe + 1;
	}
	else
	{

	}
}


void ShoppingList::addTrouser(CString n, int w)
{
	if (noe < cap)
	{
		p[noe] = new Trouser(n, w);
		noe = noe + 1;
	}
}

void ShoppingList::addShirt(CString n, int cz)
{
	if (noe < cap)
	{
		p[noe] = new Shirt(n, cz);
		noe= noe + 1;
	}
	else
	{

	}

}


void ShoppingList::removeElement (int index)
{
	ShoppingList temp(*this);
	this->~ShoppingList();
	cap = temp.cap;
	p = new Garments *[cap];
	for (int  i = 0; i < noe; i++)
	{

	}
}


ShoppingList::ShoppingList(const ShoppingList & ref)
{

	noe = ref.noe;
	cap = ref.cap;
	p = new Garments *[cap];
	for (int i = 0; i < noe; i = i + 1)
	{
		p[i] = ref.p[i];
	}

}


ShoppingList::~ShoppingList()
{
	if (p)
	{
		delete p;
		p = nullptr;
	}
}