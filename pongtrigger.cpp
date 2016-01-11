#include "pongtrigger.h"

namespace pong {
	PGTrigger::PGTrigger(const int& triggernum)
		: triggernum(triggernum) {
		// empty
	}

	PGTrigger& PGTrigger::Set(const int& triggernum) {
		(this->triggernum) = triggernum;

		return *this;
	}

	bool operator==(const PGTrigger& t1, const PGTrigger& t2) {
		if (t1.triggernum == t2.triggernum) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator!=(const PGTrigger& t1, const PGTrigger& t2) {
		if (t1.triggernum != t2.triggernum) {
			return true;
		}
		else {
			return false;
		}
	}
}
