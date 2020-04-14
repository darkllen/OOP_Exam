#pragma once
#include <iostream>
#include "Axis.h"
using namespace std;

class Point {
private:
	double _x;
	double _y;
public:
	//constructor with default values
	Point(const double x = 0, const double y = 0);
	//copy constructor
	Point(const Point&);
	//destructor
	~Point();
	//assign operator
	Point& operator=(const Point&);

	double& x();
	double& y();
	const double& x()const;
	const double& y()const;

	//arbitrary axis mirroring
	void flip(const Axis);
	//point rotation
	void rotate(const double);
};
//output operaor
ostream& operator<<(ostream&, const Point&);
//equal operator
bool operator==(const Point& u, const Point& v);
