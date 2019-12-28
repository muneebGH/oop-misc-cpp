#include<iostream>
#include<stdlib.h>
#include"MyOOPString.h"
using namespace std;


void draw(char(*p)[3]);
void switchPlayer(char &ch, int & PN);
void input(char(*p)[3], char ch, int PN);
int checkWinner(char(*p)[3]);
int rowChecker(char(*p)[3]);
int coloumnChecker(char(*p)[3]);
int diagonalOneCheck(char(*p)[3]);
int tieCheck(char(*p)[3]);
int diagonalTwoCheck(char(*p)[3]); 
void displayWinner(int x);
void play(char(*box)[3]);
bool validatorOne(char * boxNum);
bool validatorTwo(int i, int j, char(*p)[3]);
void  initializeBox(char(*p)[3]);
