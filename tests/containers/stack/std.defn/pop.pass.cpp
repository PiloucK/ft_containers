/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.pass.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:28:31 by ecaceres          #+#    #+#             */
/*   Updated: 2021/12/03 10:20:47 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unit_stack.hpp>

TEST_CASE({
	{
		STACK<Aware<int> > stack;

		ASSERT(stack.size() == 0);

		stack.push(1);
		stack.push(2);
		stack.push(3);
		ASSERT(stack.size() == 3);
		ASSERT(stack.top() == 3);

		stack.pop();
		ASSERT(stack.size() == 2);
		ASSERT(stack.top() == 2);

		stack.pop();
		ASSERT(stack.size() == 1);
		ASSERT(stack.top() == 1);

		stack.pop();
		ASSERT(stack.size() == 0);
	}
}
