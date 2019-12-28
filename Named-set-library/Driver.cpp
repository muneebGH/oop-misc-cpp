#include"NamedSet.h"
int main()
{

	Set s1(5);
	Set s2(5);
	for (int i = 0; i < 5; i++)
	{
		s1.insert(i + 1);
	}
	for (int i = 0; i < 4; i++)
	{
		s2.insert(i + 5);
	}
	NamedSet ns("ns", s1);
	NamedSet ns2("ns2", s2);
	ns.print();
	ns2.print();
	ns = ns2;
	ns.CalcIntersection(ns2).print();
	system("pause");
	return 0;
	
}