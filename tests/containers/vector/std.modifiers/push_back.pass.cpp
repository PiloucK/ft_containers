/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.pass.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 14:03:25 by ecaceres          #+#    #+#             */
/*   Updated: 2021/12/02 18:02:39 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myUnitTest.hpp"

TEST_CASE({
	TEST_AWARE_BLOCK({
		VECTOR<int> c;

		c.push_back(0);
		ASSERT(c.size() == 1);

		for (int j = 0; static_cast<std::size_t>(j) < c.size(); ++j)
			ASSERT(c[j] == j);

		c.push_back(1);
		ASSERT(c.size() == 2);

		for (int j = 0; static_cast<std::size_t>(j) < c.size(); ++j)
			ASSERT(c[j] == j);

		c.push_back(2);
		ASSERT(c.size() == 3);

		for (int j = 0; static_cast<std::size_t>(j) < c.size(); ++j)
			ASSERT(c[j] == j);

		c.push_back(3);
		ASSERT(c.size() == 4);

		for (int j = 0; static_cast<std::size_t>(j) < c.size(); ++j)
			ASSERT(c[j] == j);

		c.push_back(4);
		ASSERT(c.size() == 5);

		for (int j = 0; static_cast<std::size_t>(j) < c.size(); ++j)
			ASSERT(c[j] == j);
	});

	})
