#include "RegisterCalc.h"

RegisterCalc::RegisterCalc(Register r):_reg(r)
{
}

RegisterCalc& RegisterCalc::operator=(const RegisterCalc& that)
{
	if (_reg == that._reg) return *this;
	_reg = that._reg;
	return *this;
}


//methods
void RegisterCalc::operationOr()
{
	_reg.setRegister(reg_a, _reg.getRegister(reg_a) | _reg.getRegister(reg_b));
}

void RegisterCalc::operationAnd()
{
	_reg.setRegister(reg_a, _reg.getRegister(reg_a) & _reg.getRegister(reg_b));
}

void RegisterCalc::operationXor()
{
	_reg.setRegister(reg_a, _reg.getRegister(reg_a) ^ _reg.getRegister(reg_b));
}

void RegisterCalc::operationNot()
{
	_reg.setRegister(reg_a, ~_reg.getRegister(reg_a));
}
