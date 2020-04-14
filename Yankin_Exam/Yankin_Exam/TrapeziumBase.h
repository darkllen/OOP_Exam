#pragma once

#include "Trapezium.h"
class TrapeziumAxes;
class TrapeziumBase : public Trapezium {
public:
	//constructor
	TrapeziumBase(const Segment& ab, const Segment& cd);
	~TrapeziumBase();

	//cast to TrapeziumAxes
	operator TrapeziumAxes() const;

	//trapezium square
	double area();
	//trapezium perimeter
	double perimeter();

	//return tops and sides
	const Point pointA();
	const Point pointB();
	const Point pointC();
	const Point pointD();

	const Segment sideAB();
	const Segment sideBC();
	const Segment sideCD();
	const Segment sideAD();

	//get middle line of trapezium
	const Segment&  getMidLine();

	//arbitrary axis mirroring
	void flip(const Axis);
	//trapezium rotation
	void rotate(const double);

	//output method
	ostream& show(ostream&);
private:
	Segment _ab, _cd;
	Segment* _midLine;
};


