#include"TaskB.h"
void Time::setHours(int h)
{
	if (h >= 0 && h <= 23)
	{
		hours = h;
	}
}


void Time::setMinutes(int m)
{
	if (m >= 0 && m <= 59)
	{
		minutes = m;
	}
}

void Time::setSeconds(int s)
{
	if (s >= 0 && s <= 59)
	{
		seconds = s;
	}
}

void Time::setTime(int h, int m, int s)
{
	setHours(h);
	setMinutes(m);
	setSeconds(s);
}

int Time::getHours()
{
	return hours;
}

int Time::getMinutes()
{
	return minutes;
}

int Time::getSeconds()
{
	return seconds;
}

void Time::printTwentyFourHourFormat()
{
	cout << hours << ":" << minutes << ":" << seconds << endl;
}

void Time::printTwelveHourFormat()
{
	if (hours <= 12)
	{
		if (hours == 0)
		{
			cout << "12";
		}
		else
		{
			cout << hours;
		}
		 cout<< ":" << minutes << ":" << seconds << " ";
		if (hours == 12)
		{
			cout << "Pm" << endl;
		}
		else
		{
			cout << "Am" << endl;
		}
			
	}
	else
	{
		int remainder = 0;
		remainder = hours % 12;
		cout << remainder << ":" << minutes << ":" << seconds << " Pm" << endl;
	}
}

void Time::incSec(int s)
{
	int temp;
	temp = seconds + s;
	if (temp <= 59)
	{
		seconds = temp;
	}
	else
	{
		int remainder = 0;
		remainder = temp % 60;
		seconds = remainder;
		int incMinCounter = temp / 60;
		incMin(incMinCounter);
		
	}
}

void Time::incMin(int m)
{
	int temp = minutes + m;
	if (temp <= 59)
	{
		minutes = temp;
	}
	else
	{
		int remainder = 0;
		remainder = temp % 60;
		minutes = remainder;
		int incHourCount = temp / 60;
		incHour(incHourCount);
	}
}


void Time::incHour(int h)
{
	int temp;
	temp = hours + h;
	if (temp <= 23)
	{
		hours = temp;
	}
	else
	{
		int remainder = 0;
		remainder = temp % 24;
		hours = remainder;
	}
}


Time::Time()
{
	hours = 0;
	minutes = 0;
	seconds = 0;
}


Time::Time(int h, int m, int s)
{
	hours = h;
	minutes = m;
	seconds = s;
}


