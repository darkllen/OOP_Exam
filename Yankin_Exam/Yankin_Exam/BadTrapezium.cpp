#include "BadTrapezium.h"
BadTrapezium::BadTrapezium(const string& reason) :
	_reason(reason) {
}
//destructor
BadTrapezium::~BadTrapezium() {
}
// method to output error
void BadTrapezium::diagnose() const {
	cerr << "message : " << _reason << endl;
}