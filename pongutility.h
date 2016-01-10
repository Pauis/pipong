#ifndef __MAINAUTOMATION_H__
#define __MAINAUTOMATION_H__

#include "sysio.h"
#include "pongobj.h"


class MainAM
{
public:
	static pong::PRect PRectMove(pong::sys::SOut& sout, pong::PRect& prect, pong::Point& pos, pong::PRect& crect);
};

#endif
