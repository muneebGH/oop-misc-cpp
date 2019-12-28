#include<iostream>
using namespace std;
struct player
{
	char name[50];
	int playerNo;
	int score;
};

void getData(player * a);
void displayTotal(player * a);
void displayMax(player * a);
void showData(player * a);