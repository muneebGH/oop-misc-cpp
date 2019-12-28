#include<iostream>
#include"MyOOPString.h"
using namespace std;
struct Quote
{
	char * message;
	char * author;
};
void initializaQuote(Quote & q, const char * qt, const char * auth);
Quote createClone(Quote & q1);
void freeQuote(Quote & q);
