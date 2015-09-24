#include <iostream>
#include <string>
#include <cstdio>
#include "pongstring.h"

using std::string;
using pong::Point;

namespace pong
{
	PString::PString(string str, int color, Point spoint)
		: str(str), color(color), spoint(spoint)
	{
		// empty
	}

	PString::PString(string str, int color, int xpos, int ypos)
		: str(str), color(color), spoint(xpos, ypos)
	{
		// empty
	}

	PString::PString(string str, Point spoint)
		: str(str), spoint(spoint)
	{
		color = PColor::DEFAULT;
	}

	PString::PString(string str, int xpos, int ypos)
		: str(str), spoint(xpos, ypos)
	{
		color = PColor::DEFAULT;
	}

	PString& PString::Set(string str, int color, Point spoint)
	{
		(this->str) = str;
		(this->color) = color;
		(this->spoint) = spoint;
	}

	PString& PString::Set(string str, int color, int xpos, int ypos)
	{
		(this->str) = str;
		(this->color) = color;
		(this->spoint).Set(xpos, ypos);
	}

	PString& PString::SetString(string str)
	{
		(this->str) = str;
	}

	PString& PString::SetColor(int color)
	{
		(this->color) = color;
	}

	PString& PString::SetSpoint(Point spoint)
	{
		(this->spoint) = spoint;
	}

	PString& PString::SetSpoint(int xpos, int ypos)
	{
		(this->spoint).Set(xpos, ypos);
	}

	PString& PString::SetSxpos(int xpos)
	{
		(this->spoint).SetXpos(xpos);
	}

	PString& PString::SetSypos(int ypos)
	{
		(this->spoint).SetYpos(ypos);
	}

	string PString::GetString(void) const
	{
		return str;
	}

	int PString::GetColor(void) const
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
