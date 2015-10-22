#include <string>
#include "pongobj.h"
#include "pongstring.h"
#include "sysio.h"
#include "pongproperties.h"
#include "pongtrigger.h"

using pong::PString;
using pong::PRect;
using pong::PKProperty;
using pong::PGProperty;
using pong::PGTrigger;
using pong::sys::SOut;
using pong::sys::SInInitial;
using pong::sys::SCurrent;

int main(void)
{
	SOut sout;
	SInInitial sin;
	SCurrent scurrent;
	int keyinput;

	bool signal_terminate = false;
	PGTrigger gmode_event = PGTrigger::LOBBY;
	PGTrigger gmode_stage = PGTrigger::NONE;

	while (signal_terminate != true)
	{
		sin >> keyinput;

		if (gmode_event == PGTrigger(PGTrigger::LOBBY))
		{
			for (; gmode_stage != PGTrigger(PGTrigger::LOBBY); gmode_stage = PGTrigger::LOBBY)
			{
				sout.Clear();

				sout << PString("Pipong - A Classic Table Tennis Game", PColor(PColor::CYAN), Point(60, 30));
				sout << PString("Press 's' to start game", PColor(PColor::DEFAULT), Point(65, 32));
				sout << PString("Press 'q' to exit the game", PColor(PColor::DEFAULT), Point(65, 33));
			}

			if (keyinput == PKProperty::PSTART)
				gmode_event = PGTrigger::INGAME;
			else if (keyinput == PKProperty::PEXIT)
				signal_terminate = true;
		}
		else if (gmode_event == PGTrigger(PGTrigger::INGAME))
		{
			for (; gmode_stage != PGTrigger(PGTrigger::INGAME); gmode_stage = PGTrigger::INGAME)
			{
				sout.Clear();

				sout << PRect(Point(3, 10), 1, 10, PColor(PColor::DEFAULT));
				sout << PRect(Point(100, 10), 1, 10, PColor(PColor::CYAN));
			}

			if (keyinput == PKProperty::PEXIT)
				gmode_event = PGTrigger::LOBBY;
		}

		scurrent.DelayMsec(PGProperty::PCYCLEDELAY);
	}
	return 0;
}
