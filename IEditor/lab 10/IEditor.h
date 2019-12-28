#include<iostream>
#include"CString.h"
using namespace std;
class IEditor
{
private:
	CString filename;
	CString ** data;
	int currentLine;
	int noOfLines;
	int capacity;
public:
	IEditor(CString fn = "file1");
	void start();
	void forA(CString input);
	void forL(CString input);
	void forD(CString input);
};