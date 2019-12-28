#include<iostream>
#include"MyOOPString.h"
using namespace std;
class Employee
{private:
	char firstName[100];
	char lastName[100];
	float salary;
public:
	Employee();
	Employee(const char * firstN, const char * last, float s);
	void setFirstName(const char *);
	void setLastName(const char *);
	void setSalary(float s);
	const char * getFirstName();
	const char * getLastName();
	float getSalary();
	void increaseSalary();
};

float getYearlySalary(float s);