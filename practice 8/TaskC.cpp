#include"TaskC.h"
void Employee::setFirstName(const char * p)
{
	copyString(firstName, p);
}

void Employee::setLastName(const char * p)
{
	copyString(lastName, p);
}

void Employee::setSalary(float s)
{
	if (s >= 0)
	{
		salary = s;
	}
}

const char * Employee::getFirstName()
{
	return firstName;
}

const char * Employee::getLastName()
{
	return lastName;
}

float Employee::getSalary()
{
	return salary;
}

void Employee::increaseSalary()
{
	float temp;
	temp = salary / 10;
	salary = salary + temp;
}

float getYearlySalary(float s)
{
	return s * 12;
}

Employee::Employee()
{
	char firstN[] = "first name invalid";
	char lastN []= "last name invalid ";

	copyString(firstName, firstN);
	copyString(lastName, lastN);
	salary = 100;
}

Employee::Employee(const char * firstN, const char * lastN, float s)
{
	copyString(firstName, firstN);
	copyString(lastName, lastN);
	salary = s;
}