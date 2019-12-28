#include<iostream>
#include"CString.h"
using namespace std;



int  main()
{
	int testRuns = 0;
back:
	testRuns++;
	cout << "===================| TEST RUN NUMBER = " << testRuns << " |==================\n";
	int arr[4];
	for (int i= 0; i < 4; i++)
	{
		cin >> arr[i];
	}

	CString s;
	s.input();
	int noc = 0;
	for (int i = 0; i < s.getLength(); i++)
	{
		 char ch=s.at(i);
		 if (ch == '1')
		 {
			 noc += arr[0];
		 }
		 else if (ch == '2')
		 {
			 noc += arr[1];
		 }
		 else if (ch == '3')
		 {
			 noc += arr[2];
		 }
		 else
		 {
			 noc += arr[4];
		 }
	}
	
	cout << "\n" << noc;
	cout << endl;
	goto back;
	system("pause");
	return 0;
}

