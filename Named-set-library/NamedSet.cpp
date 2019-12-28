#include"NamedSet.h"
NamedSet::NamedSet(CString n,Set s):Set::Set(s),name(n)
{

}

NamedSet::NamedSet(const NamedSet & ref):Set(ref),name(ref.name)
{

}

NamedSet::NamedSet(const Set & ref) : Set(ref),name("not set")
{
}


NamedSet NamedSet::CalcIntersection(const NamedSet & ref)
{
	NamedSet y=Set::CalcIntersection(ref);
	return y;

}


NamedSet NamedSet::calcUnion(const NamedSet & ref)
{
	NamedSet y = Set::calcUnion(ref);
	return y;

}


NamedSet NamedSet::calcDifference(const NamedSet & ref)
{
	NamedSet y = Set::calcDifference(ref);
	return y;

}


NamedSet NamedSet::operator=(const NamedSet & ref)
{
	Set::operator=(ref);
	name = ref.name;
	return *this;
}


NamedSet NamedSet::operator=(const Set & ref)
{
	Set::operator=(ref);
	return  *this;
}

void NamedSet::print()
{
	name.display();
	Set::print();
}