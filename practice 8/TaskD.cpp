#include"TaskD.h"
void Student::setRollNo(const char * p)
{
	char temp[4];
	for (int i = 0; i < 3; i = i + 1)
	{
		temp[i] = p[i + 7];
	}
	temp[4] = '\0';
	int checkRange = convertToInteger(temp);
	if(checkRange>=1 && checkRange<=999)
	{
		copyString(rollNo, p);
	}

}
void Student::setSemester(int s)
{
	if (s > 0)
	{
		semester = s;
	}
}

void Student::setName(const char * p)
{
	copyString(name, p);
}

void Student::setCGPA(float gpa)
{
	CGPA = gpa;
}

const char * Student::getName()
{
	return name;
}

const char * Student::getRollNo()
{
	return rollNo;
}

int Student::getSemester()
{
	return semester;

}

float Student::getCGPA()
{
	return CGPA;
}

bool Student::isStudentDropOut()
{
	if (semester == 1 && CGPA < 1.5)
	{
		return true;
	}
	else if (semester > 1 && CGPA < 1.7)
	{
		return true;
	}
	else
	{
		return false;
	}


}


bool Student::isStudentOnProbation()
{
	if (semester == 1)
	{
		if(CGPA >= 1.5 && CGPA < 2)
		{
			return true;
		}
	}
	else
	{
		if (CGPA >= 1.7 && CGPA < 2.0)
		{
			return true;
		}
	}
	return false;
}

Student::Student()
{
	char r[] = "bcsf17m001";
	char n[] = "no user";
	copyString(rollNo, r);
	copyString(name, n);
	semester = 1;
	CGPA = 2.0;
}

Student::Student(const char * r, int s, const char * n, float g)
{
	copyString(name, n);
	copyString(rollNo, r);
	semester = s;
	CGPA = g;
}