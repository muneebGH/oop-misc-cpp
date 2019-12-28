#include<iostream>
using namespace std;
class A
{
	int a;
public:
	A()
	{
		cout << "A::A()" << endl;
	
	}
	A(int c)
	{
		cout << "A::A(int)" << endl;
	}

	~A()
	{
		cout << "A::~A()" << endl;
		
	}

};

class B
{
	int b;
public:
	B()
	{
		cout << "B::B()" << endl;
	}

	B(int b)
	{
		cout << "B::B(int)" << endl;
	}


	~B()
	{
		cout << "B::~B()" << endl;
	}
	
};



class C:public B,public A
{
	int c;
public:
	C()
	{
		cout << "C::C()" << endl;
	}

	C(int c)
	{
		cout << "C::C(int)" << endl;
	}


	~C()
	{
		cout << "C::~C()" << endl;
	}
};



class D:public C
{
	int d;
public:
	D()
	{
		cout << "D::D()" << endl;
	}

	D(int d)
	{
		cout << "D:;D(int)" << endl;
	}


	~D()
	{
		cout << "D::~D()" << endl;
	}
};