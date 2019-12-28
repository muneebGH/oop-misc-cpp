#include<iostream>
#include"set.h"
using namespace std;


void createSet(Set & setA, int n)
{

	setA.capacity = n;
	setA.data = new int[setA.capacity];
}

bool addElement(Set & setA, int element)
{
	if (isFull(setA) == true)
	{
		return false;
	}

	if (searchElement(setA, element) == true)
	{
		return false;
	}
	setA.data[setA.noOfElements] = element;
	setA.noOfElements = setA.noOfElements + 1;
	return true;
}

bool isFull(Set setA)
{
	if (setA.noOfElements == setA.capacity)
	{
		return true;
	}
	else
	{
		return false;
	}
}



bool searchElement(Set setA, int element)
{
	for (int i = 0; i < setA.noOfElements; i = i + 1)
	{
		if (setA.data[i] == element)
		{
			return true;
		}
	}

	return false;
}


int searchElementPosition(Set setA, int element)
{

	for (int i = 0; i < setA.noOfElements; i = i + 1)
	{
		if (setA.data[i] == element)
		{
			return i;
		}
	}
	return -1;
}


bool isEmpty(Set setA)
{
	if (setA.noOfElements == 0)
	{
		return true;
	}

	return false;
}


void displaySet(Set setA)
{
	for (int i = 0; i < setA.noOfElements; i = i + 1)
	{
		cout << setA.data[i] << " ";
	}
}


Set setIntersection(Set setA, Set setB)
{
	bool forNothing;
	Set setC;
	
	createSet(setC, setA.noOfElements);
	for (int i = 0; i < setA.noOfElements; i = i + 1)
	{
		for (int j = 0; j < setB.noOfElements; j = j + 1)
		{
			if (setA.data[i] == setB.data[j])
			{
				forNothing = addElement(setC, setA.data[i]);
			}
		}
	}


	return setC;
}

Set calcUnion(Set setA, Set setB)
{
	bool forNothing;
	int pos;
	Set ABunion;
	int capacity = setA.noOfElements + setB.noOfElements;
	createSet(ABunion, capacity);
	Set ABintersection;
	createSet(ABintersection, setA.noOfElements);
	ABintersection = setIntersection(setA, setB);
	for (int i = 0; i < ABintersection.noOfElements; i = i + 1)
	{
		pos = searchElementPosition(setB, ABintersection.data[i]);
		swap(setB, pos, i);
	}

	for (int i = 0; i < setA.noOfElements; i = i + 1)
	{
		forNothing = addElement(ABunion, setA.data[i]);
	}

	for (int i = ABintersection.noOfElements; i < setB.noOfElements; i = i + 1)
	{
		forNothing = addElement(ABunion, setB.data[i]);
	}
	
	return ABunion;
}


Set setDifference(Set setA, Set setB)
{
	bool doNothing;
	int counter = 0;
	Set diff;
	createSet(diff, setA.noOfElements);
	for (int i = 0; i < setA.noOfElements; i = i + 1)
	{
		for (int j = 0; j < setB.noOfElements; j = j + 1)
		{
			if (setA.data[i] == setB.data[j])
			{
				counter = counter + 1;
			}
		}
		if (counter == 0)
		{
			doNothing = addElement(diff, setA.data[i]);
		}
		counter = 0;
	}

	return diff;
}


int isSubset(Set setA, Set setB)
{
	int counter = 0;
	Set ABintersection;
	createSet(ABintersection, setA.noOfElements);
	ABintersection = setIntersection(setA, setB);
	if (ABintersection.noOfElements == setA.noOfElements)
	{
		counter = counter + 1;
	}
	if (setA.noOfElements == setB.noOfElements)
	{
		counter = counter + 1;
	}

	if (ABintersection.noOfElements != setA.noOfElements)
	{
		counter = 0;
	}

	return counter;

}


void reSize(Set & setA, int newSize)
{
	
	setA.capacity = newSize;
	if (newSize >= setA.noOfElements)
	{
		setA.noOfElements = setA.noOfElements;
	}
	else
	{
		setA.noOfElements = newSize;
	}
	
	Set temp=createClone(setA);
	deAllocateSet(setA);
	setA = createClone(temp);
	deAllocateSet(temp);

	

}



Set createClone(Set & setA)
{
	
	Set clone;
	createSet(clone, setA.capacity);

	for (int i = 0; i < setA.noOfElements; i = i + 1)
	{

		clone.data[i] = setA.data[i];
	}
	clone.noOfElements = setA.noOfElements;
	clone.capacity = setA.capacity;
	return clone;
}


void swap(Set & setA, int index1, int index2)
{
	int temp = setA.data[index1];
	setA.data[index1] = setA.data[index2];
	setA.data[index2] = temp;
}

void deAllocateSet(Set & setA)
{
	delete[] setA.data;
	setA.capacity = 0;
	setA.noOfElements = 0;
	setA.data = nullptr;
}