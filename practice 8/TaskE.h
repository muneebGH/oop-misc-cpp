#include<iostream>
#include"MyOOPString.h"
using namespace std;

class Car
{private:
	int model;
	char make[30];
	int speed;
	float maxSpeed;
public:
	Car();
	Car(int m, const char * setMake, int s, float maxS);
	void setModel(int m);
	void setMake(const char * m);
	void setSpeed(int s);
	void setMaxSpeed(float maxS);
	int getModel();
	char * getMake();
	int getSpeed();
	float getMaxSpeed();
	void accelerate();
	void brake();
};