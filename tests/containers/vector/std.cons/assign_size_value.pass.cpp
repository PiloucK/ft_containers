/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_size_value.pass.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 18:20:42 by ecaceres          #+#    #+#             */
/*   Updated: 2021/12/02 18:02:39 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myUnitTest.hpp"

bool
is6(const Aware<int> &x)
{
	return (x == Aware<int>(6));
}

void
test(VECTOR<Aware<int> > &v)
{
	v.assign(5, Aware<int>(6));
	ASSERT(v.size() == 5);

	for (VECTOR<Aware<int> >::iterator it = v.begin(); it < v.end(); it++)
	{
		ASSERT(is6(*it));
	}
}

TEST_CASE({
	TEST_AWARE_BLOCK({
		typedef VECTOR<Aware<int> > V;
		V d1;
		V d2;

		d2.reserve(10);

		test(d1);
		test(d2);
	});

	})
