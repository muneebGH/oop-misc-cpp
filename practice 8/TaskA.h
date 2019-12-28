#include<iostream>
using namespace std;
class Rectangle
{private:
	int length;
	int width;
public:
	Rectangle();
	Rectangle(int l, int w);
	void setLength(int l);
	void setWidth(int w);
	int getLength();
	int getWidth();
	bool isSquare();
	int getArea();
	int getPerimeter();
};