
#include "pch.h"
#include <iostream>
using namespace std;

int getLength(char * destination);
void inserString(char * destination, char * source, int index);

int main()
{
	char destination[] = "muneeb rehman";
	char source[] = "ur ";
	//int x = getLength(destination);
	//cout << x << endl;
	inserString(destination, source, 7);
	
	cout << destination;
}



int getLength(char * destination) {
	int length = 0;
	int i = 0;
	char ch = destination[i];
	while (ch != '\0') {
		i++;
		length++;
		ch = destination[i];
	}
	return length;
}



void inserString(char * destination, char * source, int index) {
	int lengthDestination = getLength(destination);
	int lengthSource = getLength(source);
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