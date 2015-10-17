#include <cstdio>
#include <string>
#include "pongcolor.h"
#include "sysio.h"

#ifdef LINUX_GPIO_RPI
#include <wiringPi.h>
#endif

using std::string;
using pong::PColor;
using pong::Rect;
using pong::PRect;

namespace pong { namespace sys
{
#ifdef POSIX
	void STtyOut::GotoXy(int x, int y)
	{
		printf("\033[%d;%df", y, x);
		fflush(stdout);
	}

	void STtyOut::PrintColorString(string str, PColor colornum)
	{
		printf("\033[%dm%s\033[0m", colornum.GetNum(), str.c_str());
	}

	STtyOut& STtyOut::operator<<(PRect& rect)
	{
		for(int width=0; width<rect.GetWidth(); width++)
		{
			GotoXy((rect.GetSpoint()).GetXpos(), (rect.GetSpoint()).GetYpos() + width);

			for(int length=0; length<rect.GetLength(); length++)
			{
				PrintColorString("█", rect.GetColor());
			}
		}

		return *this;
	}

	STtyOut& STtyOut::operator<<(PString& str)
	{


		return *this;
	}
#endif

#ifdef LINUX_GPIO_RPI
	void SGpio::SetupBasic(void);
	{
		static int ini = 0;

		if(ini == 0)
		{
			wiringPiSetup();
			ini++;
		}
	}

	SGpio::~SGpio()
	{
		// empty
	}
#endif
}}
