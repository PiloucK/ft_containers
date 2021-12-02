/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.pass.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 17:35:33 by ecaceres          #+#    #+#             */
/*   Updated: 2021/12/02 18:02:39 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myUnitTest.hpp"

TEST_CASE({
	{
		VECTOR<int> foo(3, 100);
		VECTOR<int> bar(2, 200);

		ASSERT((foo == bar) == false);
		ASSERT((foo != bar) == true);
		ASSERT((foo < bar) == true);
		ASSERT((foo > bar) == false);
		ASSERT((foo <= bar) == true);
		ASSERT((foo >= bar) == false);
	};

	})
