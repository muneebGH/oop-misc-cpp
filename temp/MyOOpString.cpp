
#include"MyOOPString.h"

int getStringLength(const char * p)
{

	int length = 0;

	while (p[length] != '\0')
	{
		length = length + 1;
	}
	return length;
}



void concatenate(char * destination, char * source)
{
	int length1 = getStringLength(destination);
	int length2 = getStringLength(source);
	int totalLength = length1 + length2;
	int j = 0;
	for (int i = length1; i < totalLength; i++)
	{
		destination[i] = source[j];
		j++;
	}
	destination[totalLength] = '\0';
}




void copyString(char * destination,const char * source)
{
	int length1 = getStringLength(source);
	
	for (int i = 0; i < length1; i++)
	{
		destination[i] = source[i];
	}
	
	destination[length1] = '\0';
	
}

void insertString(char * destination, char * source, int index)
{
	int lengthDestination = getStringLength(destination);
	int lengthSource = getStringLength(source);
	int totalLoopCount = lengthDestination - index;
	int startIndex = lengthDestination - 1;
	int nextIndex = startIndex + lengthSource;
	for (int i = 0; i < totalLoopCount; i++) {
		destination[nextIndex] = destination[startIndex];
		startIndex--;
		nextIndex--;
	}

	for (int i = 0; i < lengthSource; i++) {
		destination[index] = source[i];
		index++;

	}
	int newLength = lengthDestination + lengthSource;
	destination[newLength] = '\0';
}




int convertToInteger(char * source)
{
	int num = 0;
	double tempNum;
	int length = getStringLength(source);
	int toPow = length - 1;
	for (int i = 0; i < length; i++)
	{
		tempNum = (int)source[i];
		tempNum = tempNum - 48;
		tempNum=tempNum*pow(10, toPow);
		toPow=toPow-1;
		num = num + (int)tempNum;

	}

	return num;
}



float convertToFloat(char * source)
{
	// deptb 1
	int lengthTotal = 0;
	lengthTotal = getStringLength(source);
	int lengthBeforeDot = 0;
	char ch = source[0];
	while (ch != '.')
	{
		lengthBeforeDot = lengthBeforeDot + 1;
		ch = source[lengthBeforeDot];
	}

	int lengthAfterDot = lengthTotal - (lengthBeforeDot + 1);
	char * p1 = new char[lengthBeforeDot];
	for (int i = 0; i < lengthBeforeDot; i = i + 1)
	{
		p1[i] = source[i];
	}
	p1[lengthBeforeDot] = '\0';

	int numBeforeDot = convertToInteger(p1);




	char * p2 = new char[lengthAfterDot];
	int j = lengthBeforeDot + 1;
	for (int i = 0; i < lengthAfterDot; i = i + 1)
	{
		p2[i] = source[j];
		j = j + 1;
	}
	p2[lengthAfterDot] = '\0';

	int numAfterDot = convertToInteger(p2);


	float number1 = (float)numBeforeDot;
	float number2 = (float)numAfterDot;

	float toDivide = (float)pow(10, lengthAfterDot);

	number2 = number2 / toDivide;
	number1 = number1 + number2;
	return number1;


}


int findSubString(char * destination,const char * key, int start)
{
	int keystart = 0;
	int counter = 0;

	int length = getStringLength(destination);
	int lengthKey = getStringLength(key);


	for (int i = start; i < length; i++)
	{

		if (destination[i] == key[keystart])
		{
			int start2 = i;

			for (int j = 0; j < lengthKey; j++)
			{
				if (destination[start2] == key[j])
				{
					counter++;
					start2++;
				}
			}

			if (counter == lengthKey)
			{
				return i;
			}
			counter = 0;
		}
	}




	return -1;

}




int findSubString(char * destination, char ch, int start)
{



	int length = getStringLength(destination);
	for (int i = start; i < length; i++)
	{
		if (destination[i] == ch)
		{
			return i;
		}
	}

	return -1;
}






int insertString(char * destination, int index, char ch)
{



	int length = getStringLength(destination);
	for (int i = length; i > index; i--)
	{
		destination[i] = destination[i - 1];
	}
	destination[index] = ch;




	return length + 1;
}




int remove(char * destination, int count)
{

	if (count > 0)
	{
		int length = getStringLength(destination);
		int counter = length - count;
		for (int i = 0; i < counter; i++)
		{
			destination[i] = destination[i + count];
		}

		destination[counter] = '\0';
		for (int i = counter + 1; i < length; i++)
		{
			destination[i] = 0;
		}

		return length - count;
	}
	else if(count<0)
	{

		int length = getStringLength(destination);
		int counter = length +count;
		destination[counter] = '\0';
		for (int i = counter + 1; i < length; i++)
		{
			destination[i] = 0;
		}
		return length+count;
	}
	else
	{
		return getStringLength(destination);
	}

}

