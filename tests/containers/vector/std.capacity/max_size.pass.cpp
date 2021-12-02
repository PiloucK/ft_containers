/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_size.pass.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 17:12:35 by ecaceres          #+#    #+#             */
/*   Updated: 2021/12/02 18:02:39 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits>
#include "myUnitTest.hpp"

template<typename T>
	bool
	test()
	{
		typedef VECTOR<T> C;
		typename C::size_type max = static_cast<typename C::size_type>(std::numeric_limits<typename C::size_type>::max() / sizeof(typename C::value_type));

		C c;
		return (c.max_size() <= max);
	}

TEST_CASE({
	ASSERT(test<char>());
	ASSERT(test<short>());
	ASSERT(test<int>());
	ASSERT(test<float>());
	ASSERT(test<double>());
	ASSERT(test<long>());
	ASSERT(test<long long>());
	ASSERT(test<Aware<int> >());
	ASSERT(test<std::string>());
	ASSERT(test<VECTOR<long> >());

	})
