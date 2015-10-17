#include <cstdio>
#include <string>
#include "pongcolor.h"
#include "sysio.h"

#ifdef POSIX
#include <termios.h>
#endif
#ifdef LINUX_GPIO_RPI
#include <wiringPi.h>
#endif

using std::string;
using pong::PColor;
using pong::Rect;
using pong::PRect;

namespace pong { namespace sys
{
	void STtyOut::GotoXy(int x, int y)
	{
		#ifdef POSIX
		printf("\033[%d;%df", y, x);
		fflush(stdout);
		#endif
	}

	void STtyOut::PrintColorString(string str, PColor colornum)
	{
		#ifdef POSIX
		printf("\033[%dm%s\033[0m", colornum.GetNum(), str.c_str());
		#endif
	}

	STtyOut& STtyOut::operator<<(PRect& rect)
	{
		#ifdef POSIX
		for(int width=0; width<rect.GetWidth(); width++)
		{
			GotoXy((rect.GetSpoint()).GetXpos(), (rect.GetSpoint()).GetYpos() + width);

			for(int length=0; length<rect.GetLength(); length++)
			{
				PrintColorString("█", rect.GetColor());
			}
		}
		#endif

		return *this;
	}

	STtyOut& STtyOut::operator<<(PString& str)
	{
		#ifdef POSIX

		#endif

		return *this;
	}

	STtyIn::STtyIn(void)
	{
		#ifdef POSIX
		tcgetattr(0, &regulartset);
		newtset = regulartset;
		newtset.c_lflag &= ~ICANON;
		newtset.c_lflag &= ~ECHO;
		newtset.c_cc[VTIME] = 0;
		newtset.c_cc[VMIN] = 0;
		tcsetattr(0, TCSANOW, &newtset);
		#endif
	}

	void STtyIn::operator>>(char& target)
	{
		#ifdef POSIX
		target = getchar();
		#endif
	}

	STtyIn::~STtyIn(void)
	{
		#ifdef POSIX
		tcsetattr(0, TCSANOW, &regulartset);
		#endif
	}

	void SGpio::SetupBasic(void)
	{
		#ifdef LINUX_GPIO_RPI
		static int ini = 0;

		if(ini == 0)
		{
			wiringPiSetup();
			ini++;
		}
		#endif
	}

	SGpio::~SGpio()
	{
		// empty
	}
}}
