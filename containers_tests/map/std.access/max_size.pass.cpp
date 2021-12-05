/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_size.pass.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 14:37:11 by ecaceres          #+#    #+#             */
/*   Updated: 2021/12/02 17:59:19 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unit_map.hpp>
#include <limits>

TEST_CASE({
	{
		typedef MAP<char, int> C;
		const C::size_type max_dist = static_cast<C::size_type>(std::numeric_limits<C::difference_type>::max());
		C c;

		ASSERT(c.max_size() <= max_dist);
	}
}
