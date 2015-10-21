#ifndef __PONGSTRING_H__
#define __PONGSTRING_H__

#include "pongobj.h"
#include "pongcolor.h"

using std::string;
using pong::Point;
using pong::PColor;

namespace pong
{
	class PString
	{
	private:
		string str;
		PColor color;
		Point spoint;
	public:
		PString(string str, int color, Point spoint);
		PString(string str, int color, int xpos, int ypos);
		PString(string str, Point spoint);
		PString(string str, int xpos, int ypos);
		PString& Set(string str, int color, Point spoint);
		PString& Set(string str, int color, int xpos, int ypos);
		PString& SetString(string str);
		PString& SetColor(int color);
		PString& SetSpoint(Point spoint);
		PString& SetSpoint(int xpos, int ypos);
		PString& SetSxpos(int xpos);
		PString& SetSypos(int ypos);
		string GetString(void) const;
		PColor GetColor(void) const;
		Point GetSpoint(void) const;
		const char* c_str(void) const;
	};
}

#endif
