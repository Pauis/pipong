#include <iostream>
#include <string>
#include <cstdio>
#include "pongstring.h"

using std::string;
using pong::Point;
using pong::PColor;

namespace pong
{
	PString::PString(string str, PColor color, Point spoint)
		: str(str), color(color), spoint(spoint)
	{
		// empty
	}

	PString::PString(string str, PColor color, int xpos, int ypos)
		: str(str), color(color), spoint(xpos, ypos)
	{
		// empty
	}

	PString::PString(string str, Point spoint)
		: str(str), spoint(spoint), color(PColor::DEFAULT)
	{
		// empty
	}

	PString::PString(string str, int xpos, int ypos)
		: str(str), spoint(xpos, ypos), color(PColor::DEFAULT)
	{
		// empty
	}

	PString& PString::Set(string str, PColor color, Point spoint)
	{
		(this->str) = str;
		(this->color) = color;
		(this->spoint) = spoint;

		return *this;
	}

	PString& PString::Set(string str, PColor color, int xpos, int ypos)
	{
		(this->str) = str;
		(this->color) = color;
		(this->spoint).Set(xpos, ypos);

		return *this;
	}

	PString& PString::SetString(string str)
	{
		(this->str) = str;

		return *this;
	}

	PString& PString::SetColor(PColor color)
	{
		(this->color) = color;

		return *this;
	}

	PString& PString::SetSpoint(Point spoint)
	{
		(this->spoint) = spoint;

		return *this;
	}

	PString& PString::SetSpoint(int xpos, int ypos)
	{
		(this->spoint).Set(xpos, ypos);

		return *this;
	}

	PString& PString::SetSxpos(int xpos)
	{
		(this->spoint).SetXpos(xpos);

		return *this;
	}

	PString& PString::SetSypos(int ypos)
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
