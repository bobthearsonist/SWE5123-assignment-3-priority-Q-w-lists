// NONMEMBER FUNCTION IMPLEMENTATIONS

#include "pqqueue.h"

template <typename T>
std::ostream& operator<<(std::ostream& out, const pqqueue<T>& pq)
{
	// output the queue showing values and priority

	for (NodeIterator<T> cursor(pq.priority.get_head()); cursor != NULL; cursor++)
	{
		out << (*cursor)->data() << endl;
	}

	return out;

}

