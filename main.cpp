#include "clitl/clitl.hpp"
#include <iostream>

enum class gamemode {
    NONE,
    LOBBY,
    INGAME,
};

int main(void) {
    using namespace std;
    using namespace clitl;
    using clitl::outbuf;
    using clitl::ostream;
    typedef pair<coord_t, coord_t> coordpair;

	// Customized System Object
    outbuf obuf;
    ostream cliout(&obuf);
	int keyinput;

	// System Setting
	coordpair terminal_size = cliout.screensize();

	// Game Object
    rect<coord_t> boundary_up(coordpair(3, 2),
        coordpair(terminal_size.first - 5, 2));
    rect<coord_t> boundary_down(coordpair(3, terminal_size.second - 1),
        coordpair(terminal_size.first - 5, terminal_size.second - 1));
    rect<coord_t> boundary_left(coordpair(2, 2),
        coordpair(2, terminal_size.second - 2));
    rect<coord_t> boundary_right(coordpair(terminal_size.first - 1, 2),
        coordpair(terminal_size.first - 1, terminal_size.second - 2));
    rect<coord_t> boundary_court(coordpair(3, 3),
        coordpair(terminal_size.first - 6, terminal_size.second - 5));
    rect<coord_t> lcursor(coordpair(2, terminal_size.second / 2 - 2),
        coordpair(2, terminal_size.second / 2 + 4));
    rect<coord_t> rcursor(coordpair(terminal_size.first - 1, terminal_size.second / 2 - 2),
        coordpair(terminal_size.first - 1, terminal_size.second / 2 + 4));
    rect<coord_t> ball(coordpair(terminal_size.first / 2, terminal_size.second / 2),
        coordpair(terminal_size.first / 2, terminal_size.second / 2));
	rect<coord_t> rectbuf;
    /*
	// Game Setting
	Point ballmovevector(-1, 1);
	bool signal_terminate = false;
	PGTrigger gmode_event = PGTrigger::LOBBY;
	PGTrigger gmode_stage = PGTrigger::NONE;
	PGTrigger gmode_lobby = PGTrigger::LOBBY;
	PGTrigger gmode_ingame = PGTrigger::INGAME;

	// Game Logic
	while (signal_terminate != true) {
		ssin >> keyinput;

		if (gmode_event == gmode_lobby) {
			for (; gmode_stage != gmode_lobby; gmode_stage.Set(PGTrigger::LOBBY)) {
				sout.Clear();

				boundary_up.SetColor(PColor(PColor::BLUE));
				boundary_down.SetColor(PColor(PColor::BLUE));

				sout << boundary_up << boundary_down
					<< PString("Pipong - Classic Table Tennis Game",
							PColor(PColor::CYAN),
							Point(terminal_length/2-20, terminal_width/2-2))
					<< PString(string("Press '") + string("s") + string("' to start"),
							Point(terminal_length/2-12, terminal_width/2))
					<< PString(string("Press '") + string("q") + string("' to end"),
							Point(terminal_length/2-12, terminal_width/2+1))
					<< PString("See more details on https://github.com/pauis/pipong.",
							Point(terminal_length/2-20, terminal_width/2+3));
			}

			if (keyinput == PKProperty::PSTART) {
				gmode_event.Set(PGTrigger::INGAME);
			}
			else if (keyinput == PKProperty::PEXIT) {
				signal_terminate = true;
			}
		}
		else if (gmode_event == gmode_ingame) {
			for (; gmode_stage != gmode_ingame; gmode_stage.Set(PGTrigger::INGAME)) {
				sout.Clear();

				boundary_up.SetColor(PColor(PColor::CYAN));
				boundary_down.SetColor(PColor(PColor::CYAN));
				lcursor.SetSypos(terminal_width/2-4);
				rcursor.SetSypos(terminal_width/2-4);
				ball.SetSpoint(terminal_length/2, terminal_width/2);
				sout << boundary_up << boundary_down << lcursor << rcursor << ball;
			}

			if (keyinput == PKProperty::PEXIT) {
				gmode_event.Set(PGTrigger::LOBBY);
			}
			else if (keyinput == PKProperty::PP1UP) {
				MainAM::PRectMove(sout, lcursor, upmovevector, boundary_left);
			}
			else if (keyinput == PKProperty::PP1DOWN) {
				MainAM::PRectMove(sout, lcursor, downmovevector, boundary_left);
			}
			else if (keyinput == PKProperty::PP2UP) {
				MainAM::PRectMove(sout, rcursor, upmovevector, boundary_right);
			}
			else if (keyinput == PKProperty::PP2DOWN) {
				MainAM::PRectMove(sout, rcursor, downmovevector, boundary_right);
			}

			if (scurrent.CycleTick(PGProperty::PBALLFREQ)) {
				pbuf = MainAM::PRectMove(sout, ball, ballmovevector, boundary_court);

				if (boundary_up.CheckInclude(pbuf) || boundary_down.CheckInclude(pbuf)) {
					ballmovevector.SetYpos(-(ballmovevector.GetYpos()));
				}

				if (boundary_left.CheckInclude(pbuf) || boundary_right.CheckInclude(pbuf)) {
					if (lcursor.CheckInclude(pbuf) || rcursor.CheckInclude(pbuf)) {
						ballmovevector.SetXpos(-(ballmovevector.GetXpos()));
					}
					else {
						gmode_event.Set(PGTrigger::LOBBY);
					}
				}
			}
		}

		sout.Refresh();
		scurrent.DelayMsec(PGProperty::PCYCLEDELAY);
	}

	return 0;
    */
}
