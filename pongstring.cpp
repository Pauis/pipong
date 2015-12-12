#include <iostream>
#include <string>
#include <cstdio>
#include "pongstring.h"

using std::string;
using pong::Point;
using pong::PColor;

namespace pong
{
	PString::PString(const string& str, const PColor& color, const Point& spoint)
		: str(str), color(color), spoint(spoint)
	{
		// empty
	}

	PString::PString(const string& str, const PColor& color, const int& xpos, const int& ypos)
		: str(str), color(color), spoint(xpos, ypos)
	{
		// empty
	}

	PString::PString(const string& str, const Point& spoint)
		: str(str), spoint(spoint), color(PColor::DEFAULT)
	{
		// empty
	}

	PString::PString(const string& str, const int& xpos, const int& ypos)
		: str(str), spoint(xpos, ypos), color(PColor::DEFAULT)
	{
		// empty
	}

	PString& PString::Set(const string& str, const PColor& color, const Point& spoint)
	{
		(this->str) = str;
		(this->color) = color;
		(this->spoint) = spoint;

		return *this;
	}

	PString& PString::Set(const string& str, const PColor& color, const int& xpos, const int& ypos)
	{
		(this->str) = str;
		(this->color) = color;
		(this->spoint).Set(xpos, ypos);

		return *this;
	}

	PString& PString::SetString(const string& str)
	{
		(this->str) = str;

		return *this;
	}

	PString& PString::SetColor(const PColor& color)
	{
		(this->color) = color;

		return *this;
	}

	PString& PString::SetSpoint(const Point& spoint)
	{
		(this->spoint) = spoint;

		return *this;
	}

	PString& PString::SetSpoint(const int& xpos, const int& ypos)
	{
		(this->spoint).Set(xpos, ypos);

		return *this;
	}

	PString& PString::SetSxpos(const int& xpos)
	{
		(this->spoint).SetXpos(xpos);

		return *this;
	}

	PString& PString::SetSypos(const int& ypos)
	{
		(this->spoint).SetYpos(ypos);

		return *this;
	}

	string PString::GetString(void) const
	{
		return str;
	}

	PColor PString::GetColor(void) const
	{
		return color;
	}

	Point PString::GetSpoint(void) const
	{
		return spoint;
	}

	const char* PString::c_str(void) const
	{
		return str.c_str();
	}
}
