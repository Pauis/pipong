#ifndef __PONGSTRING_H__
#define __PONGSTRING_H__

#include "pongobj.h"

using std::ostream;
using std::string;

namespace pong
{
	class PString
	{
	private:
		string str;
		string color;
		Point pos;
	public:
		PString(string str, string color, Point pos)
			: str(str), color(color), pos(pos)
		{
			// empty
		}
		PString(string str, string color, int x, int y)
			: str(str), color(color), pos(x, y)
		{
			// empty
		}
		PString(string str, Point pos)
			: str(str), pos(pos)
		{
			color = "default";
		}
		PString(string str, int x, int y)
			: str(str), pos(x, y)
		{
			color = "default";
		}
		PString(string str)
			: str(str), pos(0, 0)
		{
			color = "default";
		}
		const char* c_str(void);
		PString& ShowElement(void);
		friend ostream& operator<<(ostream& os, const PString& pstr);
	};
}

#endif
