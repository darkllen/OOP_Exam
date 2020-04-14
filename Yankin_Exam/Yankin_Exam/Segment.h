#pragma once
#include "Point.h"
class Segment
{
private:
	//start segment point
	Point _a;
	//end segment point
	Point _b;
public:
	//constructor by coordinates with default values
	Segment(const double x1 = 0, const double y1 = 0,
		const double x2 = 1, const double y2 = 0);
	//constructor by points
	Segment(const Point& start, const Point& end);

	//copy constructor
	Segment(const Segment&);

	//destructor
	~Segment();

	//assign operator
	Segment& operator=(const Segment&);

	//points` selectors
	const Point& start() const;
	const Point& end() const;

	//points` selectors-modificators
	Point& start();
	Point& end();

	//coordinate selectors
	const double& startX() const;
	const double& startY() const;
	const double& endX() const;
	const double& endY() const;

	//coordinate selectors-modificators
	double& startX();
	double& startY();
	double& endX();
	double& endY();

	//counting length of segment
	double length() const;

	//arbitrary axis mirroring
	void flip(const Axis);
	//point rotation
	void rotate(const double);
};

//method to check if segment a and b are parallel
bool isParallel(const Segment& a, const Segment& b);
//output operator
ostream& operator<<(ostream&, const Segment&);
//equal operator
bool operator==(const Segment&, const Segment&);


