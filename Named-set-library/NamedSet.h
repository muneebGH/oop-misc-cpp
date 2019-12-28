#include"Set.h"
#include"CString.h"
class NamedSet:public Set
{
private: 
	CString name;
	NamedSet(const Set & ref);
public:
	NamedSet(CString n,Set s);
	NamedSet(const NamedSet & ref);
	NamedSet CalcIntersection(const NamedSet & ref);
	NamedSet calcUnion(const NamedSet & ref);
	NamedSet calcDifference(const NamedSet & ref);
	NamedSet operator = (const NamedSet & ref);
	NamedSet operator =(const Set & ref);
	void print();
};