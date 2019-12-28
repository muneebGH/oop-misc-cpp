#include"Matrix.h"
class SMatrix :public Matrix
{
private:
	SMatrix(const Matrix & r);
public:
	SMatrix();
	SMatrix(int both);
	void reSize(int both);
	SMatrix(const SMatrix & r);
	//SMatrix operator =(const SMatrix & ref);
	SMatrix operator =(const Matrix & ref);
	SMatrix transpose();


};
