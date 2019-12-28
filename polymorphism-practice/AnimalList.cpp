#include"AnimalList.h"
AnimalList::AnimalList()
{
	capacity = 0;
	noOfElements = 0;
	animallist = nullptr;
}

AnimalList::AnimalList(int cap)
{
	capacity = cap;
	animallist = new Animal *[capacity];
	noOfElements = 0;
	
}

void AnimalList::addAnimal(Animal & p)
{
	if (noOfElements < capacity)
	{
		animallist[noOfElements] = &p;
		noOfElements = noOfElements + 1;

	}
	else
	{

		reSize(capacity + 1);
		animallist[noOfElements] = &p;
		noOfElements = noOfElements + 1;

	}
}

void AnimalList::reSize(int newCap)
{
	AnimalList tempCopy(*this);
	this->~AnimalList();
	animallist = new Animal *[newCap];
	for (int i = 0; i < capacity; i = i + 1)
	{
		animallist[i] = tempCopy.animallist[i];
	}

}


AnimalList::~AnimalList()
{
	delete animallist;
	animallist = nullptr;
	
}


AnimalList::AnimalList(const AnimalList & ref)
{
	if (this->animallist)
	{
		this->~AnimalList();
	}
	capacity = ref.capacity;
	noOfElements = ref.noOfElements;
	animallist = new Animal *[capacity];

	for (int i = 0; i <noOfElements;i=i+1)
	{
		animallist[i] = ref.animallist[i];
	}

}


void AnimalList::startMenu()
{
	char ch = 'y';
	while (ch = 'y')
	{
		int choice;

		for (int i = 0; i < noOfElements; i = i + 1)
		{
			cout << "press " << i + 1 << " for animal "; animallist[i]->getName().display();
			cout << endl;

		}
		cin >> choice;
		animallist[choice - 1]->sound();
		cout << "press some y to enter again" << endl;
		cin >> ch;
	}

}

