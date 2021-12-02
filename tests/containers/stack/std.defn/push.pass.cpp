/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.pass.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:28:31 by ecaceres          #+#    #+#             */
/*   Updated: 2021/12/02 17:59:19 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unit_stack.hpp>

TEST_CASE({
	TEST_AWARE_BLOCK({
		STACK<Aware<int> > q;

		q.push(1);
		ASSERT(q.size() == 1);
		ASSERT(q.top() == 1);

		q.push(2);
		ASSERT(q.size() == 2);
		ASSERT(q.top() == 2);

		q.push(3);
		ASSERT(q.size() == 3);
		ASSERT(q.top() == 3);
	});
}
