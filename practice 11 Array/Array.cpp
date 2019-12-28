#include"Array.h"
Array::~Array()
{
	if (data)
	{
		delete[] data;
		data = nullptr;
		capacity = 0;
	}

}


int & Array::getSet(int index)
{
	if (isValidIndex(index))
	{
		return data[index];
	}
	else
	{
		exit(0);
	}

}

const int Array::getSet(int index)const
{
	if (isValidIndex(index))
	{
		return data[index];
	}
	else
	{
		exit(0);
	}
}

int Array::getCapacity()const
{
	return capacity;
}

int Array::reSize(int newCap)
{
	if (newCap <= 0)
	{
		this->~Array();
		return;
	}

	int * ptr = new int[newCap];
	memcpy(ptr, data, (newCap < capacity ? newCap : capacity) * sizeof(int));
	this->~Array();
	data = ptr;
	capacity = newCap;
}

Array::Array(const Array & ref)
{
	if (ref.data == 0)
	{
		this->data = 0;
		capacity = 0;
		return;
	}

	capacity = ref.capacity;
	data = new int[capacity];
	memcpy(data, ref.data, (capacity * sizeof(int)));

}

Array::Array(int argumentCount , ...)
{
	if (argumentCount <= 0)
	{
		data = 0;
		capacity = 0;
		return;
	}

	capacity = argumentCount;
	data = new int[capacity];
	va_list vl;
	va_start(vl, argumentCount);

	for (int i = 0; i < argumentCount; i = i + 1)
	{
		data[i] = va_arg(vl, int);
	}

	va_end(vl);
	
}



void Array::display()
{
	for (int i = 0; i < capacity; i = i + 1)
	{
		cout << data[i] << " : ";
	}
}

void Array::display(const Array & ref)
{
	for (int i = 0; i < ref.capacity; i = i + 1)
	{
		cout << ref.data[i] << " : ";
	}
}