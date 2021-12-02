/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reserve.pass.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 17:30:20 by ecaceres          #+#    #+#             */
/*   Updated: 2021/12/02 18:02:39 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myUnitTest.hpp"

TEST_CASE({
	TEST_AWARE_BLOCK({
		VECTOR<int> v;

		v.reserve(10);
		ASSERT(v.capacity() >= 10);
	});

	TEST_AWARE_BLOCK({
		VECTOR<int> v(100);

		ASSERT(v.capacity() == 100);

		v.reserve(50);
		ASSERT(v.size() == 100);
		ASSERT(v.capacity() == 100);

		v.reserve(150);
		ASSERT(v.size() == 100);
		ASSERT(v.capacity() == 150);
	});

	})
