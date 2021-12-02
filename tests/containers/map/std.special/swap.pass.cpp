/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.pass.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 20:31:46 by ecaceres          #+#    #+#             */
/*   Updated: 2021/12/02 17:59:19 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unit_map.hpp>

TEST_CASE({
	typedef PAIR<const Aware<int>, Aware<double> > V;
	typedef MAP<Aware<int>, Aware<double> > M;

	{
		M m1;
		M m2;
		M m1_save = m1;
		M m2_save = m2;

		m1.swap(m2);
		ASSERT(m1 == m2_save);
		ASSERT(m2 == m1_save);
	}

	{
		V ar2[] = {
			V(5, 5),
			V(6, 6),
			V(7, 7),
			V(8, 8),
			V(9, 9),
			V(10, 10),
			V(11, 11),
			V(12, 12) };

		M m1;
		M m2(ar2, ar2 + sizeof(ar2) / sizeof(ar2[0]));
		M m1_save = m1;
		M m2_save = m2;

		m1.swap(m2);
		ASSERT(m1 == m2_save);
		ASSERT(m2 == m1_save);
	}

	{
		V ar1[] = {
			V(1, 1),
			V(2, 2),
			V(3, 3),
			V(4, 4) };

		M m1(ar1, ar1 + sizeof(ar1) / sizeof(ar1[0]));

		M m2;
		M m1_save = m1;
		M m2_save = m2;

		m1.swap(m2);
		ASSERT(m1 == m2_save);
		ASSERT(m2 == m1_save);
	}

	{
		V ar1[] = {
			V(1, 1),
			V(2, 2),
			V(3, 3),
			V(4, 4) };

		V ar2[] = {
			V(5, 5),
			V(6, 6),
			V(7, 7),
			V(8, 8),
			V(9, 9),
			V(10, 10),
			V(11, 11),
			V(12, 12) };

		M m1(ar1, ar1 + sizeof(ar1) / sizeof(ar1[0]));
		M m2(ar2, ar2 + sizeof(ar2) / sizeof(ar2[0]));
		M m1_save = m1;
		M m2_save = m2;

		m1.swap(m2);
		ASSERT(m1 == m2_save);
		ASSERT(m2 == m1_save);
	}

	return 0;
}
