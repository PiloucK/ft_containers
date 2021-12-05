/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctor_container.pass.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:58:14 by ecaceres          #+#    #+#             */
/*   Updated: 2021/12/02 18:02:39 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unit_stack.hpp>
#include "myUnitTest.hpp"

template<class C>
	C
	make(int n)
	{
		C c;
		for (int i = 0; i < n; ++i)
			c.push_back(i);

		return (c);
	}

TEST_CASE({
	{
		VECTOR<int> vector = make<VECTOR<int> >(5);
		STACK<int, VECTOR<int> > stack(vector);

		ASSERT(stack.size() == 5);
		for (std::size_t i = 0; i < vector.size(); ++i)
		{
			ASSERT(stack.top() == vector[vector.size() - i - 1]);
			stack.pop();
		}
	}

	ASSERT_AWARE_ZERO();
}
