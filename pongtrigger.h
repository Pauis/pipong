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
		PGTrigger(int triggernum);
		PGTrigger& Set(int triggernum);
		friend bool operator==(PGTrigger t1, PGTrigger t2);
		friend bool operator!=(PGTrigger t1, PGTrigger t2);
	};
	bool operator==(PGTrigger t1, PGTrigger t2);
	bool operator!=(PGTrigger t1, PGTrigger t2);
}

#endif
