#include"pch.h"
#include<iostream>
#include<stdlib.h>
using namespace std;


void draw(char(*p)[3]);
void switchPlayer(char &ch, int & PN);
void input(char(*p)[3], char ch, int PN);
int winning(char(*p)[3]);
int rowChecker(char(*p)[3]);
int coloumnChecker(char(*p)[3]);
int diagonalOneCheck(char(*p)[3]);
int tieCheck(char(*p)[3]);
int diagonalTwoCheck(char(*p)[3]);
int main() {
	int playerNo = 2;
	char box[3][3] = { '1','2','3','4','5','6','7','8','9' };
	char player = 'O';
	draw(box);

	int x;
	// start playing
	do {
		switchPlayer(player, playerNo);
		input(box, player, playerNo);
		system("cls");
		draw(box);

		x = winning(box);

	} while (x == 0);
	if (x == 1) {
		cout << " player 1 won : " << endl;

	}
	else if (x == 2) {
		cout << "playe 2 won :" << endl;
	}
	else if (x == 3) {
		cout << "tie have occured " << endl;
	}
}

void draw(char(*p)[3])

{
	cout << " ____________\n";
	cout << "|            |" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "|";
		for (int j = 0; j < 3; j++)
		{
			cout << " " << p[i][j] << "  ";
		}
		cout << "|";
		cout << "\n";
	}
	cout << "|____________|" << endl;

}

void switchPlayer(char &ch, int &PN) {
	if (ch == 'X') {
		ch = 'O';
		PN = 2;
	}
	else {
		ch = 'X';
		PN = 1;
	}
}

void input(char(*p)[3], char ch, int PN) {
	int ascii;
	int boxNum;
	do {

		cout << "player " << PN << ": Enter the no of box =" << endl;
		cin >> boxNum;

		if (boxNum == 1)
		{
			ascii = (int)p[0][0];
			if (ascii >= 48 && ascii <= 57) {

				p[0][0] = ch;
			}
			else {
				boxNum = 10;
			}
		}
		else if (boxNum == 2)
		{

			ascii = (int)p[0][1];
			if (ascii >= 48 && ascii <= 57) {

				p[0][1] = ch;
			}
			else {
				boxNum = 10;
			}
		}
		else if (boxNum == 3)
		{

			ascii = (int)p[0][2];
			if (ascii >= 48 && ascii <= 57) {

				p[0][2] = ch;
			}
			else {
				boxNum = 10;
			}
		}
		else if (boxNum == 4)
		{

			ascii = (int)p[1][0];
			if (ascii >= 48 && ascii <= 57) {

				p[1][0] = ch;
			}
			else {
				boxNum = 10;
			}
		}
		else if (boxNum == 5)
		{

			ascii = (int)p[1][1];
			if (ascii >= 48 && ascii <= 57) {

				p[1][1] = ch;
			}
			else {
				boxNum = 10;
			}
		}
		else if (boxNum == 6)
		{

			ascii = (int)p[1][2];
			if (ascii >= 48 && ascii <= 57) {

				p[1][2] = ch;
			}
			else {
				boxNum = 10;
			}
		}
		else if (boxNum == 7)
		{

			ascii = (int)p[2][0];
			if (ascii >= 48 && ascii <= 57) {

				p[2][0] = ch;
			}
			else {
				boxNum = 10;
			}
		}
		else if (boxNum == 8)
		{

			ascii = (int)p[2][1];
			if (ascii >= 48 && ascii <= 57) {

				p[2][1] = ch;
			}
			else {
				boxNum = 10;
			}
		}
		else if (boxNum == 9)
		{

			ascii = (int)p[2][2];
			if (ascii >= 48 && ascii <= 57) {

				p[2][2] = ch;
			}
			else {
				boxNum = 10;
			}
		}
		else {
			cout << "invalid " << endl;
		}
	} while (boxNum > 9);

}

int winning(char(*p)[3]) {
	int counter = 0;
	int j = 0;
	int x;
	//rows checker

	x = rowChecker(p);
	if (x != 0) {
		return x;
	}
	//coloumn check
	x = coloumnChecker(p);
	if (x != 0) {
		return x;
	}
	//diagonal one check
	x = diagonalOneCheck(p);
	if (x != 0) {
		return x;
	}

	//diagonal 2 check

	x = diagonalTwoCheck(p);
	if (x != 0) {
		return x;
	}
	//tie check

	return 0;
}



int rowChecker(char(*p)[3]) {
	int counter = 0;
	int j = 0;
	for (int i = 0; i < 3; i++) {
		if (p[i][j] == p[i][j + 1]) {
			counter = counter + 1;
		}if (p[i][j + 1] == p[i][j + 2]) {
			counter = counter + 1;
		}
		if (p[i][j] == 'X') {
			if (counter == 2) {
				return 1;
			}
		}
		else if (p[i][j] == 'O') {
			if (counter == 2) {
				return 2;
			}
		}
		else {
			counter = 0;
		}
		counter = 0;
	}
	return 0;
}


int coloumnChecker(char(*p)[3]) {
	int counter = 0;
	int j = 0;
	for (int i = 0; i < 3; i++) {
		if (p[j][i] == p[j + 1][i]) {
			counter = counter + 1;
		}
		if (p[j][i] == p[j + 2][i]) {
			counter = counter + 1;
		}
		if (counter == 2 && p[j][i] == 'X') {
			return 1;
		}
		else if (counter == 2 && p[j][i] == 'O') {
			return 2;
		}
		else {
			counter = 0;
		}counter = 0;
	}
	return 0;
}


int diagonalOneCheck(char(*p)[3]) {
	int counter = 0;
	int j = 0;
	if (p[0][0] == p[1][1]) {
		counter = counter + 1;
	}
	if (p[0][0] == p[2][2]) {
		counter = counter + 1;
	}
	if (counter == 2 && p[0][0] == 'X') {
		return 1;
	}
	else if (counter == 2 && p[0][0] == 'O') {
		return 2;
	}
	else {
		counter = 0;
	}
	return 0;
}

int diagonalTwoCheck(char(*p)[3]) {
	int counter = 0;
	int j = 0;

	if (p[0][2] == p[1][1]) {
		counter = counter + 1;
	}
	if (p[0][2] == p[2][0]) {
		counter = counter + 1;
	}
	if (counter == 2 && p[0][2] == 'X') {
		return 1;
	}
	else if (counter == 2 && p[0][2] == 'O') {
		return 2;
	}
	else {
		counter = 0;
	}
	return 0;
}

int tieCheck(char(*p)[3]) {
	int counter = 0;
	int j = 0;
	for (int i = 0; i < 3; i++) {
		for (int k = 0; k < 3; k++) {
			if (p[i][k] == 'X' || p[i][k] == 'O') {
				counter = counter + 1;
			}
		}
	}
	if (counter == 9) {
		return 3;
	}
	else {
		counter = 0;
	}
	return 0;
}