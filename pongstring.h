#ifndef __PONGSTRING_H__
#define __PONGSTRING_H__

#include "pongobj.h"
#include "pongcolor.h"

namespace pong
{
	class PString
	{
	private:
		std::string str;
		pong::PColor color;
		pong::Point spoint;
	public:
		PString(std::string str, pong::PColor color, pong::Point spoint);
		PString(std::string str, pong::PColor color, int xpos, int ypos);
		PString(std::string str, pong::Point spoint);
		PString(std::string str, int xpos, int ypos);
		PString& Set(std::string str, pong::PColor color, pong::Point spoint);
		PString& Set(std::string str, pong::PColor color, int xpos, int ypos);
		PString& SetString(std::string str);
		PString& SetColor(pong::PColor color);
		PString& SetSpoint(pong::Point spoint);
		PString& SetSpoint(int xpos, int ypos);
		PString& SetSxpos(int xpos);
		PString& SetSypos(int ypos);
		std::string GetString(void) const;
		PColor GetColor(void) const;
		Point GetSpoint(void) const;
		const char* c_str(void) const;
	};
}

#endif
