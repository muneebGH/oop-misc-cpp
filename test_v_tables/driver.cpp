#include"classes.h"
typedef void(*Fun)(void);
int main()
{
	D obj;
	cout << "object adress | "<<&obj << endl;
	D * p = &obj;
	cout <<"vptsr adress | "<< p << endl;
	int * pint = (int *)p;

	cout << "vptrs value | " << (int *)pint[0] << endl;
	cout << "first function pointers adress | " << (int *)pint[0] << endl;
	cout << "first function pointers value or functions adress | " << *(int *)pint[0] << endl;
	Fun pfun = (Fun)*(int *)pint[0];
	cout << "1st function is "; pfun();
	cout << "second functions pointer adress is | " << (int *)pint[0] + 1 << endl;
	cout << "second functoion"; pfun = (Fun)*(((int *)pint[0]) + 1); pfun();
	cout << "vptrs 1st funtion"; pfun = (Fun)*(((int *)pint[2]) + 0); pfun();
	system("pause");
	return 0;
}