#include<iostream>
#include"MyOOPString.h"
using namespace std;
class Student
{private:
	char rollNo[11];
	int semester;
	char name[100];
	float CGPA;
public:
	Student();
	Student(const char * r, int s, const char * n, float g);
	void setRollNo(const char * p);
	void setSemester(int s);
	void setName(const char * p);
	void setCGPA(float gpa);
	const char * getRollNo();
	const char * getName();
	int getSemester();
	float getCGPA();
	bool isStudentDropOut();
	bool isStudentOnProbation();
};