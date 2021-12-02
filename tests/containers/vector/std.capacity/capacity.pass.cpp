/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capacity.pass.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 17:35:33 by ecaceres          #+#    #+#             */
/*   Updated: 2021/12/02 18:02:39 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myUnitTest.hpp"

TEST_CASE({
	TEST_AWARE_BLOCK({
		VECTOR<Aware<int> > v;

		ASSERT(v.capacity() == 0);
	});

	TEST_AWARE_BLOCK({
		VECTOR<Aware<int> > v(100);

		ASSERT(v.capacity() == 100);

		v.push_back(0);
		ASSERT(v.capacity() > 101);
	});

	})
