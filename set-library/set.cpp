#include"set.h"
void createSet(int ** set, int n) 
{
	*set = new int[n];
}



bool addElement(int *set, int *noe, int capacity, int element)
{
	bool check1 = searchElement(set, *noe, element);
	bool check2 = isFull(*noe, capacity);
	if (check1 == true || check2==true)
	{
		return false;
	}
	

	set[*noe] = element;
	*noe = *noe + 1;
	return true;
}



bool searchElement(int * set, int noe, int element) 
{

	for (int i = 0; i < noe; i++) 
	{

		if (set[i] == element) 
		{
			return true;
		}
	}

	return false;
}


bool removeElement(int * set, int * noe, int capacity, int element)
{

	int position;
	int i;
	bool status;
	int NOE = *noe;
	status = searchElement(set, NOE, element);
	if (status == true) 
	{
		position = searchElementPosition(set, *noe, element);

		set[position] = set[*noe - 1];
		*noe = *noe - 1;
		return true;
	}
	else 
	{
		return false;
	}

}


int searchElementPosition(int * set, int noe, int element)
{
	bool status;
	status = searchElement(set, noe, element);
	if (status == true)
	{
		for (int i = 0; i < noe; i++) 
		{
			if (element == set[i]) 
			{
				return i;
				
			}
		}
	}
	else 
	{
		return -1;
	}

}
bool isEmpty(int noe)
{

	if (noe > 0) 
	{
		return true;
	}

	return false;
}

bool isFull(int noe, int capacity)
{

	if (noe == capacity) 
	{
		return true;
	}
	else 
	{
		return false;
	}

}
void displaySet(int * set, int noe) 
{

	for (int i = 0; i < noe; i++) 
	{
		cout << set[i] << " :";
	}

}
int * calcIntersection(int * setA, int * setB, int setANoe, int setBNoe, int *newSetNoe, int *newSetCapacity)
{

	*newSetCapacity = setANoe + setBNoe;
	int * C;
	int k = 0;
	createSet(&C, *newSetCapacity);
	for (int i = 0; i < setANoe; i++) 
	{
		for (int j = k; j < setBNoe; j++)
		{
			if (setA[i] == setB[j]) 
			{
				addElement(C,newSetNoe, *newSetCapacity, setA[i]);

			}
		}
	}
	return C;
}


int isSubset(int * setA, int * setB, int Anoe, int Bnoe) 
{
	int setCCapacity = 0;
	int setCnoe = 0;
	int * setC;
	setC = calcIntersection(setA, setB, Anoe, Bnoe, &setCnoe, &setCCapacity);
	if (setCnoe < Anoe) 
	{
		return 0;
	}
	else if (setCnoe == Anoe && setCnoe == Bnoe) 
	{
		return 2;
	}
	else if (setCnoe == Anoe && setCnoe != Bnoe)
	{
		return 1;
	}

}
void reSize(int **setA, int *setAnoe, int * setACapacity, int newSize)
{
	int * temp;
	
	int tempCapacity = newSize;
	int tempNoe =*setAnoe;
	createClone(*setA, *setAnoe, *setACapacity,&temp,&tempNoe,&tempCapacity);
	delete[] * setA;
	*setA = 0;
	createClone(temp, tempNoe, tempCapacity, setA, &tempNoe, &tempCapacity);
	delete[] temp;
	temp = 0;
	*setAnoe = newSize;
	*setACapacity = newSize;



}

void createClone(int * sourceSet, int sourceNoe, int sourceCapacity, int ** targetSet, int * targetNoe, int * targetCapacity) 
{


	createSet(&(*targetSet), *targetCapacity);
	
	for (int i = 0; i <*targetCapacity; i++) 
	{
		if (i >sourceNoe)
		{
			*targetSet[i] = 0;
		}
		else
		{
			*targetSet[i] = sourceSet[i];
	
		}
	}
	
}

void deAllocateSet(int ** set)
{
	delete[] * set;
	set = 0;
}