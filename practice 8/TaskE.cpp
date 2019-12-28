#include"TaskE.h"
void Car::setModel(int m)
{
	if (m > 1885 && m < 2018)
	{
		model = m;
	}
}

void Car::setMaxSpeed(float maxS)
{
	maxSpeed = maxS;
}

void Car::setSpeed(int s)
{
	if (s < (int)maxSpeed)
	{
		speed = s;
	}
}

Car::Car(int m, const char * setMake, int s, float maxS)
{
	model = m;
	copyString(make, setMake);
	speed = s;
	maxSpeed = maxS;
}


Car::Car()
{
	char setMake[] = "toyota";
	copyString(make, setMake);
	model = 2000;
	maxSpeed = 200;
	speed = 0;
}
void Car::setMake(const char * m)
{
	copyString(make, m);
}


int Car::getSpeed()
{
	return speed;
}

int Car::getModel()
{
	return model;
}

float Car::getMaxSpeed()
{
	return maxSpeed;
}

char * Car::getMake()
{
	return make;
}

void Car::accelerate()
{
	setSpeed(speed + 5);
}

void Car::brake()
{
	if (speed >= 5)
	{
		setSpeed(speed - 5);
	}
}

