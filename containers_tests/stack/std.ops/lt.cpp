/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lt.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:16:50 by ecaceres          #+#    #+#             */
/*   Updated: 2021/12/02 17:59:19 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unit_stack.hpp>

template<class C>
	C
	make(int n)
	{
		C c;

		for (int i = 0; i < n; ++i)
			c.push(i);

		return (c);
	}

TEST_CASE({
	STACK<int> q1 = make<STACK<int> >(5);
	STACK<int> q2 = make<STACK<int> >(10);

    ASSERT(q1 < q2);
    ASSERT(q2 > q1);
    ASSERT(q1 <= q2);
    ASSERT(q2 >= q1);
}
