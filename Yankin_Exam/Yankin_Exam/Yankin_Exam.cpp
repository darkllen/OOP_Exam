#include <cassert>
#include "Register.h"
#include "Matrix.h"
#include "Segment.h"
#include "Trapezium.h"
#include "TrapeziumAxes.h"
#include "TrapeziumBase.h"
#include "RegisterCalc.h"

#define M_PI_2  (1.57079632679489661923)
#define M_PI (3.14159265358979323846)

void testTask1() {
	cout << "-----------------------------------------" << endl;
	cout << "test Task 1" << endl;
	cout << "create register" << endl;
	Register a;
	Register::Reg reg_a = a.getA();
	Register::Reg reg_x = a.getX();
	cout << "set _a to 5" << endl;
	a.setRegister(reg_a, 5);
	cout << "get _a" << endl;
	cout << a.getRegister(reg_a)<<endl;
	cout << "set _x to 1" << endl;
	a.setRegister(reg_x, 1);
	cout << "get _x" << endl;
	cout << a.getRegister(reg_x)<<endl;
	cout << "swap _a and _x" << endl;
	a.swap(reg_a, reg_x);
	cout << "get _a" << endl;
	cout << a.getRegister(reg_a)<<endl;
	cout << "get _x" << endl;
	cout << a.getRegister(reg_x)<<endl;
}

void testTask2() {
	cout << "-----------------------------------------" << endl;
	cout << "test Task 2" << endl;
	Register a;
	Register::Reg reg_a = a.getA();
	Register::Reg reg_b = a.getB();
	cout << "set _a to 17" << endl;
	cout << "set _b to 45" << endl;
	a.setRegister(reg_a, 17);
	a.setRegister(reg_b, 45);

	RegisterCalc c(a);
	cout << "c.doOperation(&RegisterCalc::operationAnd)" << endl;
	c.doOperation(&RegisterCalc::operationAnd);
	cout << "get _a"<<endl;
	cout << c._reg.getRegister(reg_a)<<endl;
#ifdef _DEBUG
	c._reg.setRegister(reg_a, 17);
	unsigned int t = c._reg.getRegister(reg_a) & c._reg.getRegister(reg_b);
	c.doOperation(&RegisterCalc::operationAnd);
	assert(t == c._reg.getRegister(reg_a));
#endif // _DEBUG

	cout << "set _a to 17" << endl;
	c._reg.setRegister(reg_a, 17);
	cout << "c.doOperation(&RegisterCalc::operationOr)" << endl;
	c.doOperation(&RegisterCalc::operationOr);
	cout << "get _a" << endl;
	cout << c._reg.getRegister(reg_a) << endl;
#ifdef _DEBUG
	c._reg.setRegister(reg_a, 17);
	t = c._reg.getRegister(reg_a) | c._reg.getRegister(reg_b);
	c.doOperation(&RegisterCalc::operationOr);
	assert(t == c._reg.getRegister(reg_a));
#endif // _DEBUG

	cout << "set _a to 17" << endl;
	c._reg.setRegister(reg_a, 17);
	cout << "c.doOperation(&RegisterCalc::operationXor)" << endl;
	c.doOperation(&RegisterCalc::operationXor);
	cout << "get _a" << endl;
	cout << c._reg.getRegister(reg_a) << endl;
#ifdef _DEBUG
	c._reg.setRegister(reg_a, 17);
	t = c._reg.getRegister(reg_a) ^ c._reg.getRegister(reg_b);
	c.doOperation(&RegisterCalc::operationXor);
	assert(t == c._reg.getRegister(reg_a));
#endif // _DEBUG

	cout << "set _a to 17" << endl;
	c._reg.setRegister(reg_a, 17);
	cout << "c.doOperation(&RegisterCalc::operationNot)" << endl;
	c.doOperation(&RegisterCalc::operationNot);
	cout << "get _a" << endl;
	cout << c._reg.getRegister(reg_a) << endl;
#ifdef _DEBUG
	c._reg.setRegister(reg_a, 17);
	t = ~c._reg.getRegister(reg_a);
	c.doOperation(&RegisterCalc::operationNot);
	assert(t == c._reg.getRegister(reg_a));
#endif // _DEBUG
}

