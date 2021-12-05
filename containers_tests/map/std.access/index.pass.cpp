/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.pass.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 19:45:09 by ecaceres          #+#    #+#             */
/*   Updated: 2021/12/02 17:59:19 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unit_map.hpp>

TEST_CASE({
	{
		typedef PAIR<const int, double> V;
		V ar[] = {
			V(1, 1.5),
			V(2, 2.5),
			V(3, 3.5),
			V(4, 4.5),
			V(5, 5.5),
			V(7, 7.5),
			V(8, 8.5), };

		MAP<int, double> m(ar, ar + sizeof(ar) / sizeof(ar[0]));

		ASSERT(m.size() == 7);
		ASSERT(m[1] == 1.5);
		ASSERT(m.size() == 7);

		m[1] = -1.5;
		ASSERT(m[1] == -1.5);
		ASSERT(m.size() == 7);
		ASSERT(m[6] == 0);
		ASSERT(m.size() == 8);

		m[6] = 6.5;
		ASSERT(m[6] == 6.5);
		ASSERT(m.size() == 8);
	}

	ASSERT_AWARE_ZERO();
}
