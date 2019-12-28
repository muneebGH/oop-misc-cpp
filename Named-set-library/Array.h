#include<iostream>
using namespace std;

class Array
{
private:
	int * data;
	int capacity;
	int isValidIndex(int index) const
	{
		return index >= 0 && index < capacity;
	}
public:
	Array(int cap);
	~Array();
	int & getSet(int index);
	const int getSet(int index)const;
	int getCapacity()const;
	void reSize(int newCap);
	Array(const Array & ref);
	//Array(int argumentCount = 0, ...);
	void display()const;
	void display(const Array & ref);
	Array operator=(const Array & ref);
};