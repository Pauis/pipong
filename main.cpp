#include <iostream>
#include "pongobj.h"
#include "sysio.h"
#include "pongproperties.h"

using pong::PProperty;
using pong::sys::SOut;
using pong::sys::SInInitial;
using pong::sys::SCurrent;

typedef enum __gamemode
{
	LOBBY,
	INGAME,
} gamemode;

int main(void)
{
	SOut sout;
	SInInitial sin;
	SCurrent scurrent;

	bool signal_terminate = false;
	int keyinput;
	gamemode gmode;

	sout.Clear();
	gmode = LOBBY;

	while (signal_terminate != true)
	{
		sin >> keyinput;

		if (gmode == LOBBY)
		{
			if (keyinput == 's')
				gmode = INGAME;
			if (keyinput == 'q')
				signal_terminate = true;
		}

		scurrent.DelayMsec(PProperty::PCYCLEDELAY);
	}

	return 0;
}
