#ifndef __PONGTRIGGER_H__
#define __PONGTRIGGER_H__

namespace pong
{
	class PGTrigger
	{
	private:
		int triggernum;
	public:
		enum
		{
			NONE,
			LOBBY,
			INGAME,
		};
		PGTrigger(const int& triggernum);
		PGTrigger& Set(const int& triggernum);
		friend bool operator==(const PGTrigger& t1, const PGTrigger& t2);
		friend bool operator!=(const PGTrigger& t1, const PGTrigger& t2);
	};
	bool operator==(const PGTrigger& t1, const PGTrigger& t2);
	bool operator!=(const PGTrigger& t1, const PGTrigger& t2);
}

#endif
