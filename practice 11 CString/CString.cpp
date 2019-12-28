#include"CString.h"

CString::CString()
{
	data = nullptr;
	size = 0;
}

CString::CString(const  char c)
{
	size = 2;
	data = new char[size];
	data[0] = c;
	data[1] = '\0';
}


CString::CString(const char * p)
{
	int length = getLength(p);
	size = length + 1;
	data = new char[size];
	for (int i = 0; i < size; i = i + 1)
	{
		data[i] = p[i];
	}
	data[size-1] = '\0';
}


CString::CString(const CString & ref)
{
	if (ref.data==0)
	{
		this->data = 0;
		this->size = 0;
		return;
	}

	size = ref.size;
	data = new char[size];
	int refLength = ref.getLength();
	for (int i = 0; i < refLength; i = i + 1)
	{
		data[i] = ref.data[i];
	}
	data[refLength] = '\0';

}

CString::~CString()
{
	if (data)
	{
		delete[] data;
		data = nullptr;
	}
		size = 0;

	
}

void CString::input()
{

	char ch;
	size = 2;
	data = new char[size];
	int counter = 0;
	cin.get(ch);
	int i = 0;
	while (ch != '\n')
	{
		counter = counter + 1;
		data[i] = ch;
		if ((counter + 1) >= size)
		{
			reSize((size * 2));
		}
		i = i + 1;
		cin.get(ch);
	}
	data[i] = '\0';
}


char & CString::at(int index)
{
	if (data && (index >= 0 && index < getLength()))
	{
		return data[index];
	}
	exit(0);
}


const char & CString::at(int index)const
{

	if (data && (index >= 0 && index <getLength()))
	{
		return data[index];
	}
	exit(0);
}


bool CString::isEmpty()const
{
	if (getLength() == 0)
	{
		return true;
	}

	return false;
}


int CString::getLength()const
{
	int length = 0;
	while (data[length] != '\0')
	{
		length = length + 1;
		
	}
	return length;
}




void CString::display()const
{
	cout << data << endl;
}




int CString::find(CString subStr, int start) const
{
	if (start < 0 || start >= getLength())
	{
		return -1;
	}
	int counter = 0;
	int length = subStr.getLength();
	int tempCounter = 0;
	int length2 = getLength();
	int toReturn;
	int j = 0;
	for (int i = start; i <length2; i = i + 1)
	{
		if (data[i] == subStr.data[j])
		{
			j = j + 1;
			counter = counter + 1;
			tempCounter += 1;
			if (counter == 1)
			{
				toReturn = i;
			}
			if (counter == length)
			{
				return toReturn;
			}
		}
		else
		{
			j = 0;
			counter = 0;
			if (tempCounter > counter)
			{
				tempCounter = 0;
				i = i - 1;
			}
		}

	}
	return -1;

}


void CString::insert(int index, CString subStr)
{

	int lengthA = subStr.getLength();
	
	int lengthB = getLength();
	int newSize = (lengthA + lengthB) + 1;
	reSize(newSize);
	int totalLoopCount = 0;
	totalLoopCount = lengthB - index;
	int j = lengthB;
	for (int i = 0; i < totalLoopCount + 1; i = i + 1)
	{
		data[j + lengthA] = data[j];
		j = j - 1;
	}

	for (int i = 0; i < lengthA; i = i + 1)
	{
		data[i + index] = subStr.data[i];
	}
	data[lengthA + lengthB] = '\0';
}




void CString::remove(int index, int count)
{
	int loopCount = getLength() - index;
	loopCount = loopCount - count;
	for (int i = 0; i < loopCount; i = i + 1)
	{
		data[i + index] = data[(i + index) + count];
	}

	int newLength = getLength() - (count - 1);
	reSize(newLength);
}


int CString::replace(CString old, CString newSubStr)
{

	int counter = 0;
	int findIndex = find(old);
	while (findIndex >= 0)
	{
		remove(findIndex,old.getLength());
		insert(findIndex, newSubStr);
		counter = counter + 1;
		findIndex = find(old, (findIndex + newSubStr.getLength()));
	}
	return counter;
}



void CString::trimLeft()
{
	int i = 0;
	char ch = data[i];
	while (ch == ' ' || ch == '\n' || ch == '\t' || ch == '\r')
	{
		i = i + 1;
		ch = data[i];
	}
	if (i == 0)
	{
		return;
	}
	remove(0, i);
}


void CString::trimRight()
{

	int i = getLength()-1;
	int check = i;
	char ch = data[i];
	while (ch == ' ' || ch == '\n' || ch == '\t' || ch == '\r')
	{
		i = i - 1;
		ch = data[i];
	}
	if (check == i)
	{
		return;
	}
	remove(getLength()-(i-1), i-1);

}


void CString::trim()
{
	trimLeft();
	trimRight();
}




void CString::makeUpper()
{

	for (int i = 0; i < size; i++)
	{
		if (((int)data[i]) >= 'a' && ((int)data[i]) <= 'z')
		{
			data[i] = data[i] - 32;
		}
	}
}







void CString::makeLower()
{
	for (int i = 0; i < size; i++)
	{
		if (((int)data[i]) >= 65 && ((int)data[i]) <= 90)
		{
			data[i] = data[i] + 32;
		}
	}

}




void CString::reverse()
{
	char temp;
	int start = 0;
	int length = size - 2;
	int loopCount = length / 2;
	for (int i = 0; i < loopCount; i = i + 1)
	{
		temp = data[start];
		data[start] = data[length - i];
		data[length - i] = temp;
		start = start + 1;
	}



}




