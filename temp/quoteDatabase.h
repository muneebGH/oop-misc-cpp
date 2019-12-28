#include"quote.h"
struct QuoteDatabase
{
	Quote * data;
	int capacity;
	int numOfQuotations=0;
};
void createQuotationDatabase(QuoteDatabase & quoteDB, const int capacity);
void addQuotation(QuoteDatabase & quoteDB, const char * quote, const char * author);
bool isFull(QuoteDatabase q);
void reSize(QuoteDatabase & q);
void displayAuthorWise(QuoteDatabase & quoteDB, const char * author);
void removeQuotation(QuoteDatabase & quoteDB, int index);
void removeQuotation(QuoteDatabase & quoteDB, const char * word);
void displayQuotation(QuoteDatabase & quoteDB, const char * quote);
void freeQuotationDatabase(QuoteDatabase & quoteDB);
int DisplayQuotation(QuoteDatabase & quoteDB, const char * quote);