/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty.pass.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 17:12:35 by ecaceres          #+#    #+#             */
/*   Updated: 2021/12/02 18:02:39 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myUnitTest.hpp"

TEST_CASE({
	TEST_AWARE_BLOCK({
		typedef VECTOR<Aware<int> > C;
		C c;

		ASSERT_NOEXCEPT(c.empty());

		ASSERT(c.empty());

		c.push_back(C::value_type(1));
		ASSERT(!c.empty());

		c.clear();
		ASSERT(c.empty());
	});

	})
