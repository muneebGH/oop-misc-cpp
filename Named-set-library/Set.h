#include<iostream>
#include"Array.h"
using namespace std;
class Set
{
private:
	Array data;
	int  noOFElements;
public:
	Set(int cap);
	void insert(int element);
	void remove(int element);
	void print()const;
	int getCardinality()const;
	int isMember(int val)const;
	int isSubset(const Set & ref);
	Set CalcIntersection(const Set & ref);
	void reSize(int newCapacity);
	Set(const Set & ref);
	Set calcUnion(const Set & ref);
	Set calcDifference(const Set & ref);
	Set operator = (const Set & ref);
 };

