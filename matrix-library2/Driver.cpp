#include"SMatrix.h"
int main()
{

	Matrix m1(2, 2);
	m1.at(0, 0) = 1;
	m1.at(0, 1) = 2;
	m1.at(1, 0) = 3;
	m1.at(1, 1) = 4;
	Matrix m2(2, 2);
	m2.at(0, 0) = 5;
	m2.at(0, 1) = 6;
	m2.at(1, 0) = 7;
	m2.at(1, 1) = 8;
	SMatrix sm1(2);

	sm1.at(0, 0) = 5;
	sm1.at(0, 1) = 6;
	sm1.at(1, 0) = 7;
	sm1.at(1, 1) = 8;
	sm1.display();

	SMatrix s2(2);

	s2= sm1.transpose();
	s2.display();
	system("pause");
	return 0;
}