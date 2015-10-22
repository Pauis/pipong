#include "pongtrigger.h"

namespace pong
{
	PGTrigger::PGTrigger(int triggernum)
		: triggernum(triggernum)
	{
		// empty
	}

	PGTrigger& PGTrigger::Set(int triggernum)
	{
		(this->triggernum) = triggernum;

		return *this;
	}

	bool operator==(PGTrigger t1, PGTrigger t2)
	{
		if (t1.triggernum == t2.triggernum)
			return true;
		else
			return false;
	}

	bool operator!=(PGTrigger t1, PGTrigger t2)
	{
		if (t1.triggernum != t2.triggernum)
			return true;
		else
			return false;
	}
}
