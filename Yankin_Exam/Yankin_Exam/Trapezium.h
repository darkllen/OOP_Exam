#pragma once
#include "Segment.h"
#include "BadTrapezium.h"

//there are two defenitions of trapezium.
//1 - quadrangle where two sides are parallel and two others not
//2 - quadrangle where two sides are parallel
//I decide to use second one, because I used to it.
class Trapezium {
	public:
		Trapezium() {};
		~Trapezium() {};
		//in my opiniom these methods could be realized in this class, because they are the same in TrapeziumBase and TrapeziumAxes
		//but accordiing to our task they must be pure virtual
		virtual double area() = 0;
		virtual double perimeter() = 0;
		//create and get middle line
		virtual const Segment& getMidLine() = 0;


		//there were two options to realize tops and sides methods.
		//first, to store them as pointers and create them if we need and change if trapezium changes.
		//but in this case we need additional variables.
		//as in our task we need just "find" tops and sides, I decide not to store them all, and just return new const Point, Segment, if it is needed.
		//in my opinion, it is enough if we want to see these values and we shouldn`t have the ability to change sides and tops, because it can destroy our trapezium.
		virtual const Segment sideAB() = 0;
		virtual const Segment sideBC() = 0;
		virtual const Segment sideCD() = 0;
		virtual const Segment sideAD() = 0;

		virtual const Point pointA() = 0;
		virtual const Point pointB() = 0;
		virtual const Point pointC() = 0;
		virtual const Point pointD() = 0;

		//show trapezium
		//can be hide in private part, but it is better to leave it public, to have opportunity use it not only in output operator.
		virtual ostream& show(ostream&) = 0;

		//arbitrary axis mirroring
		virtual void flip(const Axis)=0;
		//trapezium rotation
		virtual void rotate(const double)=0;
};
//output operator
ostream& operator<<(ostream&,  Trapezium&);