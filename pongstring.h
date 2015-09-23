#ifndef __PONGSTRING_H__
#define __PONGSTRING_H__

#include "pongobj.h"
#include "pongcolor.h"

using std::string;
using pong::PColor;

namespace pong
{
	class PString
	{
	private:
		string str;
		int color;
		Point spoint;
	public:
		PString(string str, int color, Point spoint)
			: str(str), color(color), spoint(spoint)
		{
			// empty
		}
		PString(string str, int color, int xpos, int ypos)
			: str(str), color(color), spoint(xpos, ypos)
		{
			// empty
		}
		PString(string str, Point spoint)
			: str(str), spoint(spoint)
		{
			color = PColor::DEFAULT;
		}
		PString(string str, int xpos, int ypos)
			: str(str), spoint(xpos, ypos)
		{
			color = PColor::DEFAULT;
		}
		PString& Set(string str, int color, Point spoint);
		PString& Set(string str, int color, int xpos, int ypos);
		PString& SetString(string str);
		PString& SetColor(int color);
		PString& SetSpoint(Point spoint);
		PString& SetSpoint(int xpos, int ypos);
		string GetString(void) const;
		int GetColor(void) const;
		Point GetSpoint(void) const;
		const char* c_str(void) const;
	};
}

#endif
