#include"Matrix.h"

Matrix::Matrix()
{
	data = nullptr;
	rows = 0;
	cols = 0;
}


Matrix::Matrix(int r, int c)
{
	data = new int *[r];
	for (int i = 0; i < r; i = i + 1)
	{
		data[i] = new int[c];
	}

	rows = r;
	cols = c;
}


int & Matrix::at(int r, int c)
{
	if (data)
	{
		if (r <= rows && c <= cols)
			return data[r][c];
	}
}


void Matrix::display()
{
	cout << "\n\n\n";
	for (int i = 0; i < rows; i = i + 1)
	{


		for (int j = 0; j < cols; j = j + 1)
		{
			cout << data[i][j] << ",";
		}
		cout << endl;
	}
}


Matrix Matrix::add(Matrix m2)
{
	Matrix added(rows, cols);
	for (int i = 0; i < rows; i = i + 1)
	{
		for (int j = 0; j < cols; j = j + 1)
		{
			added.at(i, j) = data[i][j] + m2.at(i, j);
		}

	}


	return added;
}



Matrix Matrix::transpose()
{

	Matrix t(rows, cols);
	for (int i = 0; i < rows; i = i + 1)
	{
		for (int j = 0; j < cols; j = j + 1)
		{
			t.data[i][j] = data[j][i];
		}
	}

	return t;
}

Matrix::Matrix(const Matrix & r)
{
	rows = r.rows;
	cols = r.cols;

	data = new int *[rows];
	for (int i = 0; i < rows; i = i + 1)
	{
		data[i] = new int[cols];
	}


	for (int i = 0; i < rows; i = i + 1)
	{
		for (int j = 0; j < cols; j = j + 1)
		{
			data[i][j] = r.data[i][j];
		}
	}
}

Matrix::~Matrix()
{
	for (int i = 0; i < rows; i = i + 1)
	{
		delete data[i];
	}

	delete data;
}

void Matrix::reSize(int newRow, int newCol)
{
	Matrix temp(*this);
	this->~Matrix();
	rows = newRow;
	cols = newCol;
	data = new int *[rows];
	for (int i = 0; i < cols; i = i + 1)
	{
		data[i] = new int[cols];
	}

	for (int i = 0; i < rows; i = i + 1)
	{
		for (int j = 0; j < cols; j = j + 1)
		{
			data[i][j] = temp.data[i][j];
		}
	}

}








Matrix Matrix::operator=(const Matrix & r)
{
	if (data == r.data)
		return *this;
	if (data)
		this->~Matrix();

	rows = r.rows;
	cols = r.cols;

	data = new int *[rows];
	for (int i = 0; i < rows; i = i + 1)
	{
		data[i] = new int[cols];
	}


	for (int i = 0; i < rows; i = i + 1)
	{
		for (int j = 0; j < cols; j = j + 1)
		{
			data[i][j] = r.data[i][j];
		}
	}
	return *this;

}



                                                                                                                                                                                                