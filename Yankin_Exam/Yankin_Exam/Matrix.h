#pragma once
#include <iostream>
using namespace std;

class Matrix {
public:
	//store matrix values in array
	double a[4];
	//constructor with default values
	Matrix(double a00 = 0, double a01 = 0, double a10 = 0, double a11 = 0);
	//copy constructor
	Matrix(const Matrix&);
	//destructor
	~Matrix();
	//assign operator
	Matrix& operator=(const Matrix&);

	//operators
	Matrix operator+(const Matrix&) const;
	Matrix operator-(const Matrix&) const;
	Matrix operator*(const Matrix&) const;
	bool operator==(const Matrix&) const;

};
//output operator
ostream& operator<<(ostream&, const Matrix&);