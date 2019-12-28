#include"TaskA.h"


void Rectangle::setLength(int l)
{
	if (l>0)
	{
		length = l;
	}
}


void Rectangle::setWidth(int w)
{
	if (w > 0)
	{
		width = w;
	}
}


int Rectangle::getLength()
{
	return length;
}


int Rectangle::getWidth()
{
	return width;
}


bool Rectangle::isSquare()
{
	if (length == width)
	{
		return true;
	}
	else
	{
		return false;
	}
}


int Rectangle::getArea()
{
	return length * width;
}

int Rectangle::getPerimeter()
{
	int perimeter = 0;
	perimeter = (length * 2) + (width * 2);
	return perimeter;
}


Rectangle::Rectangle()
{
	length = 0;
	width = 0;
}



Rectangle::Rectangle(int l, int w)
{
	length = l;
	length = w;
}

