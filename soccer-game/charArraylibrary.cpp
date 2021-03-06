#include"pch.h"
#include <iostream>
#include<cmath>
#include"charArrayLibrary.h"
using namespace std;



int getStringLength(char * p)
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




void copyString(char * destination, char * source)
{
	int length1 = getStringLength(source);
	int j = 0;
	for (int i = 0; i < length1; i++)
	{
		destination[i] = source[i];
		j = i;
	}
	j++;
	destination[j] = '\0';
	cout << destination << endl;
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
	int tempNum;
	int multiply = 0;
	int length = getStringLength(source);
	int toPow = length - 1;
	for (int i = 0; i < length; i++)
	{
		tempNum = (int)source[i];
		tempNum = tempNum - 48;
		multiply = pow(10, toPow);
		toPow--;
		tempNum = tempNum * multiply;
		num = num + tempNum;

	}

	return num;
}



float convertToFloat(char * source)
{
	// it have bugs 

	int dot;
	float num = 0.0;
	int length = getStringLength(source);
	for (int i = 0; i < length; i++)
	{
		if ((int)source[i] == 46)
		{
			dot = i;
			break;
		}
	}

	float multiply = 0;
	float tempNum = 0;
	float toPow = dot - 1;
	for (int i = 0; i < dot; i++)
	{

		tempNum = (float)source[i];
		tempNum = tempNum - 48;
		multiply = pow(10, toPow);
		toPow--;
		tempNum = tempNum * multiply;
		num = num + tempNum;





	}
	dot++;


	toPow = -1;

	for (int i = dot; i < length - 2; i++
		) {

		tempNum = (float)source[i];
		tempNum = tempNum - 48;
		multiply = pow(10, toPow);
		toPow--;
		num = num + tempNum;




	}



	return num;


}




int findSubString(char * destination, char * key, int start)
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
			destination[i] = destination[i + 3];
		}

		destination[counter] = '\0';
		for (int i = counter + 1; i < length; i++)
		{
			destination[i] = 0;
		}

		return length - count;
	}
	else
	{

		int length = getStringLength(destination);
		int counter = length - (-count);
		destination[counter] = '\0';
		for (int i = counter + 1; i < length; i++)
		{
			destination[i] = 0;
		}
		return length - (-count);
	}

}

int removeSubString(char * destination, char * source, int indexx)
{

	int destinationLength = getStringLength(destination);
	int sourceLength = getStringLength(source);


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

	int start = 0;
	int counter = 0;

	for (int i = 0; i < length; i++)
	{
		int index = findSubString(destination, ch, start);



		if (index > 1)
		{
			start = index + 1;
			counter++;


		}

	}
	for (int i = 0; i < counter; i++)
	{
		int x = remove(destination, ch);
	}



	//


	length = getStringLength(destination);

	ch = '\n';

	start = 0;
	counter = 0;

	for (int i = 0; i < length; i++)
	{
		int index = findSubString(destination, ch, start);



		if (index > 1)
		{
			start = index + 1;
			counter++;


		}

	}
	for (int i = 0; i < counter; i++)
	{
		int x = remove(destination, ch);
	}

	length = getStringLength(destination);

	ch = '\t';

	start = 0;
	counter = 0;

	for (int i = 0; i < length; i++)
	{
		int index = findSubString(destination, ch, start);



		if (index > 1)
		{
			start = index + 1;
			counter++;


		}

	}
	for (int i = 0; i < counter; i++)
	{
		int x = remove(destination, ch);
	}

	length = getStringLength(destination);

	ch = '\r';

	start = 0;
	counter = 0;

	for (int i = 0; i < length; i++)
	{
		int index = findSubString(destination, ch, start);



		if (index > 1)
		{
			start = index + 1;
			counter++;


		}

	}
	for (int i = 0; i < counter; i++)
	{
		int x = remove(destination, ch);
	}

}






void replace(char * destination, char * old, char * newone)
{
	int lengthDestination = getStringLength(destination);
	int lengthOld = getStringLength(old);
	int lengthNew = getStringLength(newone);
	int index = findSubString(destination, old, 0);
	if (lengthOld == lengthNew)
	{

		for (int i = 0; i < lengthOld; i++)
		{
			destination[index + i] = newone[i];
		}
		cout << "done" << endl;
	}
	else
	{
		cout << "the sizes arent equal " << endl;
	}
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
	for (int i = 0; i < loopCount; i++)
	{
		char temp = destination[length - 1];
		destination[length - 1] = destination[start];
		destination[start] = temp;
		start++;
		length--;
	}
	cout << destination;


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



	}
}




