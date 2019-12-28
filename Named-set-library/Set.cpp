#include"Set.h"
Set::Set(int cap):data(cap)
{
	noOFElements = 0;
}


void Set::insert(int element)
{
	data.getSet(noOFElements) = element;
	noOFElements = noOFElements + 1;

}


void Set::remove(int element)
{
	int index = isMember(element);
	if (index == -1)
	{
		return;
	}


	for (int i = index; i < noOFElements; i = i + 1)
	{
		data.getSet(i) = data.getSet(i + 1);
	}
	noOFElements = noOFElements - 1;

}

void Set::print() const
{
	for(int i = 0; i < noOFElements; i = i + 1)
	{
		cout << data.getSet(i) << ": ";
	}
	cout << endl;
}
int Set::getCardinality() const
{
	return noOFElements;
}

int Set::isMember(int val)const
{

	for (int i = 0; i < noOFElements; i = i + 1)
	{
		if (data.getSet(i) == val)
		{
			return i;
		}
	}
	return -1;
}

int Set::isSubset(const Set & ref)
{
	Set intersection = CalcIntersection(ref);
	if (intersection.noOFElements < noOFElements)
	{
		return 0;
	}
	else if (intersection.noOFElements == noOFElements && intersection.noOFElements == ref.noOFElements)
	{
		return 2;
	}
	else if (intersection.noOFElements == noOFElements && intersection.noOFElements != ref.noOFElements)
	{
		return 1;
	}
	else
	{
		return 1;
	}

}


Set Set::CalcIntersection(const Set & ref)
{
	int search;
	Set ret(noOFElements);
	for (int i = 0; i < noOFElements; i = i + 1)
	{
		search = ref.isMember(data.getSet(i));
		if (search >= 0)
		{
			ret.insert(data.getSet(i));
		}
	}

	return  ret;
}

void Set::reSize(int newCapacity)
{
	data.reSize(newCapacity);
	noOFElements = newCapacity < noOFElements ? newCapacity : noOFElements;
}

Set::Set(const Set & ref) :data(ref.data)
{
	noOFElements = ref.noOFElements;
}

Set Set::calcUnion(const Set & ref)
{
	int unionCapacity = noOFElements + ref.noOFElements;
	Set Ret(unionCapacity);
	Set intersection = CalcIntersection(ref);
	for (int i = 0; i < intersection.noOFElements; i = i + 1)
	{
		Ret.insert(intersection.data.getSet(i));
	}


	for (int i = 0; i < noOFElements; i = i + 1)
	{
		if (ref.isMember(data.getSet(i)) < 0 && Ret.isMember(data.getSet(i))<0)
		{
			Ret.insert(data.getSet(i));
		}
	}
	


	for (int i = 0; i < ref.noOFElements; i = i + 1)
	{
		if (isMember(ref.data.getSet(i)) < 0 && Ret.isMember(ref.data.getSet(i)) < 0)
		{
			Ret.insert(ref.data.getSet(i));
		}
	}


	return Ret;
}

Set Set::calcDifference(const Set & ref)
{
	Set diff(noOFElements);
	for (int i = 0; i < noOFElements; i = i + 1)
	{
		if (ref.isMember(data.getSet(i)) < 0)
		{
			diff.insert(data.getSet(i));
		}
			
	}

	return diff;
}


Set Set::operator=(const Set & ref)
{

	noOFElements = ref.noOFElements;
	data = ref.data;
	return *this;
}