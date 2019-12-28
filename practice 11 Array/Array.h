#include<iostream>
using namespace std;

class Array
{
private:
	int * data;
	int capacity;
	int isValidIndex(int index) const
	{
		if (index >= 0 && index < capacity);
	}
public:
	~Array();
	int & getSet(int index);
	const int getSet(int index)const;
	int getCapacity()const;
	int reSize(int newCap);
	Array(const Array & ref);
	Array(int argumentCount = 0, ...);
	void display();
	void display(const Array & ref);
};