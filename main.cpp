#include <iostream>
#include "pongobj.h"
#include "sysio.h"

using pong::sys::SOut;
using pong::sys::SInInitial;
using pong::sys::SCurrent;

typedef enum __gamemode
{
	LOBBY = 0,
	GAME  = 1,
} gamemode;

int main(void)
{
	SOut sout;
	SInInitial sin;
	SCurrent scurrent;

	bool signal_terminate;
	int keyinput;
	gamemode gmode;

	sout.Clear();

	while (signal_terminate != true)
	{
		sin >> keyinput;

		if (keyinput == 'q')
			signal_terminate = true;
	}

	return 0;
}
