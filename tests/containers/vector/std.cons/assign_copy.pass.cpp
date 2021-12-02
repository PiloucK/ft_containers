/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_copy.pass.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 18:20:42 by ecaceres          #+#    #+#             */
/*   Updated: 2021/12/02 18:02:39 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myUnitTest.hpp"

TEST_CASE({
	TEST_AWARE_BLOCK({
		VECTOR<Aware<int> > l(3, Aware<int>(2));
		VECTOR<Aware<int> > l2(l);

		l2 = l;

		ASSERT(l2 == l);
	});

	TEST_AWARE_BLOCK({
		VECTOR<Aware<int> > l(3, Aware<int>(2));
		VECTOR<Aware<int> > l2(l);

		l2 = l;

		ASSERT(l2 == l);
	});

	})