void testTask3() {
	cout << "-----------------------------------------" << endl;
	cout << "test Task 3" << endl;
	cout << "create Matrix a(1,2,3,4)" << endl;
	Matrix a(1, 2, 3, 4);
	cout << a;
	cout << "create Matrix b(a)" << endl;
	Matrix b(a);
	cout << b;
	cout << "a+b" << endl;
	cout << a + b;
#ifdef _DEBUG
	assert(a + b == Matrix(2, 4, 6, 8));
#endif // !_DEBUG

	cout << "a-b" << endl;
	cout << a - b;
#ifdef _DEBUG
	assert(a - b == Matrix(0,0,0,0));
#endif // !_DEBUG
	cout << "a*b" << endl;
	cout << a * b;
#ifdef _DEBUG
	assert(a * b == Matrix(7, 10, 15, 22));
#endif // !_DEBUG
}

void testTask4() {
	cout << "-----------------------------------------" << endl;
	cout << "test Task 4" << endl;
	cout << "create Point a(1,2)"<<endl;
	Point a(1, 2);
	cout << a;
	cout << "a.flip(Axis::X)" << endl;
	a.flip(Axis::X);
	cout << a;
	cout << "a.flip(Axis::Y)" << endl;
	a.flip(Axis::Y);
	cout << a;

#ifdef _DEBUG
	Point b(a);
	a.flip(Axis::X);
	a.flip(Axis::Y);
	a.flip(Axis::X);
	a.flip(Axis::Y);
	assert(b==a);
#endif // !_DEBUG

	cout << "a.rotate(M_PI_2)" << endl;
	a.rotate(M_PI_2);
	cout << a;
	cout << "a.rotate(-M_PI_2)" << endl;
	a.rotate(-M_PI_2);
	cout << a;

#ifdef _DEBUG
	Point c(a);
	a.rotate(M_PI_2);
	a.rotate(-M_PI_2);
	assert(c == a);
#endif // !_DEBUG

}

void testTask5() {
	cout << "-----------------------------------------" << endl;
	cout << "test Task 5" << endl;
	cout << "create Segment a(1, 2, 3, 4)" << endl;
	Segment a(1, 2, 3, 4);
	cout << a;
	cout << "a.flip(Axis::X)" << endl;
	a.flip(Axis::X);
	cout << a;
	cout << "a.flip(Axis::Y)" << endl;
	a.flip(Axis::Y);
	cout << a;

#ifdef _DEBUG
	Segment b(a);
	a.flip(Axis::X);
	a.flip(Axis::Y);
	a.flip(Axis::X);
	a.flip(Axis::Y);
	assert(b == a);
#endif // !_DEBUG

	cout << "a.rotate(M_PI_2)" << endl;
	a.rotate(M_PI_2);
	cout << a;
	cout << "a.rotate(-M_PI_2)" << endl;
	a.rotate(-M_PI_2);
	cout << a;

#ifdef _DEBUG
	Segment c(a);
	a.rotate(M_PI_2);
	a.rotate(-M_PI_2);
	assert(c == a);
#endif // !_DEBUG
}

void testTask6() {
	cout << "-----------------------------------------" << endl;
	cout << "test Task 6" << endl;
	Point a(1, 0);
	Point b(3, 0);
	Point c(7, -3);
	Point d(-3, -3);
	cout << "Points a(1,0), b(3,0), c(5-2), d(-1,-2)" << endl;
	cout << "create TrapeziumAxes e(a,b,c,d)" << endl;
	TrapeziumAxes e(a,b,c,d);
	cout << e;


	cout << "try to create TrapeziumAxes r(a,c,b,d)" << endl;
	try {
		TrapeziumAxes r(a, c, b, d);
	}
	catch (BadTrapezium bad) {
		bad.diagnose();
	}
	cout << "try to create TrapeziumAxes r(a,a,b,d)" << endl;
	try {
		TrapeziumAxes r(a, a, b, d);
	}
	catch (BadTrapezium bad) {
		bad.diagnose();
	}

	cout << "e.area()" << endl;
	cout << e.area() << endl;
	cout << "e.perimeter()" << endl;
	cout << e.perimeter() << endl;

	cout << "sides" << endl;
	cout << e.sideAB() ;
	cout << e.sideBC();
	cout << e.sideCD();
	cout << e.sideAD();

	cout << "e.flip(Axis::X)" << endl;
	e.flip(Axis::X);
	cout << e;
	cout << "e.rotate(M_PI_2)" << endl;
	e.rotate(M_PI_2);
	cout << e;
}

