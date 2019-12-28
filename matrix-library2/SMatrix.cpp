#include"SMatrix.h"
SMatrix::SMatrix()
{
	Matrix::Matrix();
}

SMatrix::SMatrix(int both):Matrix::Matrix(both,both)
{
}


void SMatrix::reSize(int both)
{
	Matrix::reSize(both, both);
}


SMatrix::SMatrix(const SMatrix & r):Matrix::Matrix(r)
{
}



//SMatrix SMatrix::operator=(const SMatrix & r)
//{
//	Matrix::operator=(r);
//	return *this;
//}



SMatrix SMatrix::operator=(const Matrix & r)
{
	Matrix::operator=(r);
	return *this;
}



SMatrix::SMatrix(const Matrix & r):Matrix(r)
{

}

SMatrix SMatrix::transpose()
{
	Matrix m = Matrix::transpose();
	SMatrix y(m);
	return y;
}