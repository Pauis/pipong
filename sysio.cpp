#include <iostream>
#include <string>
#include <cstdio>
#include <ctime>
#include "pongcolor.h"
#include "sysio.h"

#ifdef POSIX
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>
#endif
#ifdef WIN32
#include <Windows.h>
#endif

using std::cout;
using std::string;
using pong::PColor;
using pong::Rect;
using pong::PRect;

namespace pong { namespace sys
{
#ifdef POSIX
	struct winsize SOut::wsize = {0,};
#endif
#ifdef WIN32
	HANDLE SOut::win_termout_handle = GetStdHandle(STD_OUTPUT_HANDLE);
#endif
	int SOut::objnum = 0;

	void SOut::GotoPos(const int& x, const int& y)
	{
#ifdef POSIX
		cout << "\033[" << y << ";" << x << "f";
#endif
#ifdef WIN32
		static COORD wintermpos = {static_cast<SHORT>(x-1), static_cast<SHORT>(y-1)};
		SetConsoleCursorPosition(win_termout_handle, wintermpos);
#endif
	}

	void SOut::GotoPos(const Point& pos)
	{
		GotoPos(pos.GetXpos(), pos.GetYpos());
	}

	void SOut::PrintColorString(const string& str, const PColor& colornum)
	{
#ifdef POSIX
		cout << "\033[" << colornum.GetNum() << "m" << str.c_str() << "\033[0m";
#endif
#ifdef WIN32
		cout << str;
#endif
	}

	SOut::SOut(void)
	{
		if (objnum == 0)
		{
#ifdef POSIX
			cout << "\033[?25l";                      // Hide cursor
			cout << "\033[?1049h";                    // Use alternate screen buffer
			ioctl(STDOUT_FILENO, TIOCGWINSZ, &wsize); // Get the terminal size
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
		cout << "\033[2J";
#endif

		return *this;
	}

	int SOut::GetLength(void)
	{
#ifdef POSIX
		return wsize.ws_col;
#endif
		return 0;
	}

	int SOut::GetWidth(void)
	{
#ifdef POSIX
		return wsize.ws_row;
#endif
		return 0;
	}

	SOut& SOut::EraseWrite(PRect drect, PRect wrect)
	{
		static SOut sout;
		drect.SetColor(PColor::VOIDSPACE);

		sout << drect << wrect;

		return *this;
	}

	SOut& SOut::operator<<(PRect rect)
	{
		static PColor transp(PColor::VOIDSPACE);
		static PColor dful(PColor::DEFAULT);

		for(int width=0; width<rect.GetWidth(); width++)
		{
			GotoPos((rect.GetSpoint()).GetXpos(), (rect.GetSpoint()).GetYpos() + width);

			for(int length=0; length<rect.GetLength(); length++)
			{
				if (rect.GetColor() == transp)
					PrintColorString(" ", dful);
#ifdef POSIX
				else
					PrintColorString("█", rect.GetColor());
#endif
#ifdef WIN32
				else
					PrintColorString("@", rect.GetColor());
#endif
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
			cout << "\033[?25h";           // Show cursor
			cout << "\033[?1049l";         // Use normal screen buffer
#endif
		}
	}

#ifdef POSIX
	struct termios SIn::regulartset = {0,};
	struct termios SIn::newtset = {0,};
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
			tcgetattr(0, &regulartset);      // Get current attribution
			newtset = regulartset;           // Substitute
			newtset.c_lflag &= ~ICANON;      // Set noncanonical mode
			newtset.c_lflag &= ~ECHO;        // Turn off the echo
			newtset.c_cc[VTIME] = 0;         // Zero delay time
			newtset.c_cc[VMIN] = 0;          // Don't need any buffer delay

			tcsetattr(0, TCSANOW, &newtset); // Apply new setting
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
			tcsetattr(0, TCSANOW, &regulartset); // Apply the original setting
#endif
	}

	SCurrent& SCurrent::DelayMsec(const long& msec)
	{
#ifdef POSIX
		static struct timespec tim;
		static int ini = 0;

		if (ini == 0)
			tim.tv_sec = 0;
		tim.tv_nsec = (msec * static_cast<long>(1000000));

		nanosleep(&tim, NULL);
#endif

		return *this;
	}

	bool SCurrent::CycleTick(const int& cyclenum)
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
