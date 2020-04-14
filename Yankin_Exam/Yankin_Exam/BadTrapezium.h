#pragma once
#include <iostream>
using namespace std;
//error class
class BadTrapezium {
private:
	string _reason;
public:
	//constructor
	BadTrapezium(const string& reason = "");
	//destructor
	~BadTrapezium();
	void diagnose() const;
};