#include "myUnitTest.hpp"

TEST_CASE(Map, Access, Iterators, {
	{
		typedef PAIR<const int COMMA Aware<double> > V;
		V ar[] = {
			V(1, 1) COMMA
			V(1, 1.5) COMMA
			V(1, 2) COMMA
			V(2, 1) COMMA
			V(2, 1.5) COMMA
			V(2, 2) COMMA
			V(4, 1) COMMA
			V(4, 1.5) COMMA
			V(4, 2) COMMA
			V(3, 1) COMMA
			V(3, 1.5) COMMA
			V(3, 2) COMMA
			V(5, 1) COMMA
			V(5, 1.5) COMMA
			V(5, 2) COMMA
			V(6, 1) COMMA
			V(6, 1.5) COMMA
			V(6, 2) COMMA
			V(7, 1) COMMA
			V(7, 1.5) COMMA
			V(7, 2) COMMA
			V(8, 1) COMMA
			V(8, 1.5) COMMA
			V(8, 2) };

		MAP<int COMMA Aware<double> > m(ar, ar + sizeof(ar) / sizeof(ar[0]));
		ASSERT(static_cast<std::size_t>(NAMESPACE::distance(m.begin(), m.end())) == m.size());
		ASSERT(static_cast<std::size_t>(NAMESPACE::distance(m.rbegin(), m.rend())) == m.size());
		MAP<int COMMA Aware<double> >::iterator i;
		i = m.begin();
		MAP<int COMMA Aware<double> >::const_iterator k = i;
		ASSERT(i == k);
		for (int j = 1; static_cast<std::size_t>(j) <= m.size(); ++j, ++i)
		{
			ASSERT(i->first == j);
			ASSERT(i->second == 1);
			i->second = 2.5;
			ASSERT(i->second == 2.5);
		}
	} ASSERT_AWARENESS

	{
		typedef PAIR<const int COMMA Aware<double> > V;
		V ar[] = {
			V(1, 1) COMMA
			V(1, 1.5) COMMA
			V(1, 2) COMMA
			V(2, 1) COMMA
			V(2, 1.5) COMMA
			V(2, 2) COMMA
			V(3, 1) COMMA
			V(3, 1.5) COMMA
			V(3, 2) COMMA
			V(4, 1) COMMA
			V(4, 1.5) COMMA
			V(4, 2) COMMA
			V(5, 1) COMMA
			V(5, 1.5) COMMA
			V(5, 2) COMMA
			V(6, 1) COMMA
			V(6, 1.5) COMMA
			V(6, 2) COMMA
			V(7, 1) COMMA
			V(7, 1.5) COMMA
			V(7, 2) COMMA
			V(8, 1) COMMA
			V(8, 1.5) COMMA
			V(8, 2) };

		const MAP<int COMMA Aware<double> > m(ar, ar + sizeof(ar) / sizeof(ar[0]));

		ASSERT(static_cast<std::size_t>(NAMESPACE::distance(m.begin(), m.end())) == m.size());
		ASSERT(static_cast<std::size_t>(NAMESPACE::distance(m.rbegin(), m.rend())) == m.size());

		MAP<int COMMA Aware<double> >::const_iterator i;
		i = m.begin();
		for (int j = 1; static_cast<std::size_t>(j) <= m.size(); ++j, ++i)
		{
			ASSERT(i->first == j);
			ASSERT(i->second == 1);
		}
	} ASSERT_AWARENESS
})
