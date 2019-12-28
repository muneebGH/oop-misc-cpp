#include"CString.h"
#include<iostream>
using namespace std;
class Animal
{
	CString name = "";
public:
	Animal();
	virtual void sound();
	virtual CString getName()
	{
		return name;
	}
	
};