#ifndef __PONGPROPERTIES_H__
#define __PONGPROPERTIES_H__

namespace pong
{
	class PGProperty
	{
	public:
		enum
		{
			PBALLFREQ   = 4,
			PCYCLEDELAY = 40,
		};
	};

	class PKProperty
	{
	public:
		enum
		{
			PSTART = 's',
			PEXIT = 'q',
			PP1UP = 'e',
			PP1DOWN = 'f',
			PP2UP = 'o',
			PP2DOWN = 'k',
		};
	};
}

#endif
