#include <iostream>
#include <string>
#include <cstdio>
#include "pongstring.h"

using std::ostream;
using std::cout;
using std::endl;
using std::string;

namespace pong
{
	const char* PString::c_str(void)
	{
		return str.c_str();
	}
}
