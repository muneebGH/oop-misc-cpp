#include"quoteDatabase.h"


void createQuotationDatabase(QuoteDatabase & quoteDB, const int capacity)
{
	quoteDB.capacity = capacity;
	quoteDB.numOfQuotations = 0;
	quoteDB.data = new Quote[capacity];
}


void addQuotation(QuoteDatabase & quoteDB, const char * quote, const char * author)
{
	if (isFull(quoteDB))
	{
		reSize(quoteDB);
	}

	initializaQuote(quoteDB.data[quoteDB.numOfQuotations], quote, author);
	quoteDB.numOfQuotations = quoteDB.numOfQuotations + 1;
}



void displayAuthorWise(QuoteDatabase & quoteDB, const char * author)
{
	int index = -1;
	int i = 0;
	int counter = 0;
	for (int i = 0; i < quoteDB.numOfQuotations; i = i + 1)
	{
		index = findSubString(quoteDB.data[i].author, author, 0);
		if (index != -1)
		{
			cout <<counter+1<<" : "<< quoteDB.data[i].message << endl;
			counter = counter + 1;
		}
	}

	if (counter == 0)
	{
		cout << " no quotations for that author were found" << endl;
	}

}


void displayQuotation(QuoteDatabase & quoteDB, const char * quote)
{


	int index = -1;
	int i = 0;
	int counter = 0;
	for (int i = 0; i < quoteDB.numOfQuotations; i = i + 1)
	{
		index = findSubString(quoteDB.data[i].message, quote, 0);
		if (index != -1)
		{
			cout << counter+1<<" : "<<quoteDB.data[i].message << endl;
			counter = counter + 1;
		}
	}

	if (counter == 0)
	{
		cout << " no quotations for that quote word found" << endl;
	}

}


void removeQuotation(QuoteDatabase & quoteDB, const char * word)
{

	int x=DisplayQuotation(quoteDB, word);

	if (x != 0)
	{
		int j;

		cout << " enter the quotation number u want to remove" << endl;
		cin >> j;
		removeQuotation(quoteDB, (j - 1));
	}
}

void freeQuotationDatabase(QuoteDatabase & quoteDB)
{
	delete[] quoteDB.data;
	quoteDB.capacity = 0;
	quoteDB.numOfQuotations = 0;
}
bool isFull(QuoteDatabase q)
{
	if (q.capacity == q.numOfQuotations)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void reSize(QuoteDatabase & q)
{
	QuoteDatabase clone;
	memcpy(&clone, &q, sizeof(q));
	delete q.data;
	q.capacity = q.capacity + 1;
	q.data = new Quote[q.capacity];
	memcpy(&q, &clone, sizeof(clone));


}

void removeQuotation(QuoteDatabase & quoteDB, int index)
{
	int loopCounter;

	loopCounter = quoteDB.numOfQuotations - (index + 1);

	for (int i = index; i < loopCounter; i = i + 1)
	{
		initializaQuote(quoteDB.data[i], quoteDB.data[i + 1].message, quoteDB.data[i + 1].author);
	}
	quoteDB.data[(quoteDB.numOfQuotations) - 1].message = '\0';
	quoteDB.data[(quoteDB.numOfQuotations) - 1].author ='\0';
	quoteDB.numOfQuotations = quoteDB.numOfQuotations - 1;
}


int DisplayQuotation(QuoteDatabase & quoteDB, const char * quote)
{


	int index = -1;
	int i = 0;
	int counter = 0;
	for (int i = 0; i < quoteDB.numOfQuotations; i = i + 1)
	{
		index = findSubString(quoteDB.data[i].message, quote, 0);
		if (index != -1)
		{
			cout << counter + 1 << " : " << quoteDB.data[i].message << endl;
			counter = counter + 1;
		}
	}

	if (counter == 0)
	{
		cout << " no quotations for that quote word found" << endl;
	}


	return counter;
}
