#include<iostream>
using namespace std;

class CString
{

private:

	char * data;
	int size;

public:

	CString();
	CString(const char c);
	CString(const char * p);
	CString(const CString & ref);
	~CString();
	void input();
	char & at(int index);
	const char & at(int index)const;
	bool isEmpty()const;
	int getLength()const;
	void display()const;
	int find(CString subStr, int start = 0)const;
	void insert(int index, CString subStr);
	void remove(int index, int count = 1);
	int replace(CString old, CString newSubStr);
	void trimLeft();
	void trimRight();
	void trim();
	void makeUpper();
	void makeLower();
	void reverse();
	void reSize(int newSize);
	int comapre(CString S2) const;
	CString left(int count);
	CString right(int count);
	int toInteger()const;
	float toFloat()const;
	CString concact(CString s2) const;
	void concatEqual(CString s2);
	CString tokenize(CString delim);
	int getLength(const char * p)const;
	int operator == (CString S2) const;
	void operator += (CString s2);
	CString operator + (CString s2)const;
	char & operator [](int index);
	CString & operator = (const CString & ref);

};
