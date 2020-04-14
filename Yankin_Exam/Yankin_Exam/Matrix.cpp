#include "Matrix.h"

//constructor with default values
Matrix::Matrix(double a00, double a01, double a10, double a11) :a{a00, a01, a10, a11}
{
}

//copy constructor
Matrix::Matrix(const Matrix& that): a{that.a[0], that.a[1], that.a[2], that.a[3]}
{
}

//destructor
Matrix::~Matrix()
{
}

//assign operator
Matrix& Matrix::operator=(const Matrix& that)
{
	//check if that isn`t the same
	if (*this == that) return *this;
	a[0] = that.a[0];
	a[1] = that.a[1];
	a[2] = that.a[2];
	a[3] = that.a[3];
	return *this;
}

//operators
Matrix Matrix::operator+(const Matrix& that) const
{
	return Matrix(a[0]+that.a[0], a[1] + that.a[1], 
		a[2] + that.a[2], a[3] + that.a[3]);
}
Matrix Matrix::operator-(const Matrix& that) const
{
	return Matrix(a[0] - that.a[0], a[1] - that.a[1],
		a[2] - that.a[2], a[3] - that.a[3]);
}
Matrix Matrix::operator*(const Matrix& that) const
{
	return Matrix(a[0] * that.a[0] + a[1]*that.a[2], a[0] * that.a[1] + a[1] * that.a[3], 
		a[2] * that.a[0] + a[3] * that.a[2], a[2] * that.a[1] + a[3] * that.a[3]);
}

bool Matrix::operator==(const Matrix& that) const
{
	return a[0]==that.a[0] && a[1] == that.a[1] && a[2] == that.a[2] && a[3] == that.a[3];
}

ostream& operator<<(ostream& os, const Matrix& that)
{
	os << "[" << that.a[0] << "," << that.a[1]<<"]" << endl;
	os << "[" << that.a[2] << "," << that.a[3] << "]" << endl;
	return os;
}
