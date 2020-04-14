#include "TrapeziumBase.h"
#include "TrapeziumAxes.h"

//arbitrary axis mirroring
//using enum to choose axis
void TrapeziumAxes::flip(const Axis t)
{
	_a.flip(t);
	_b.flip(t);
	_c.flip(t);
	_d.flip(t);
}

//rotation of a segment by a given angle (in radians) relative to the origin.
void TrapeziumAxes::rotate(const double radians)
{
	_a.rotate(radians);
	_b.rotate(radians);
	_c.rotate(radians);
	_d.rotate(radians);

	delete _midLine;
	_midLine = 0;
	getMidLine();
}

//show trapezium
ostream& TrapeziumAxes::show(ostream& os)
{
	os << "TrapeziumAxes" << endl;
	os << _a;
	os << _b;
	os << _c;
	os << _d;
	return os;
}

//constructor
TrapeziumAxes::TrapeziumAxes(const Point& a, const Point& b, const Point& c, const Point& d):_a(a), _b(b), _c(c), _d(d), _midLine(0)
{
	//check if trapezium with these points is possible

	//check that all points are different
	if (_a == _b || _a == _c || _a == _d || _b == _c || _b == _d || _c == _d) throw BadTrapezium("some points are the same, not a trapezium");
	//check if points are in right order a->b->c->d where a is top left point
	if (!(_a.x() < _b.x() && b.y() > c.y() && c.x() > d.x() && d.y() < a.y())) throw BadTrapezium("wrong order of points");
	//check if figure is trapezium
	if (!isParallel(Segment(_a,_b),Segment(_c, _d)) && !isParallel(Segment(_a, _d), Segment(_b, _c))) throw BadTrapezium("no two parallel sides, not a trapezium");
}

//destructor
TrapeziumAxes::~TrapeziumAxes()
{
	delete _midLine;
	_midLine = 0;
}

//cast to TrapeziumBase
TrapeziumAxes::operator TrapeziumBase() const
{
	return TrapeziumBase(Segment(_a, _b), Segment(_c, _d));
}


//return trapezium square
//counting square with 4 sides
double TrapeziumAxes::area()
{
	double ground1 = sideAB().length();
	double ground2 = sideCD().length();
	double side1 = sideBC().length();
	double side2 = sideAD().length();


	

	double a = (ground1 + ground2) / 2;
	double c = 2 * (ground2 - ground1);
	double d = pow(ground2 - ground1, 2) + pow(side2, 2) - pow(side1, 2);
	double b = sqrt(pow(side2, 2) - pow(d / c, 2));
	return  a * b;
}

//return trapezium perimeter
double TrapeziumAxes::perimeter()
{
	return sideAB().length() + sideBC().length() + sideCD().length()+ sideAD().length();
}

const Point TrapeziumAxes::pointA()
{
	return _a;
}
const Point TrapeziumAxes::pointB()
{
	return _b;
}
const Point TrapeziumAxes::pointC()
{
	return _c;
}
const Point TrapeziumAxes::pointD()
{
	return _d;
}

const Segment TrapeziumAxes::sideAB()
{
	return Segment(_a, _b);
}

const Segment TrapeziumAxes::sideBC()
{
	return Segment(_b, _c);
}

const Segment TrapeziumAxes::sideCD()
{
	return Segment(_c, _d);
}

const Segment TrapeziumAxes::sideAD()
{
	return Segment(_a, _d);
}

//get middle line of trapezium
const Segment&  TrapeziumAxes::getMidLine() 
{
	if (_midLine == 0) {
		double x1 = sideAD().startX() > sideAD().endX() ? (sideAD().startX() - sideAD().endX()) / 2 : (sideAD().endX() - sideAD().startX()) / 2;
		double x2 = sideBC().startX() > sideBC().endX() ? (sideBC().startX() - sideBC().endX()) / 2 : (sideBC().endX() - sideBC().startX()) / 2;
		double y1 = sideAD().startY() > sideAD().endY() ? (sideAD().startY() - sideAD().endY()) / 2 : (sideAD().endY() - sideAD().startY()) / 2;
		double y2 = sideBC().startY() > sideBC().endY() ? (sideBC().startY() - sideBC().endY()) / 2 : (sideBC().endY() - sideBC().startY()) / 2;
		_midLine = new Segment(x1, y1, x2, y2);
	}
	return *_midLine;
}


