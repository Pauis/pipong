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
	void SOut::GotoXy(int x, int y)
	{
		#ifdef POSIX
		printf("\033[%d;%df", y, x);
		fflush(stdout);
		#endif
	}

	void SOut::PrintColorString(string str, PColor colornum)
	{
		#ifdef POSIX
		printf("\033[%dm%s\033[0m", colornum.GetNum(), str.c_str());
		#endif
	}

	SOut& SOut::operator<<(PRect& rect)
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

	SOut& SOut::operator<<(PString& str)
	{
		#ifdef POSIX

		#endif

		return *this;
	}

	SIn::SIn(void)
	{
		#ifdef POSIX
		regulartset = new struct termios;
		newtset = new struct termios;

		tcgetattr(0, regulartset);
		*newtset = *regulartset;
		(*newtset).c_lflag &= ~ICANON;
		(*newtset).c_lflag &= ~ECHO;
		(*newtset).c_cc[VTIME] = 0;
		(*newtset).c_cc[VMIN] = 0;
		tcsetattr(0, TCSANOW, newtset);
		#endif
	}

	void SIn::operator>>(int& target)
	{
		#ifdef POSIX
		target = getchar();
		#endif
	}

	SIn::~SIn(void)
	{
		#ifdef POSIX
		tcsetattr(0, TCSANOW, regulartset);

		delete regulartset;
		delete newtset;
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
