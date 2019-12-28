#include<iostream>
using namespace std;

class A
{
private:
	int aa = 10;
public:
	virtual void a()
	{
		cout << "A::a()" << endl;
	}
};

class B
{
private:
	int bb = 20;
public:
	virtual void b()
	{
		cout << "B::b()" << endl;
	}
};

class D:public A,public B
{
private:
	int dd = 40;
public:
	virtual void d()
	{
		cout << "D::d()" << endl;
	}
};


