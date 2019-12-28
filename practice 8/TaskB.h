#include<iostream>
using namespace std;
class Time
{
private:
	int hours;
	int minutes;
	int seconds;
public:
	Time();
	Time(int h, int m, int s);
	void setHours(int h);
	void setMinutes(int m);
	void setSeconds(int s);
	void setTime(int h, int m, int s);
	int getHours();
	int getMinutes();
	int getSeconds();
	void printTwentyFourHourFormat();
	void printTwelveHourFormat();
	void incHour(int = 1);
	void incMin(int = 1);
	void incSec(int = 1);
};