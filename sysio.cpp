#include <cstdio>
#include <string>
#include "pongcolor.h"
#include "sysio.h"

using std::string;
using pong::PColor;

namespace pong { namespace sys
{
#ifdef POSIX
	SOut& SOut::GotoXY(int x, int y)
	{
		printf("\033[%d;%df", y, x);
		fflush(stdout);

		return *this;
	}

	SOut& SOut::PrintColorString(string str, PColor colornum)
	{
		printf("\033[%dm%s\033[0m", colornum.GetNum(), str.c_str());

		return *this;
	}

	SOut& SOut::PrintColorString(char* str, PColor colornum)
	{
		printf("\033[%dm%s\033[0m", colornum.GetNum(), str);

		return *this;
	}
#endif
}}
