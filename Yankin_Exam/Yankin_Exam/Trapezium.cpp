#include "Trapezium.h"

//output operator
ostream& operator<<(ostream& os,  Trapezium& that)
{
	that.show(os);
	return os;
}
