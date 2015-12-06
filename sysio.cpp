#include <string>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "pongcolor.h"
#include "sysio.h"

#ifdef POSIX
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>
#endif

using std::string;
using pong::PColor;
using pong::Rect;
using pong::PRect;

namespace pong { namespace sys
{
	#ifdef POSIX
	struct winsize* SOut::wsize = new struct winsize;
	#endif
	int SOut::objnum = 0;

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
		#endif
	}

	SOut::SOut(void)
	{
		if (objnum == 0)
		{
			#ifdef POSIX
			printf("\033[?25l");   // Hide cursor
			printf("\033[?1049h"); // Use alternate screen buffer
			#endif
		}

		objnum++;
	}

	SOut& SOut::Refresh(void)
	{
		#ifdef POSIX
		fflush(stdout);
		#endif

		return *this;
	}

	SOut& SOut::Clear(void)
	{
		#ifdef POSIX
		printf("\033[2J");
		#endif

		return *this;
	}

	int SOut::GetLength(void)
	{
		#ifdef POSIX
		ioctl(STDOUT_FILENO, TIOCGWINSZ, wsize);
		return wsize->ws_col;
		#endif
	}

	int SOut::GetWidth(void)
	{
		#ifdef POSIX
		ioctl(STDOUT_FILENO, TIOCGWINSZ, wsize);
		return wsize->ws_row;
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
			GotoPos(Point(1, GetWidth())); // Move cursor to the end of the command line
			printf("\033[?25h");           // Show cursor
			printf("\033[?1049l");         // Use normal screen buffer
			#endif
		}
	}

	#ifdef POSIX
	struct termios* SIn::regulartset = new struct termios;
	struct termios* SIn::newtset = new struct termios;
	#endif
	int SIn::objnum = 0;

	void SIn::ClearBuf(void)
	{
		while (getchar() != EOF);
	}

	SIn::SIn(void)
	{
		if (objnum == 0)
		{
			#ifdef POSIX
			tcgetattr(0, regulartset);      // Get current attribution
			*newtset = *regulartset;        // Substitute
			(*newtset).c_lflag &= ~ICANON;  // Set noncanonical mode
			(*newtset).c_lflag &= ~ECHO;    // Turn off the echo
			(*newtset).c_cc[VTIME] = 0;     // Zero delay time
			(*newtset).c_cc[VMIN] = 0;      // Don't need any buffer delay

			tcsetattr(0, TCSANOW, newtset); // Apply new setting
			#endif
		}

		objnum++;
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
			tcsetattr(0, TCSANOW, regulartset); // Apply the original setting
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