int removeSubString(char * destination, char * source, int indexx)
{

	int destinationLength = getStringLength(destination);
	int sourceLength = getStringLength(source);
	if (indexx > destinationLength)
	{
		return destinationLength;
	}

	int keyIndex = findSubString(destination, source, indexx);
	int from = sourceLength + keyIndex;
	int loopCount = destinationLength - from;
	for (int i = 0; i < loopCount; i++)
	{
		destination[keyIndex] = destination[from];
		keyIndex++;
		from++;
	}
	int newSize = destinationLength - sourceLength;
	destination[newSize] = '\0';
	return newSize;
}



int remove(char * destination, char ch)
{
	int index = findSubString(destination, ch, 0);
	int length = getStringLength(destination);
	int loopCount = length - index;

	for (int i = 0; i < loopCount; i++)
	{
		destination[index] = destination[index + 1];
		index++;
	}
	length--;
	destination[length] = '\0';
	return length;
}


void trim(char * destination)
{
	int length = getStringLength(destination);

	char ch = ' ';
	char ch2 = '\n';
	char ch3 = '\t';
	char ch4 = '\r';
	int start = 0;
	for (int i = 0; i < length; i++)
	{
		int index1 = findSubString(destination, ch, start);
		int index2 = findSubString(destination, ch2, start);
		int index3 = findSubString(destination, ch3, start);
		int index4 = findSubString(destination, ch4, start);

		if (index1 != -1)
		{
			remove(destination, ch);

		}
		if (index2 != -1)
		{
			remove(destination, ch2);

		}
		if (index3 != -1)
		{
			remove(destination, ch3);

		}
		if (index4 != -1)
		{
			remove(destination, ch4);

		}


	}




}






void replace(char * destination, char * old, char * newOne)
{
	int lengthDestination = getStringLength(destination);
	int lengthOld = getStringLength(old);
	int lengthNew = getStringLength(newOne);
	int index = findSubString(destination, old, 0);
	int length2 = removeSubString(destination, old, index);
	insertString(destination, newOne, index);
}



void makeUpperCase(char * destination)
{
	int length = getStringLength(destination);
	for (int i = 0; i < length; i++)
	{
		if (((int)destination[i]) >= 97 && ((int)destination[i]) <= 122)
		{
			destination[i] = destination[i] - 32;
		}
	}
}


void makeLower(char * destination)
{

	int length = getStringLength(destination);
	for (int i = 0; i < length; i++)
	{
		if (((int)destination[i]) >= 65 && ((int)destination[i]) <= 90)
		{
			destination[i] = destination[i] + 32;
		}
	}

}



void reverse(char * destination)
{
	int length = getStringLength(destination);
	int start = 0;
	int loopCount = length / 2;
	for (int i = 0; i < loopCount; i=i+1)
	{
		char temp = destination[length - 1];
		destination[length - 1] = destination[start];
		destination[start] = temp;
		start=start+1;
		length=length-1;
	}
	


}





int compare(char * a, char * b, bool caseSensitive)
{
	if (caseSensitive == true)
	{
		int lengthA = getStringLength(a);
		int lengthB = getStringLength(b);
		int counter = 0;
		for (int i = 0; i < lengthA; i++)
		{
			if ((int)a[i] == (int)b[i])
			{
				counter++;
			}
		}
		if (lengthA == lengthB && counter == lengthA )
		{
			return 0;
		}
		else if (lengthA < lengthB && counter == lengthA)
		{
			return 1;
		}
		else if (lengthA > lengthB && counter == lengthB)
		{
		return -1;
		}
		
	}
	else
	{
		int lengthA = getStringLength(a);
		int lengthB = getStringLength(b);
		int counter = 0;
		for (int i = 0; i < lengthA; i++)
		{
			int x = (int)a[i];
			int y = (int)b[i];
			if (x == y || (x - 32) == y || (x + 32) == y) {
				counter++;
			}
		}
			if (lengthA == lengthB && counter == lengthA && counter == lengthB)
			{
				return 0;
			}
			else if (lengthA < lengthB && counter == lengthA)
			{
				return 1;
			}
			else if (lengthA > lengthB && counter == lengthB)
			{
				return -1;
			}
		



	}
	return 0;
}




