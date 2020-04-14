#include "TrapeziumAxes.h"
#include "TrapeziumBase.h"

//constructor
TrapeziumBase::TrapeziumBase(const Segment& ab, const Segment& cd): _ab(ab), _cd(cd), _midLine(0)
{
	//check if all points are different
	if (_ab.start() == _ab.end() || _ab.start() == _cd.start() || _ab.start() == _cd.end() || _ab.end() == _cd.start() || _ab.end() == _cd.end() || _cd.start() == _cd.end()) throw BadTrapezium("some points are the same, not a trapezium");
	//check if bases are realyy parallel
	if (!isParallel(_ab, _cd)) throw BadTrapezium("trapezium must be defined by the bases");
}

//destructor
TrapeziumBase::~TrapeziumBase()
{
	delete _midLine;
	_midLine = 0;
}

//cast to TrapeziumAxes
TrapeziumBase::operator TrapeziumAxes() const
{
	return TrapeziumAxes(_ab.start(), _ab.end(), _cd.start(), _cd.end());
}

//return trapezium square
//counting square with 4 sides
double TrapeziumBase::area()
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

//return perimeter
double TrapeziumBase::perimeter()
{
	return _ab.length() + _cd.length() + sideBC().length() + sideAD().length();
}

const Point TrapeziumBase::pointA()
{
	return _ab.start();
}

const Point TrapeziumBase::pointB()
{
	return _ab.end();
}

const Point TrapeziumBase::pointC()
{
	return _cd.start();
}

const Point TrapeziumBase::pointD()
{
	return _cd.end();
}

const Segment TrapeziumBase::sideAB()
{
	return _ab;
}

const Segment TrapeziumBase::sideBC()
{
	return Segment(_ab.end(), _cd.start());
}

const Segment TrapeziumBase::sideCD()
{
	return _cd;
}

const Segment TrapeziumBase::sideAD()
{
	return Segment(_ab.start(), _cd.end());
}


//get middle line of trapezium
const Segment&  TrapeziumBase::getMidLine()
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

//arbitrary axis mirroring
//using enum to choose axis
void TrapeziumBase::flip(const Axis t)
{
	_ab.flip(t);
	_cd.flip(t);
}

//rotation of a segment by a given angle (in radians) relative to the origin.
void TrapeziumBase::rotate(const double radians)
{
	_ab.rotate(radians);
	_cd.rotate(radians);


	delete _midLine;
	_midLine = 0;
	getMidLine();
}

ostream& TrapeziumBase::show(ostream& os)
{
	os << "TrapeziumBase" << endl;
	os << _ab;
	os << _cd;
	return os;
}


