#include <cstdio>
#include <string>
#include "pongcolor.h"
#include "sysio.h"

#ifdef LINUX_GPIO_RPI
#include <wiringPi>
#endif

using std::string;
using pong::PColor;

namespace pong { namespace sys
{
#ifdef POSIX
	void SOut::GotoXY(int x, int y)
	{
		printf("\033[%d;%df", y, x);
		fflush(stdout);
	}

	void SOut::PrintColorString(string str, PColor colornum)
	{
		printf("\033[%dm%s\033[0m", colornum.GetNum(), str.c_str());
	}

	void SOut::PrintColorString(char* str, PColor colornum)
	{
		printf("\033[%dm%s\033[0m", colornum.GetNum(), str);
	}
#endif

#ifdef LINUX_GPIO_RPI
	void SGpio::Setup(void)
	{
		static int ini = 0;

		if(ini == 0)
		{
			wiringPiSetup();
			ini++;
		}
	}
#endif
}}