void CString::reSize(int newSize)
{
	int i = 0;
	char * temp = new char[newSize];
	int length = getLength();
	while (i < newSize - 1 && i < length)
	{
		temp[i] = data[i];
		i = i + 1;
	}

	temp[i] = '\0';
	delete[] data;
	size = newSize;
	data = temp;
}



int CString::comapre(CString S2) const
{
	int counter = 0;
	int length1 = getLength();
	int length2 = S2.getLength();
	for (int i = 0; i < length1 && length2; i = i + 1)
	{
		if ((int)data[i] == (int)S2.data[i])
		{
			counter = counter + 1;
		}
		else if ((int)data[i] < (int)S2.data[i])
		{
			return -1;
		}
		else if ((int)data[i] > (int)S2.data[i])
		{
			return 2;
		}
	}
	
	if (counter == length1 && counter == length2)
	{
		return 0;
	}
	else if (counter < length2)
	{
		return -1;
	}
	else
	{
		return 2;
	}
}




CString CString::left(int count)
{
	if (count > getLength())
	{
		exit(0);
	}

	CString left;
	left.size = count + 1;
	left.data = new char[left.size];
	for (int i = 0; i < count; i = i + 1)
	{
		left.data[i] = data[i];
	}
	left.data[(left.size)-1] = '\0';
	

	remove(0, count);
	return left;
}




CString CString::right(int count)
{
	CString right;
	if (count > getLength())
	{
		exit(0);
	}
	right.size = count + 1;
	right.data = new char[size];
	int index = size - count;
	int j = getLength()-count;
	for (int i = 0; i < count; i = i + 1)
	{
		right.data[i] = data[j];
		j += 1;
	}

	right.data[right.size-1] = '\0';
	

	remove(getLength() - count, count);
	return right;
}




int CString::toInteger()const
{

	int num = 0;
	double tempNum;
	int length = getLength();
	int toPow = length - 1;
	for (int i = 0; i < length; i++)
	{
		tempNum = (int)data[i];
		tempNum = tempNum - 48;
		tempNum = tempNum * pow(10, toPow);
		toPow = toPow - 1;
		num = num + (int)tempNum;

	}

	return num;
	
}


float CString::toFloat()const
{
	int lengthTotal = 0;
	lengthTotal = getLength();
	int lengthBeforeDot = 0;
	char ch = data[0];
	while (ch != '.')
	{
		lengthBeforeDot = lengthBeforeDot + 1;
		ch = data[lengthBeforeDot];
	}

	int lengthAfterDot = lengthTotal - (lengthBeforeDot + 1);
	char * p1 = new char[lengthBeforeDot];
	for (int i = 0; i < lengthBeforeDot; i = i + 1)
	{
		p1[i] = data[i];
	}
	p1[lengthBeforeDot] = '\0';



	int numBeforeDot = 0;
	double tempNum;
	int length = lengthBeforeDot;
	int toPow = length - 1;
	for (int i = 0; i < length; i++)
	{
		tempNum = (int)p1[i];
		tempNum = tempNum - 48;
		tempNum = tempNum * pow(10, toPow);
		toPow = toPow - 1;
		numBeforeDot = numBeforeDot + (int)tempNum;

	}


	



	char * p2 = new char[lengthAfterDot];
	int j = lengthBeforeDot + 1;
	for (int i = 0; i < lengthAfterDot; i = i + 1)
	{
		p2[i] = data[j];
		j = j + 1;
	}
	p2[lengthAfterDot] = '\0';


	

	int numAfterDot = 0;
	
	length = lengthAfterDot;
	toPow = length - 1;
	for (int i = 0; i < length; i++)
	{
		tempNum = (int)p2[i];
		tempNum = tempNum - 48;
		tempNum = tempNum * pow(10, toPow);
		toPow = toPow - 1;
		numAfterDot = numAfterDot + (int)tempNum;

	}

	


	float number1 = (float)numBeforeDot;
	float number2 = (float)numAfterDot;

	float toDivide = (float)pow(10, lengthAfterDot);

	number2 = number2 / toDivide;
	number1 = number1 + number2;
	return number1;

}




CString CString::concact(CString s2)const
{
	CString s3;
	s3.size =getLength() + s2.getLength();
	s3.size = s3.size + 1;
	s3.data = new char[s3.size];
	int i;
	for (i= 0; i <getLength(); i = i + 1)
	{
		s3.data[i] = data[i];
	}

	int k = 0;
	for (int j = i; j < s3.size-1; j = j + 1)
	{
		s3.data[j] = s2.data[k];
		k += 1;
	}

	s3.data[s3.size-1] = '\0';
	return s3;



}



void CString::concatEqual(CString s2)
{

	int index = size-1;

	int newSize = getLength() + s2.getLength();
	newSize += 1;
	this->reSize(newSize);

	int j = 0;
	for (int i = index; i < size; i = i + 1)
	{
		data[i] = s2.data[j];
		j = j + 1;
	}

	this->data[size-1] = '\0';
}



CString CString::tokenize(CString delim)
{
	int lengthDelim = delim.getLength();
	int min=0;
	for (int i = 0; i < lengthDelim; i = i + 1)
	{
		int index =this->find(delim.data[i]);
		
		if (i == 0 && index>=0)
		{
			min = index;
		}
		else if (i > 0 && index < min)
		{
			min = index;
		}


	}


	CString toReturn;
	toReturn.size = min + 1;
	toReturn.data = new char[toReturn.size];
	for (int i = 0; i < min; i = i + 1)
	{
		toReturn.data[i] = this->data[i];
	}
	toReturn.data[toReturn.size - 1] = '\0';
	this->remove(0, min);
	return toReturn;

}




int CString::getLength(const char * p)const
{
	int length = 0;
	while (p[length] != '\0')
	{
		length = length + 1;
	}

	return length;
}