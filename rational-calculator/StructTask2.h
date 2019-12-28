#pragma once
#pragma
using namespace std;
struct Rational
{

	int numerator;
	int denominator;

};

Rational addRational(Rational a, Rational b);
void inputRational(Rational & structInput);
void printRational(Rational  structOut);
Rational diffRational(Rational a, Rational b);
Rational divRational(Rational a, Rational b);
void reduce(Rational * a);

//helping functions not to check
int getLCM(int num1, int num2);
int getGCD(int a, int b);
