#ifndef SHOPPINGLIST_H
#define SHOPPINGLIST_H

#include"Pajama.h"
#include"Shirt.h"
#include"Trouser.h"
class ShoppingList:Pajama,Shirt,Trouser
{
private:
	Garments ** p;
	int cap;
	int noe;
public:
	ShoppingList();
	ShoppingList(int c);
	ShoppingList(const ShoppingList & ref);
	void addShirt(CString n, int cz);
	void addPajama(CString n, int w);
	void addTrouser(CString n, int w);
	void removeElement(int index);
	~ShoppingList();


};

#endif