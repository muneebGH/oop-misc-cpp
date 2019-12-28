#include"Matrix.h"
#include"SMatrix.h"
int main()
{

	Matrix m1(2, 2);
	m1.at(0, 0) = 1;
	m1.at(0, 1) = 2;
	m1.at(1, 0) = 3;
	m1.at(1, 1) = 4;
	SMatrix sm1(2);

	sm1.at(0, 0) = 5;
	sm1.at(0, 1) = 6;
	sm1.at(1, 0) = 7;
	sm1.at(1, 1) = 8;

	
	system("pause");
	return 0;
}