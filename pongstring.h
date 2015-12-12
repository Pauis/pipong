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
		PString(const std::string& str, const pong::PColor& color, const pong::Point& spoint);
		PString(const std::string& str, const pong::PColor& color, const int& xpos, const int& ypos);
		PString(const std::string& str, const pong::Point& spoint);
		PString(const std::string& str, const int& xpos, const int& ypos);
		PString& Set(const std::string& str, const pong::PColor& color, const pong::Point& spoint);
		PString& Set(const std::string& str, const pong::PColor& color, const int& xpos, const int& ypos);
		PString& SetString(const std::string& str);
		PString& SetColor(const pong::PColor& color);
		PString& SetSpoint(const pong::Point& spoint);
		PString& SetSpoint(const int& xpos, const int& ypos);
		PString& SetSxpos(const int& xpos);
		PString& SetSypos(const int& ypos);
		std::string GetString(void) const;
		PColor GetColor(void) const;
		Point GetSpoint(void) const;
		const char* c_str(void) const;
	};
}

#endif
