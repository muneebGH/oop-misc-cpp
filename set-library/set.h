#include<iostream>
using namespace std;

void createSet(int ** set, int n);
bool addElement(int *set, int * noe, int capacity, int element);
bool searchElement(int * set, int noe, int element);
bool removeElement(int * set, int * noe, int capacity, int element);
int searchElementPosition(int * set, int noe, int element);
bool isEmpty(int noe);
bool isFull(int noe, int capacity);
void displaySet(int * set, int noe);
int * calcIntersection(int * setA, int * setB, int setANoe, int setBNoe, int *newSetNoe, int *newSetCapacity);
int isSubset(int * setA, int * setB, int Anoe, int Bnoe);
void createClone(int * sourceSet, int sourceNoe, int sourceCapacity, int ** targetSet, int * targetNoe, int * targetCapacity);
void deAllocateSet(int ** set);
void reSize(int **setA, int *setAnoe, int * setACapacity, int newSize);