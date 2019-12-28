#include<iostream>
#include"soccerPlayer.h"
#include<iomanip>
using namespace std;

void getData(player * a)
{
	for (int i = 0; i < 12; i = i + 1)
	{
		a[i].playerNo = i + 1;
	}

	for (int i = 0; i < 12; i = i + 1)
	{
		
		cout << "enter the name of player " << i + 1 << endl;
		cin.getline(a[i].name, 50);
		cout << "enter the score for player " << i + 1 << endl;
		cin >> a[i].score;
		cin.ignore();
	}
}

void displayTotal(player * a)
{
	int total = 0;
	for (int i = 0; i < 12; i = i + 1)
	{
		total = total + a[i].score;
	}
	cout << "the total score is " << total << endl;

}

void displayMax(player * a)
{

	int max = a[0].score;

	for (int i = 1; i < 12; i = i + 1)
	{
		if (a[i].score > max)
		{
			max = a[i].score;
		}
	}

	cout << "the max score is : " << max << endl;
}


void showData(player * a)
{
	
	cout << "Player No:         Name:               Score:" << endl;
	for (int i = 0; i < 12; i = i + 1)
	{
		cout << setw(5) <<a[i].playerNo<< setw(20) << a[i].name << "               " << a[i].score << endl;
	}
	displayTotal(a);
	displayMax(a);
}



















