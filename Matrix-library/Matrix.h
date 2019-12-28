#include<iostream>
using namespace std;
class Matrix
{
private:
	int ** data;
	int rows;
	int cols;
public:
	Matrix();
	Matrix(int r, int c);
	~Matrix();
	int & at(int r, int c);
	Matrix transpose();
	Matrix add(Matrix m2);
	void reSize(int newRow, int newCol);
	Matrix(const Matrix & r);
	Matrix operator = (const SMatrix & r);
	Matrix operator = (const Matrix & r);

};
