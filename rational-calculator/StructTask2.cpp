
#include<iostream>
#include"structTask2.h"
using namespace std;




int main()
{
	//Rational Number1, Number2;
	//inputRational(Number1);
	//inputRational(Number2);
	
	
	//add rational 
	//Rational Add= addRational( Number1,Number2);
	//printRational(Add);

	//diffRational 
	//Rational Diff= diffRational(Number1,Number2);
	//printRational(Diff);

	//div rational
	//Rational Div=divRational(Number1,Number2);
	//printRational(Div);


	int gcd = getGCD(78,15);
	cout << gcd << endl;
	system(" pause");

}

void inputRational(Rational & StructIn)
{


	cout << "enter the numerator :  ";
	cin >> StructIn.numerator;

	cout << " enter the denominator : ";
	do
	{
		cin >> StructIn.denominator;
	} 
	while (StructIn.denominator == 0);


}

void printRational(Rational  structOut)
{
	cout << structOut.numerator;
	if (structOut.denominator > 1)
	{
		cout << "/" << structOut.denominator;
	}
	cout << endl;
	system("pause");
}

Rational addRational(Rational a, Rational b)
{

	int LCM = getLCM(a.denominator, b.denominator);

	Rational C;
	C.denominator = LCM;

	int num1, num2;
	num1 = LCM / a.denominator;

	a.numerator = a.numerator*num1;

	num2 = LCM / b.denominator;
	b.numerator = num2 * b.numerator;

	C.numerator = a.numerator + b.numerator;
	reduce(&C);



	return C;


}

Rational diffRational(Rational a, Rational b)
{
	int LCM = getLCM(a.denominator, b.denominator);

	Rational C;
	C.denominator = LCM;

	int num1, num2;
	num1 = LCM / a.denominator;

	a.numerator = a.numerator*num1;

	num2 = LCM / b.denominator;
	b.numerator = num2 * b.numerator;

	C.numerator = a.numerator - b.numerator;
	reduce(&C);
	return C;

}

Rational divRational(Rational a, Rational b)
{
	Rational C;

	int temp = 0;
	temp = b.numerator;
	b.numerator = b.denominator;
	b.denominator = temp;
	C.numerator = a.numerator*b.numerator;
	C.denominator = a.denominator*b.denominator;
	reduce(&C);
	return C;
}

int getLCM(int num1, int num2) {

	int tempNumber1 = 0;
	tempNumber1 = num1 * num2;
	int tempNumber2 = getGCD(num1, num2);
	int LCM = tempNumber1 / tempNumber2;
	return LCM;
}


void reduce(Rational * a)
{
	int gcd = getGCD(a->numerator, a->denominator);
	a->numerator = a->numerator / gcd;
	a->denominator = a->denominator / gcd;

}


int getGCD(int a, int b) 
{
	int gcd = 1;
	int remainder;
	
	if (a > b)
	{
		int temp = a;
		a = b;
		b = temp;
	}

	remainder = a % b;
	while (remainder != 0)
	{
		a=b;
		b = remainder;
		gcd = b;
		remainder = a % b;

	}
	
	return gcd;
}