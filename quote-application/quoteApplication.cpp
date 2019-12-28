#include"quoteApplication.h"
void quoteDBapplication()
{
	QuoteDatabase quoteDB;
	createQuotationDatabase(quoteDB, 10);
	int choice;
	do
	{
		cout << "------------Quotation Database------------\n";
		cout << "******************************************\n";
		cout << "Enter 1 to Add Quote \n";
		cout << "Enter 2 to Remove Quote \n";
		cout << "Enter 3 to Search Quotes of Author \n";
		cout << "Enter 4 to Search Quote That Contains Word \n";
		cout << "Enter 0 to Quit ";
		cin >> choice;
		cin.ignore();
		switch (choice)
		{
		case 1:
			char q[200], a[50];
			cout << "\nEnter Quotation: ";
			cin.getline(q, 200);
			cout << "\nEnter Author Name: ";
			cin.getline(a, 50);
			addQuotation(quoteDB, q, a);
			break;
		case 2:
			char word[30];
			cout << " enter the word " << endl;
			cin.getline(word, 30);
			removeQuotation(quoteDB, word);
			break;
		case 3:
			char author[30];
			cout << " enter the name of author " << endl;
			cin.getline(author, 30);
			displayAuthorWise(quoteDB, author);
			break;
		case 4:
			char quotation[50];
			cout << "enter the word " << endl;
			cin.getline(quotation, 50);
			displayQuotation(quoteDB, quotation);
			break;
		case 0:
			freeQuotationDatabase(quoteDB);
			break;
		default:
			cout << "OOPs! You Entered Wrong Choice\n";
		}
	} while (choice != 0);

}