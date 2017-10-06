#include "clitl/clitl.hpp"
#include <iostream>
#include <thread>

#define UNIT_CLOCK 40
#define BALLFREQ 2

enum class fkey {
    NONE = EOF,
    START = 's',
    EXIT = 'q',
    P1PADUP = 'e',
    P1PADDOWN = 'f',
    P2PADUP = 'o',
    P2PADDOWN = 'k',
};

enum class gamemode {
    NONE,
    LOBBY,
    INGAME,
};

int main(void) {
    using namespace std;
    using namespace clitl;
    using clitl::streambuf;
    using clitl::ostream;
    using clitl::istream;
    typedef pair<coord_t, coord_t> coordpair;

	// Customized System Object
    streambuf obuf;
    ostream cliout(&obuf);
    streambuf ibuf;
    istream cliin(&ibuf);
    char rawinput[2];
    fkey keyinput;

	// System Setting
	coordpair terminal_size = cliout.screensize();

	// Game Object
    rect<> boundary_up(coordpair(3, 2),
        coordpair(terminal_size.first - 2, 2));
    rect<> boundary_down(coordpair(3, terminal_size.second - 1),
        coordpair(terminal_size.first - 2, terminal_size.second - 1));
    rect<> boundary_left(coordpair(2, 3),
        coordpair(2, terminal_size.second - 2));
    rect<> boundary_right(coordpair(terminal_size.first - 1, 3),
        coordpair(terminal_size.first - 1, terminal_size.second - 2));
    rect<> boundary_court(coordpair(3, 3),
        coordpair(terminal_size.first - 2, terminal_size.second - 2));
    rect<> lcursor(coordpair(2, terminal_size.second / 2 - 2),
        coordpair(2, terminal_size.second / 2 + 4), color::CYAN);
    rect<> rcursor(coordpair(terminal_size.first - 1, terminal_size.second / 2 - 2),
        coordpair(terminal_size.first - 1, terminal_size.second / 2 + 4), color::CYAN);
    rect<> ball(coordpair(terminal_size.first / 2, terminal_size.second / 2),
        coordpair(terminal_size.first / 2, terminal_size.second / 2));

    coordpair upmovevector(0, -1);
    coordpair downmovevector(0, 1);
    coordpair ballmovevector(-1, 1);
    rect<> rectbuf;
    auto timepoint_start = chrono::system_clock::now();
    bool signal_terminate = false;
    gamemode gmode_event = gamemode::LOBBY;
    gamemode gmode_staged = gamemode::NONE;

    // Main Loop
    cliout << pre_process;

    while (signal_terminate == false) {
        cliin >> rawinput;
        keyinput = static_cast<fkey>(rawinput[0]);

        if (gmode_event == gamemode::LOBBY) {
            for (; gmode_staged != gamemode::LOBBY; gmode_staged = gamemode::LOBBY) {
                cliout << clear;

                boundary_up.set_background(color::BLUE);
                boundary_down.set_background(color::BLUE);
                cliout << boundary_up << boundary_down
                    << coloredstring<>(coordpair(terminal_size.first / 2 - 20, terminal_size.second / 2 - 2),
                        "Pipong - Classic Table Tennis Game", color::CYAN, color::DEFAULT)
                    << coloredstring<>(coordpair(terminal_size.first / 2 - 12, terminal_size.second / 2),
                        string("Press '") + string("s") + string("' to start"))
                    << coloredstring<>(coordpair(terminal_size.first / 2 - 12, terminal_size.second / 2 + 1),
                        string("Press '") + string("q") + string("' to end"))
                    << coloredstring<>(coordpair(terminal_size.first / 2 - 20, terminal_size.second / 2 + 3),
                        "See more details on https://github.com/pauis/pipong.");
            }

            if (keyinput == fkey::START) {
                gmode_event = gamemode::INGAME;
            }
            else if (keyinput == fkey::EXIT) {
                signal_terminate = true;
            }
        }

        else if (gmode_event == gamemode::INGAME) {
            for (; gmode_staged != gamemode::INGAME; gmode_staged = gamemode::INGAME) {
                cliout << clear;

                boundary_up.set_background(color::CYAN);
                boundary_down.set_background(color::CYAN);
                lcursor.set_origin(coordpair(2, terminal_size.second / 2 - 2));
                lcursor.set_endpoint(coordpair(2, terminal_size.second / 2 + 4));
                rcursor.set_origin(coordpair(terminal_size.first - 1, terminal_size.second / 2 - 2));
                rcursor.set_endpoint(coordpair(terminal_size.first - 1, terminal_size.second / 2 + 4));
                ball.set_origin(coordpair(terminal_size.first / 2, terminal_size.second / 2));
                ball.set_endpoint(coordpair(terminal_size.first / 2, terminal_size.second / 2));
                cliout << boundary_up << boundary_down << lcursor << rcursor << ball;
            }

            auto rectmove = [&] (
                rect<>& prect, const coordpair& pos, const rect<>& crect) {
                rect<> rbuf;
                rect<> rfinal;

                rbuf = prect;
                prect.set_origin(coordpair(prect.get_origin().first + pos.first,
                    prect.get_origin().second + pos.second));
                prect.set_endpoint(coordpair(prect.get_endpoint().first + pos.first,
                    prect.get_endpoint().second + pos.second));
                rfinal = prect;

                if (crect.check_cover(prect) == false) {
                    prect = rbuf;
                    return rfinal;
                }
                else {
                    cliout << rbuf.set_background(color::DEFAULT);
                    cliout << prect;
                    return rfinal;
                }
            };

            if (keyinput == fkey::EXIT) {
                gmode_event = gamemode::LOBBY;
            }
            else if (keyinput == fkey::P1PADUP) {
                rectmove(lcursor, upmovevector, boundary_left);
            }
            else if (keyinput == fkey::P1PADDOWN) {
                rectmove(lcursor, downmovevector, boundary_left);
            }
            else if (keyinput == fkey::P2PADUP) {
                rectmove(rcursor, upmovevector, boundary_right);
            }
            else if (keyinput == fkey::P2PADDOWN) {
                rectmove(rcursor, downmovevector, boundary_right);
            }

            if (chrono::system_clock::now() >
                timepoint_start + chrono::milliseconds(UNIT_CLOCK * BALLFREQ)) {
                timepoint_start = chrono::system_clock::now();

                auto pbuf = rectmove(ball, ballmovevector, boundary_court);

                if (boundary_up.check_cover(pbuf) || boundary_down.check_cover(pbuf)) {
                    ballmovevector.second = -ballmovevector.second;
                }
                if (boundary_left.check_cover(pbuf) || boundary_right.check_cover(pbuf)) {
                    if (lcursor.check_cover(pbuf) || rcursor.check_cover(pbuf)) {
                        ballmovevector.first = -ballmovevector.first;
                    }
                    else {
                        gmode_event = gamemode::LOBBY;
                    }
                }
            }
        }

        std::this_thread::sleep_for(chrono::milliseconds(UNIT_CLOCK));
    }

    cliout << post_process;
}
