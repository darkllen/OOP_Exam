#pragma once

class Register {
private:
	//registers.
	//_a and _b - main
	//_x and _y - for help
	unsigned int _a, _b, _x, _y;
public:
	Register(unsigned int a = 0, unsigned int b = 0, unsigned int x = 0, unsigned int y = 0);
	Register(Register&);
	~Register() {};
	Register& operator=(const Register&);
	bool operator==(const Register&);

	using Reg =unsigned int Register::*;
	Reg getA() { return &Register::_a; };
	Reg getB() { return &Register::_b; };
	Reg getX() { return &Register::_x; };
	Reg getY() { return &Register::_y; };

	//getter for any register
	inline unsigned int getRegister(Reg&);
	//setter for any register
	inline void setRegister(Reg&, unsigned int);
	//swap 2 any registers
	inline void swap(Reg&, Reg&);

};


inline Register::Register(unsigned int a, unsigned int b, unsigned int x, unsigned int y): _a(a), _b(b), _x(x), _y(y)
{
}

inline Register::Register(Register& that): _a(that._a), _b(that._b), _x(that._x), _y(that._y)
{
}

inline Register& Register::operator=(const Register& that)
{
	if (this == &that) return *this;
	_a = that._a;
	_b = that._b;
	_x = that._x;
	_y = that._y;
}

inline bool Register::operator==(const Register& that)
{
	return _a==that._a && _b==that._b && _x==that._x && _y==that._y;
}

unsigned int Register::getRegister(Reg& that) {
	return this->*that;
}

void Register::setRegister(Reg& that, unsigned int val) {
	this->*that = val;
}

inline void Register::swap(Reg& a, Reg& b)
{
	this->*a ^= this->*b;
	this->*b ^= this->*a;
	this->*a ^= this->*b;
}
