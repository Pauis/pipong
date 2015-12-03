#include <string>
#include <cstdio>
#include <cstdlib>
#include <ctime>
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
	int SOut::objnum = 0;

	SOut::SOut(void)
	{
		if (objnum == 0)
		{
			#ifdef POSIX
			printf("\e[?25l");
			#endif
		}

		objnum++;
	}

	void SOut::GotoPos(int x, int y)
	{
		#ifdef POSIX
		printf("\033[%d;%df", y, x);
		#endif
	}

	void SOut::GotoPos(Point pos)
	{
		GotoPos(pos.GetXpos(), pos.GetYpos());
	}

	void SOut::PrintColorString(string str, PColor colornum)
	{
		#ifdef POSIX
		printf("\033[%dm%s\033[0m", colornum.GetNum(), str.c_str());
		fflush(stdout);
		#endif
	}

	SOut& SOut::Clear(void)
	{
		#ifdef POSIX
		system("clear");
		#endif

		return *this;
	}

	int SOut::GetLength(void)
	{
		#ifdef POSIX
		return 100;
		#endif
	}

	int SOut::GetWidth(void)
	{
		#ifdef POSIX
		return 40;
		#endif
	}

	SOut& SOut::EraseWrite(PRect drect, PRect wrect)
	{
		static SOut sout;
		drect.SetColor(PColor::TRANSPARENT);

		sout << drect << wrect;

		return *this;
	}

	SOut& SOut::operator<<(PRect rect)
	{
		static PColor transp(PColor::TRANSPARENT);
		static PColor dful(PColor::DEFAULT);

		for(int width=0; width<rect.GetWidth(); width++)
		{
			GotoPos((rect.GetSpoint()).GetXpos(), (rect.GetSpoint()).GetYpos() + width);

			for(int length=0; length<rect.GetLength(); length++)
			{
				if (rect.GetColor() == transp)
					PrintColorString(" ", dful);
				else
					PrintColorString("█", rect.GetColor());
			}
		}

		return *this;
	}

	SOut& SOut::operator<<(PString str)
	{
		GotoPos(str.GetSpoint());
		PrintColorString(str.GetString(), str.GetColor());

		return *this;
	}

	SOut::~SOut()
	{
		objnum--;

		if (objnum == 0)
		{
			#ifdef POSIX
			printf("\e[?25h");
			#endif
		}
	}

	#ifdef POSIX
	struct termios* SIn::regulartset = new struct termios;
	struct termios* SIn::newtset = new struct termios;
	#endif
	int SIn::objnum = 0;

	SIn::SIn(void)
	{
		if (objnum == 0)
		{
			#ifdef POSIX
			tcgetattr(0, regulartset);
			*newtset = *regulartset;
			(*newtset).c_lflag &= ~ICANON;
			(*newtset).c_lflag &= ~ECHO;
			(*newtset).c_cc[VTIME] = 0;
			(*newtset).c_cc[VMIN] = 0;

			tcsetattr(0, TCSANOW, newtset);
			#endif
		}

		objnum++;
	}

	void SIn::ClearBuf(void)
	{
		while (getchar() != EOF);
	}

	void SIn::operator>>(int& target)
	{
		#ifdef POSIX
		target = getchar();
		//ClearBuf();
		#endif
	}

	SIn::~SIn()
	{
		objnum--;

		#ifdef POSIX
		if (objnum == 0)
			tcsetattr(0, TCSANOW, regulartset);
		#endif
	}

	SCurrent& SCurrent::DelayMsec(long msec)
	{
		#ifdef POSIX
		static struct timespec tim;
		static int ini = 0;

		if (ini == 0)
			tim.tv_sec = 0;
		tim.tv_nsec = (msec * 1000000L);

		nanosleep(&tim, NULL);
		#endif

		return *this;
	}

	bool SCurrent::CycleTick(int cyclenum)
	{
		static int cycount = 0;

		cycount++;

		if (cycount >= cyclenum)
		{
			cycount = 0;
			return true;
		}
		else
			return false;
	}
}}
