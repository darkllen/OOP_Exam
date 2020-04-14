#pragma once
#include "Register.h"


class RegisterCalc {
public:
	//define pointer on methods
	typedef void (RegisterCalc::* const Operation)() ;
	RegisterCalc(Register);
	~RegisterCalc() {};
	RegisterCalc& operator=(const RegisterCalc&);
	//register
	Register _reg;
	Register::Reg reg_a = _reg.getA();
	Register::Reg reg_b = _reg.getB();

	//methods
	void operationOr();
	void operationAnd();
	void operationXor();
	void operationNot();

	//run operation
	void doOperation(Operation c) {
		(this->*c)();
	};
};
