#include"set.h"
int main()
{

	int *setA;
	int capacity = 10;
	int noe = 0;
	createSet(&setA, capacity);
	addElement(setA, &noe, capacity, 10);
	addElement(setA, &noe, capacity, 20);
	addElement(setA, &noe, capacity, 30);
	addElement(setA, &noe, capacity, 40);
	addElement(setA, &noe, capacity, 50);

	int * clonned;
	int noe2 = 3;
	int capacity2 = 3;
	createClone(setA, noe, capacity, &clonned,&noe2,&capacity2);
	displaySet(clonned, 3);


	system("pause");
	system("pause");
	return 0;
}