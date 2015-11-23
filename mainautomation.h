#ifndef __MAINAUTOMATION_H__
#define __MAINAUTOMATION_H__

#include "sysio.h"
#include "pongobj.h"

using pong::sys::SOut;
using pong::Point;
using pong::PRect;

class MainAM
{
public:
	static PRect PRectMove(SOut& sout, PRect& prect, Point& pos, PRect& crect);
};

#endif
