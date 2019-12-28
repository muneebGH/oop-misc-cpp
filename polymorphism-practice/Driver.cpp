#include<iostream>
#include"AnimalList.h"
using namespace std;

class cat :public Animal
{
private:
	CString name = "cat";

public:
	void sound()
	{
		cout << "speak cat" << endl;
	}
	
	CString getName()
	{
		return name;
	}

};


class dog :public Animal
{
private:
	CString name = "dog";
public:
	void sound()
	{
		cout << "speak dog" << endl;
	}

	CString getName()
	{
		return name;
	}

};



class rat :public Animal
{
private:
	CString name = "rat";
public:
	void sound()
	{
		cout << "speak rat" << endl;
	}

	CString getName()
	{
		return name;
	}
};

int main()
{
	AnimalList al(5);
	cat kitten;
	dog doggy;
	rat ratty;
	al.addAnimal(kitten);
	al.addAnimal(doggy);
	al.addAnimal(ratty);
	
	al.startMenu();
	system("pause");
	return 0;
}
