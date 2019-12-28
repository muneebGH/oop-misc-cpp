
#include"TaskB.h"
int main()
{
	Time a;
	a.setHours(12);
	a.setMinutes(0);
	a.setSeconds(0);
	cout << a.getHours() << " : " << a.getMinutes() << " : " << a.getSeconds() << endl;
	a.printTwelveHourFormat();
	a.incSec(1000);
	a.printTwelveHourFormat();
	system("pause");
}