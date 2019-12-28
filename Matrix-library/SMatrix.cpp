#include"SMatrix.h"
SMatrix::SMatrix()
{
	Matrix::Matrix();
}

SMatrix::SMatrix(int both)
{
	Matrix::Matrix(both, both);
}


void SMatrix::reSize(int both)
{
	Matrix::reSize(both, both);
}


SMatrix::SMatrix(const SMatrix & r)
{
	Matrix::Matrix(r);
}



SMatrix SMatrix::operator=(const SMatrix & r)
{
	this->operator=(r);
	return *this;
}



SMatrix SMatrix::operator=(const Matrix & r)
{
	this->operator=(r);
	return *this;
}







