/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_size_value.pass.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 18:20:42 by ecaceres          #+#    #+#             */
/*   Updated: 2021/12/02 18:02:39 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myUnitTest.hpp"

template<class C>
	void
	test(typename C::size_type n, const typename C::value_type &x)
	{
		C c(n, x);
		ASSERT(c.size() == n);

		for (typename C::const_iterator i = c.begin(), e = c.end(); i != e; ++i)
			ASSERT(*i == x);
	}

TEST_CASE({
	test<VECTOR<int> >(50, 3);
	test<VECTOR<Aware<int> > >(50, 5);

	ASSERT_AWARE_ZERO();

	})
