#include <iostream>
#include "pongstring.h"

using std::ostream;
using std::endl;

namespace pong
{
	const char* PString::c_str(void)
	{
		return str.c_str();
	}

	ostream& operator<<(ostream& os, const PString& pstr)
	{
		os << "[String:" << pstr.str << ", Color:" << pstr.color << ", Position:"<< pstr.pos << ']';
		return os;
	}
}
