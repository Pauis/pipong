#include <string>
#include "pongobj.h"
#include "pongstring.h"
#include "sysio.h"
#include "pongproperties.h"
#include "pongtrigger.h"
#include "mainautomation.h"

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
	// System Object
	SOut sout;
	SInInitial sin;
	SCurrent scurrent;
	int keyinput;

	// System Setting
	int terminal_length = sout.GetLength();
	int terminal_width = sout.GetWidth();

	// Game Object
	PRect boundary_up = PRect(3, 1, terminal_length-4, 1, PColor(PColor::DEFAULT));
	PRect boundary_down = PRect(3, terminal_width, terminal_length-4, 1, PColor(PColor::DEFAULT));
	PRect boundary_left = PRect(2, 1, 1, terminal_width, PColor(PColor::DEFAULT));
	PRect boundary_right = PRect(terminal_length-1, 1, 1, terminal_width, PColor(PColor::DEFAULT));
	PRect boundary_court = PRect(3, 2, terminal_length-4, terminal_width-2, PColor(PColor::DEFAULT));
	PRect lcursor = PRect(2, terminal_width/2-2, 1, 8, PColor(PColor::DEFAULT));
	PRect rcursor = PRect(terminal_length-1, terminal_width/2-2, 1, 8, PColor(PColor::DEFAULT));
	PRect ball = PRect(terminal_length/2, terminal_width/2, 1, 1, PColor(PColor::DEFAULT));
	PRect pbuf;

	// Game Setting
	int ball_lr = -1;
	int ball_ud = 1;
	bool signal_terminate = false;
	PGTrigger gmode_event = PGTrigger::LOBBY;
	PGTrigger gmode_stage = PGTrigger::NONE;

	// Game Logic
	while (signal_terminate != true)
	{
		sin >> keyinput;

		if (gmode_event == PGTrigger(PGTrigger::LOBBY))
		{
			for (; gmode_stage != PGTrigger(PGTrigger::LOBBY); gmode_stage.Set(PGTrigger::LOBBY))
			{
				sout.Clear();

				boundary_up.SetColor(PColor(PColor::BLUE));
				boundary_down.SetColor(PColor(PColor::BLUE));
				sout << boundary_up << boundary_down;

				sout << PString("Pipong - Classic Table Tennis Game", PColor(PColor::CYAN), Point(terminal_length/2-16, terminal_width/2-2));
				sout << PString("Press 's' to start game", PColor(PColor::DEFAULT), Point(terminal_length/2-13, terminal_width/2));
				sout << PString("Press 'q' to exit the game", PColor(PColor::DEFAULT), Point(terminal_length/2-13, terminal_width/2+1));
			}

			if (keyinput == PKProperty::PSTART)
				gmode_event.Set(PGTrigger::INGAME);
			else if (keyinput == PKProperty::PEXIT)
				signal_terminate = true;
		}
		else if (gmode_event == PGTrigger(PGTrigger::INGAME))
		{
			for (; gmode_stage != PGTrigger(PGTrigger::INGAME); gmode_stage.Set(PGTrigger::INGAME))
			{
				sout.Clear();

				boundary_up.SetColor(PColor(PColor::CYAN));
				boundary_down.SetColor(PColor(PColor::CYAN));
				lcursor.SetSypos(terminal_width/2-4);
				rcursor.SetSypos(terminal_width/2-4);
				ball.SetSxpos(terminal_length/2);
				ball.SetSypos(terminal_width/2);
				sout << boundary_up << boundary_down << lcursor << rcursor << ball;
			}

			if (keyinput == PKProperty::PEXIT)
				gmode_event.Set(PGTrigger::LOBBY);
			else if (keyinput == PKProperty::PP1UP)
			{
				MainAM::PRectMove(sout, lcursor, 0, -1, boundary_left);
			}
			else if (keyinput == PKProperty::PP1DOWN)
			{
				MainAM::PRectMove(sout, lcursor, 0, 1, boundary_left);
			}
			else if (keyinput == PKProperty::PP2UP)
			{
				MainAM::PRectMove(sout, rcursor, 0, -1, boundary_right);
			}
			else if (keyinput == PKProperty::PP2DOWN)
			{
				MainAM::PRectMove(sout, rcursor, 0, 1, boundary_right);
			}

			if (scurrent.TimeTick(PGProperty::PBALLFREQ))
			{
				pbuf = MainAM::PRectMove(sout, ball, ball_lr, ball_ud, boundary_court);

				if (boundary_up.CheckInclude(pbuf) || boundary_down.CheckInclude(pbuf))
					ball_ud = -ball_ud;

				if (boundary_left.CheckInclude(pbuf) || boundary_right.CheckInclude(pbuf))
				{
					if (lcursor.CheckInclude(pbuf) || rcursor.CheckInclude(pbuf))
						ball_lr = -ball_lr;
					else
						gmode_event.Set(PGTrigger::LOBBY);
				}
			}
		}

		scurrent.DelayMsec(PGProperty::PCYCLEDELAY);
	}
	return 0;
}
