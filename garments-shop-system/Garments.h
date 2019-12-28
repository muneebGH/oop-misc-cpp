#ifndef GARMENTS_H
#define GARMENTS_H
#include<iostream>
#include"CString.h"
using namespace std;
class Garments
{
private:
	CString name;
public:
	Garments(CString n="not set");
	virtual int calculatePrice() = 0;
	CString getName();
};

#endif
