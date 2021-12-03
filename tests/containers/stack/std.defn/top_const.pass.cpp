/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_const.pass.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:47:21 by ecaceres          #+#    #+#             */
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
		const STACK<Aware<int> >& cstack = stack;
		const Aware<int> &ctop = cstack.top();
		ASSERT(ctop == 3);
	}
}
