#include"CarApplication.h"
void carApplication()
{
	Car a;
	a.setMaxSpeed(250);
	a.setModel(2016);
	a.setMake("Toyota");
	cout << a.getMake() << " : " << a.getModel() << ": Max speed " << a.getMaxSpeed() << endl;
	cout << a.getSpeed() << endl;
	a.accelerate();
	cout << a.getSpeed() << endl;
	a.accelerate();
	cout << a.getSpeed() << endl;
	a.accelerate();
	cout << a.getSpeed() << endl;
	a.accelerate();
	cout << a.getSpeed() << endl;
	a.accelerate();
	cout << a.getSpeed() << endl;
	a.brake();
	cout << a.getSpeed() << endl;
	a.brake();
	cout << a.getSpeed() << endl;
	a.brake();
	cout << a.getSpeed() << endl;
	a.brake();
	cout << a.getSpeed() << endl;
	a.brake();
	cout << a.getSpeed() << endl;

}