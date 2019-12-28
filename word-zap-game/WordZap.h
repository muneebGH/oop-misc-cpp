#include"pch.h"
#include<iostream>
#include<cstdlib>
#include<time.h>
#include"MyOOPString.h"
using namespace std;
struct player {
	char name[50];
	char playerLetters[200];
};
void getNoOFPlayers(int & NOofPlayers);
void getDataOfPlayers(player * players, int NoOfPlayers);
int getRandomInRange(int lowerBound, int upperBound);
void showTurn(player * players, int playerNo);
int getLength(char * destination);
void removeElement(player * players, int playerNo, int index);
bool win(player * players, int playerNo);
void switchPlayer(int & playerNo, int NoOfPlayers);
bool getInput(player * players, int & playerNo, int NoOfPlayers);