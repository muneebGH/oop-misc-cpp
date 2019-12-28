#include"quote.h"
#include"MyOOPString.h"


void initializaQuote(Quote & q, const char * qt, const char * auth)
{
	q.author = new char[getStringLength(auth) + 1];
	q.message = new char[getStringLength(qt) + 1];
	copyString(q.author, auth);
	copyString(q.message, qt);
}

Quote createClone(Quote & q1)
{
	Quote q2;
	memcpy(&q2, &q1, sizeof(q1));
	return q2;
}

void freeQuote(Quote & q)
{
	delete q.message;
	delete q.author;

}
