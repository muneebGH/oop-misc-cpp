#include"set.h"
#include<iostream>
using namespace std;
int main()
{
	Set setA;
	createSet(setA, 5);
	addElement(setA, 4);
	addElement(setA, 5);
	addElement(setA, 6);
	addElement(setA, 7);
	addElement(setA, 8);
	
	reSize(setA, 6);
	displaySet(setA);

	system("pause");
}