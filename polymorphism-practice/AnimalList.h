#include"Animal.h"
class AnimalList:public Animal
{
private:
	Animal ** animallist;
	int noOfElements;
	int capacity;
public:
	AnimalList();
	AnimalList(int cap);
	AnimalList(const AnimalList & ref);
	void addAnimal(Animal & p);
	void reSize(int newaCap);
	void startMenu();
	~AnimalList();

};