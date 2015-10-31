#ifndef __MAINAUTOMATION_H__
#define __MAINAUTOMATION_H__

#include "sysio.h"
#include "pongobj.h"

using pong::sys::SOut;
using pong::PRect;

class MainAM
{
public:
	static void PRectMove(SOut& sout, PRect& prect, int lr, int ud, PRect& crect);
};

#endif
