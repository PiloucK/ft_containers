#include "myUnitTest.hpp"

template<class C, class Iterator>
	void
	test(Iterator first, Iterator last, std::stringstream & output_string, int & test_passed, int & test_failed)
	{
		C c(first, last);
		ASSERT(c.size() == static_cast<std::size_t>(NAMESPACE::distance(first, last)));

		for (typename C::const_iterator i = c.begin(), e = c.end(); i != e; ++i, ++first)
			ASSERT(*i == *first);
	}

static void
basic_test_cases(std::stringstream & output_string, int & test_passed, int & test_failed)
{
	Aware<int> a[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 1, 0 };
	Aware<int> *an = a + sizeof(a) / sizeof(a[0]);

	test<VECTOR<Aware<int> > >(SimpleIterator<const Aware<int>*>(a), SimpleIterator<const Aware<int>*>(an), output_string, test_passed, test_failed);

#if !(USING_STD)
	test<VECTOR<Aware<int> > >(VECTOR<Aware<int> >::iterator(a), VECTOR<Aware<int> >::iterator(an), output_string, test_passed, test_failed);
	test<VECTOR<Aware<int> > >(VECTOR<Aware<int> >::const_iterator(a), VECTOR<Aware<int> >::const_iterator(an), output_string, test_passed, test_failed);
#endif
	test<VECTOR<Aware<int> > >(a, an, output_string, test_passed, test_failed);
}

struct B1
{
		int x;
};

struct B2
{
		int y;
};

struct Der :
		B1,
		B2
{
		int z;
};

void
test_ctor_with_different_value_type(std::stringstream & output_string, int & test_passed, int & test_failed) // Initialize a vector with a different value type.
{
	float array[3] = { 0.0f, 1.0f, 2.0f };

	{ // Make sure initialization is performed with each element value, not with a memory blob.
		VECTOR<int> v(array, array + 3);
		ASSERT(v[0] == 0);
		ASSERT(v[1] == 1);
		ASSERT(v[2] == 2);
	}

	{ // Though the types Der* and B2* are very similar, initialization still cannot be done with `memcpy`.
		Der z;
		Der *array[1] = { &z };

		VECTOR<B2*> v(array, array + 1);
		ASSERT(v[0] == &z);
	}

	{ // Though the types are different, initialization can be done with `memcpy`.
		int32_t array[1] = { -1 };
		VECTOR<unsigned int> v(array, array + 1);
		ASSERT(v[0] == 4294967295);
	}
}

TEST_CASE(Vector, Constructor, FromIteratorOrDifferentValueType, {
	basic_test_cases(output_string, test_passed, test_failed);
	ASSERT_AWARENESS

	test_ctor_with_different_value_type(output_string, test_passed, test_failed);
	ASSERT_AWARENESS
})
