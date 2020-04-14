#pragma once
#include "Trapezium.h"

class TrapeziumBase;
class TrapeziumAxes : public Trapezium {
public:
	//error class
	//constructor
	TrapeziumAxes(const Point& a, const Point& b,
		const Point& c, const Point& d);
	~TrapeziumAxes();
	//cast to TrapeziumBase
	operator TrapeziumBase() const;

	//trapezium square
	double area();
	//trapezium perimeter
	double perimeter();

	const Point pointA();
	const Point pointB();
	const Point pointC();
	const Point pointD();

	//return sides as new Segments, not connected with trapezium.
	//according to the task we should only find and not store sides, so I decide just return sides as new const segments.
	const Segment sideAB();
	const Segment sideBC();
	const Segment sideCD();
	const Segment sideAD();

	const Segment&  getMidLine();

	//arbitrary axis mirroring
	void flip(const Axis);
	//trapezium rotation
	void rotate(const double);

	ostream& show(ostream&);
private:
	//store trapezium ABCD as 4 points where a is top left point 
	Point _a, _b, _c, _d;
	Segment* _midLine;
};


