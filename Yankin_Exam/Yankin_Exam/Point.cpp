#include "Point.h"


//constructor with default values 
Point::Point(const double x, const double y) :_x(x), _y(y) {
};
//copy constructor
Point::Point(const Point& that) :_x(that._x), _y(that._y) {
};
//destructor
Point::~Point() {
};

//asignment operator
Point& Point::operator=(const Point& that) {
	//check if points aren`t the same
	if (this == &that)
		return *this;
	_x = that._x;
	_y = that._y;
	return *this;
};

//selector-modificator
double& Point::x() { return _x; };

//selector-modificator
double& Point::y() { return _y; };

//selector
const double& Point::x()const { return _x; };

//selector
const double& Point::y()const { return _y; }

//arbitrary axis mirroring
//using enum to choose axis
void Point::flip(const Axis t)
{
	if (t == X) _y = -_y;
	if (t == Y) _x = -_x;
}
//rotation of a point by a given angle (in radians) relative to the origin.
void Point::rotate(const double radians)
{
	double xPrev = _x;
	_x = _x * cos(radians) - _y * sin(radians);
	_y = xPrev * sin(radians) + _y * cos(radians);

}


//output point coordinates in release mod.
ostream& operator<<(ostream& os, const Point& that) {
	os << "x: " << that.x() << ", y: " << that.y() << endl;
	return os;
};

//equal operator. Compare points by coordinates
bool operator==(const Point& u, const Point& v) {
	return u.x() == v.x() && u.y() == v.y();
};
