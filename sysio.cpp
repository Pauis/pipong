#include <iostream>
#include <string>
#include <cstdio>
#include <ctime>
#include "pongcolor.h"
#include "sysio.h"

#ifdef TARGET_IS_POSIX
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>
#endif
#ifdef TARGET_IS_WIN32
#include <conio.h>
#include <Windows.h>
#endif

using std::cout;
using std::string;
using pong::PColor;
using pong::Rect;
using pong::PRect;

namespace pong { namespace sys
{
#ifdef TARGET_IS_POSIX
	struct winsize SOut::wsize = {0,};
#endif
#ifdef TARGET_IS_WIN32
	HANDLE SOut::windows_termout_handle = GetStdHandle(STD_OUTPUT_HANDLE);
#endif
	int SOut::objnum = 0;

	void SOut::GotoPos(const int& x, const int& y)
	{
#ifdef TARGET_IS_POSIX
		cout << "\033[" << y << ";" << x << "f";
#endif
#ifdef TARGET_IS_WIN32
		COORD wintermpos = {static_cast<SHORT>(x-1), static_cast<SHORT>(y-1)};
		SetConsoleCursorPosition(windows_termout_handle, wintermpos);
#endif
	}

	void SOut::GotoPos(const Point& pos)
	{
		GotoPos(pos.GetXpos(), pos.GetYpos());
	}

	void SOut::PrintColorString(const string& str, const PColor& colornum)
	{
#ifdef TARGET_IS_POSIX
		cout << "\033[" << colornum.GetNum() << "m" << str.c_str() << "\033[0m";
#endif
#ifdef TARGET_IS_WIN32
		cout << str;
#endif
	}

	SOut::SOut(void)
	{
		if (objnum == 0)
		{
#ifdef TARGET_IS_POSIX
			cout << "\033[?25l";                      // Hide cursor
			cout << "\033[?1049h";                    // Use alternate screen buffer
			ioctl(STDOUT_FILENO, TIOCGWINSZ, &wsize); // Get the terminal size
#endif
#ifdef TARGET_IS_WIN32
			CONSOLE_CURSOR_INFO windows_termout_curinfo;
			GetConsoleCursorInfo(windows_termout_handle, &windows_termout_curinfo);
			windows_termout_curinfo.bVisible = 0;
			SetConsoleCursorInfo(windows_termout_handle, &windows_termout_curinfo);
#endif
		}

		objnum++;
	}

	SOut& SOut::Refresh(void)
	{
#ifdef TARGET_IS_POSIX
		fflush(stdout);
#endif

		return *this;
	}

	SOut& SOut::Clear(void)
	{
#ifdef TARGET_IS_POSIX
		cout << "\033[2J";
#endif
#ifdef TARGET_IS_WIN32
		CONSOLE_SCREEN_BUFFER_INFO windows_termout_sbufinfo;
		COORD startpoint = {0, 0};
		DWORD dw;

		GetConsoleScreenBufferInfo(windows_termout_handle, &windows_termout_sbufinfo);
		FillConsoleOutputCharacterA(windows_termout_handle, ' ', windows_termout_sbufinfo.dwSize.X * windows_termout_sbufinfo.dwSize.Y, startpoint, &dw);
		FillConsoleOutputAttribute(windows_termout_handle, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,windows_termout_sbufinfo.dwSize.X * windows_termout_sbufinfo.dwSize.Y, startpoint, &dw);
#endif

		return *this;
	}

	int SOut::GetLength(void)
	{
#ifdef TARGET_IS_POSIX
		return wsize.ws_col;
#endif
#ifdef TARGET_IS_WIN32
		CONSOLE_SCREEN_BUFFER_INFO windows_termout_sbufinfo;
		GetConsoleScreenBufferInfo(windows_termout_handle, &windows_termout_sbufinfo);
		return static_cast<int>(windows_termout_sbufinfo.dwSize.X);
#endif
		return 0;
	}

	int SOut::GetWidth(void)
	{
#ifdef TARGET_IS_POSIX
		return wsize.ws_row;
#endif
#ifdef TARGET_IS_WIN32
		CONSOLE_SCREEN_BUFFER_INFO windows_termout_sbufinfo;
		GetConsoleScreenBufferInfo(windows_termout_handle, &windows_termout_sbufinfo);
		return (static_cast<int>(windows_termout_sbufinfo.dwSize.X))/4;
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
#ifdef TARGET_IS_POSIX
				else
					PrintColorString("█", rect.GetColor());
#endif
#ifdef TARGET_IS_WIN32
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
			GotoPos(Point(1, GetWidth())); // Move cursor to the end of the command line

#ifdef TARGET_IS_POSIX
			cout << "\033[?25h";           // Show cursor
			cout << "\033[?1049l";         // Use normal screen buffer
#endif
#ifdef TARGET_IS_WIN32
			CONSOLE_CURSOR_INFO windows_termout_curinfo;
			GetConsoleCursorInfo(windows_termout_handle, &windows_termout_curinfo);
			windows_termout_curinfo.bVisible = 1;
			SetConsoleCursorInfo(windows_termout_handle, &windows_termout_curinfo);
#endif
		}
	}

#ifdef TARGET_IS_POSIX
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
#ifdef TARGET_IS_POSIX
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
#ifdef TARGET_IS_POSIX
		target = getchar();
		//ClearBuf();
#endif
#ifdef TARGET_IS_WIN32
		if (_kbhit())
			target = _getch();
		else
			target = -1;
#endif
	}

	SIn::~SIn()
	{
		objnum--;

#ifdef TARGET_IS_POSIX
		if (objnum == 0)
			tcsetattr(0, TCSANOW, &regulartset); // Apply the original setting
#endif
	}

	SCurrent& SCurrent::DelayMsec(const long& msec)
	{
#ifdef TARGET_IS_POSIX
		static struct timespec tim;
		static int ini = 0;

		if (ini == 0)
			tim.tv_sec = 0;
		tim.tv_nsec = (msec * static_cast<long>(1000000));

		nanosleep(&tim, NULL);
#endif
#ifdef TARGET_IS_WIN32
		Sleep(msec);
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