void testTask7() {
	cout << "-----------------------------------------" << endl;
	cout << "test Task 7" << endl;
	Segment a(1, 0, 3, 0);
	Segment b(7, -3, -3, -3);
	cout << "Segment a(1,0,3,0), b(7,-3,-3,-3)" << endl;
	cout << "create TrapeziumBase e(a,b)" << endl;
	TrapeziumBase e(a, b);
	cout << e;


	cout << "try to create TrapeziumBase r(a,a)" << endl;
	try {
		TrapeziumBase r(a,a);
	}
	catch (BadTrapezium bad) {
		bad.diagnose();
	}

	cout << "Segment c(0,0,1,1), d(2,2,3,3)" << endl;
	Segment c(0, 0, 1, 1);
	Segment d(2, 2, 3, 3);

	cout << "try to create TrapeziumBase r(c,d)" << endl;
	try {
		TrapeziumBase r(c, d);
	}
	catch (BadTrapezium bad) {
		bad.diagnose();
	}

	cout << "e.area()" << endl;
	cout << e.area() << endl;
	cout << "e.perimeter()" << endl;
	cout << e.perimeter() << endl;

	cout << "tops" << endl;
	cout << e.pointA() ;
	cout << e.pointB();
	cout << e.pointC();
	cout << e.pointD();

	cout << "e.flip(Axis::X)" << endl;
	e.flip(Axis::X);
	cout << e;
	cout << "e.rotate(M_PI_2)" << endl;
	e.rotate(M_PI_2);
	cout << e;
}

void testTask8() {
	cout << "-----------------------------------------" << endl;
	cout << "test Task 8" << endl;

	cout << "Points a(1,0), b(3,0), c(5-2), d(-1,-2)" << endl;
	cout << "create TrapeziumAxes e(a,b,c,d)" << endl;
	Point a(1, 0);
	Point b(3, 0);
	Point c(7, -3);
	Point d(-3, -3);
	TrapeziumAxes e(a, b, c, d);

	cout << "cast e to TrapeziumBase" << endl;
	(static_cast<TrapeziumBase>(e)).show(cout);

	Segment f(a,b);
	Segment g(c,d);
	cout << "Segment f(a,b), g(c,d)" << endl;
	cout << "create TrapeziumBase h(f,g)" << endl;
	TrapeziumBase h(f, g);

	cout << "cast h to TrapeziumAxes" << endl;
	(static_cast<TrapeziumAxes>(h)).show(cout);

}

void testTask9() {
	cout << "-----------------------------------------" << endl;
	cout << "test Task 9" << endl;
	cout << "Points a(1,0), b(3,0), c(5-2), d(-1,-2)" << endl;
	cout << "create TrapeziumAxes e(a,b,c,d)" << endl;
	Point a(1, 0);
	Point b(3, 0);
	Point c(7, -3);
	Point d(-3, -3);
	TrapeziumAxes e(a, b, c, d);

	cout << "get e._midLine" << endl;
	cout << e.getMidLine();

	Segment f(a, b);
	Segment g(c, d);
	cout << "Segment f(a,b), g(c,d)" << endl;
	cout << "create TrapeziumBase h(f,g)" << endl;
	TrapeziumBase h(f, g);

	cout << "get h._midLine" << endl;
	cout << h.getMidLine();

}

void testTask10() {
	cout << "-----------------------------------------" << endl;
	cout << "test Task 10" << endl;
	Point a(1, 0);
	Point b(3, 0);
	Point c(7, -3);
	Point d(-3, -3);



	cout << "Points a(1,0), b(3,0), c(5-2), d(-1,-2)" << endl;
	cout << "create TrapeziumAxes e(a,b,c,d)" << endl;
	TrapeziumAxes e(a, b, c, d);
	cout << e;

	cout << "Segment f(a,b), g(c,d)" << endl;
	cout << "create TrapeziumBase h(f,g)" << endl;
	Segment f(a, b);
	Segment g(c, d);
	TrapeziumBase h(f, g);
	cout << h;

	cout << "create Trapezium* p = new TrapeziumAxes(a, b, c, d)" << endl;
	Trapezium* p =  new TrapeziumAxes(a, b, c, d);
	cout << *p;

}
int main()
{
	testTask1();
	testTask2();
	testTask3();
	testTask4();
	testTask5();
	testTask6();
	testTask7();
	testTask8();
	testTask9();
	testTask10();

}

