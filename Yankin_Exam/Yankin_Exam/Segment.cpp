#include "Segment.h"


//constructor by coordinates
Segment::Segment(const double x1, const double y1, const double x2, const double y2) :_a(x1, y1), _b(x2, y2) {
}

//constructor by points
Segment::Segment(const Point& start, const Point& end) :_a(start), _b(end)
{
}


//copy constructor
Segment::Segment(const Segment& that) :_a(that._a), _b(that._b)
{
}

//destructor
Segment::~Segment()
{
}


//assignment operator
Segment& Segment::operator=(const Segment& that)
{
	//check if segments aren`t the same
	if (this == &that)
		return *this;
	_a = that._a;
	_b = that._b;
	return *this;
}

const Point& Segment::start() const
{
	return _a;
}
const Point& Segment::end() const {
	return _b;
}

Point& Segment::start()
{
	return _a;
}

Point& Segment::end()
{
	return _b;
}

const double& Segment::startX() const
{
	return _a.x();
}

const double& Segment::startY() const
{
	return _a.y();
}

const double& Segment::endX() const
{
	return _b.x();
}

const double& Segment::endY() const
{
	return _b.y();
}

double& Segment::startX()
{
	return _a.x();
}

double& Segment::startY()
{
	return _a.y();
}

double& Segment::endX()
{
	return _b.x();
}

double& Segment::endY()
{
	return _b.y();
}

//counting length with: 
// length = sqrt( (x2-x1)^2 + (y2-y1)^2 )
double Segment::length() const
{
	return sqrt(pow(_b.x() - _a.x(), 2) + pow(_b.y() - _a.y(), 2));
}

//arbitrary axis mirroring
//using enum to choose axis
void Segment::flip(const Axis t)
{
		_a.flip(t);
		_b.flip(t);
}

//rotation of a segment by a given angle (in radians) relative to the origin.
void Segment::rotate(const double radians)
{
	_a.rotate(radians);
	_b.rotate(radians);
}



//method to check if segment a and b are parallel
//return true if yes and false if no 
//to check we get 2 points (middle of the segments), imagine line through these points and compare lying corners.
//because according to the second sign of parallel lines
//If at the intersection of two lines of the third secant:the cross angles are equal, so lines are parallel
bool isParallel(const Segment& a, const Segment& b)
{
	double x1 = a.startX() > a.endX() ? a.endX() + (a.startX() - a.endX())/2 : a.startX() + (a.endX() - a.startX())/2;
	double y1 = a.startY() > a.endY() ? a.endY() + (a.startY() - a.endY())/2 : a.startY() + (a.endY() - a.startY())/2;
	Point s(x1, y1);

	double x2 = b.startX() > b.endX() ? b.endX() + (b.startX() - b.endX()) / 2 : b.startX() + (b.endX() - b.startX()) / 2;
	double y2 = b.startY() > b.endY() ? b.endY() + (b.startY() - b.endY()) / 2 : b.startY() + (b.endY() - b.startY()) / 2;
	Point t(x2, y2);

	if ((((a.startX() >= a.endX() && a.startY() >= a.endY()) || (a.startX() <= a.endX() && a.startY() <= a.endY())) &&
		((b.startX() >= b.endX() && b.startY() >= b.endY()) || (b.startX() <= b.endX() && b.startY() <= b.endY()))) ||
		(((a.startX() >= a.endX() && a.startY() <= a.endY()) || (a.startX() <= a.endX() && a.startY() >= a.endY())) &&
		((b.startX() >= b.endX() && b.startY() <= b.endY()) || (b.startX() <= b.endX() && b.startY() >= b.endY())))) {

		x1 = a.startX() > a.endX() ? a.startX() : a.endX();
		x2 = b.startX() > b.endX() ? b.endX() : b.startX();
		y1 = a.startX() > a.endX() ? a.startY() : a.endY();
		y2 = b.startX() > b.endX() ? b.endY() : b.startY();
	}
	else {
		x1 = a.startX() > a.endX() ? a.startX() : a.endX();
		x2 = b.startX() > b.endX() ? b.startX() : b.endX();
		y1 = a.startX() > a.endX() ? a.startY() : a.endY();
		y2 = b.startX() > b.endX() ? b.startY() : b.endY();
	}


	double vx1 = x1 - s.x();
	double vy1 = y1 - s.y();
	double vx2 = t.x() - s.x();
	double vy2 = t.y() - s.y();

	double ang1 = (vx1 * vx2 + vy1 * vy2) / (sqrt(vx1 * vx1 + vy1 * vy1) * sqrt(vx2 * vx2 + vy2 * vy2));

	vx1 = x2-t.x();
	vy1 = y2-t.y();
	vx2 = s.x() - t.x();
	vy2 = s.y() - t.y();
	double ang2 = (vx1 * vx2 + vy1 * vy2) / (sqrt(vx1 * vx1 + vy1 * vy1) * sqrt(vx2 * vx2 + vy2 * vy2));

	//check if angles are equal and if segment a and b don`t lie on the same line
	return ang1==ang2 && (t.x()-x1)/(s.x()-x1)!=(t.y()-y1)/(s.y()-y1);
}

//output operator
ostream& operator<<(ostream& os, const Segment& that)
{
	os << "start point: " << that.start() << "end point: " << that.end() << endl;
	return os;
}

//equal operator
bool operator==(const Segment& first, const Segment& sec)
{
	return (first.start() == sec.start() && first.end() == sec.end());
}
