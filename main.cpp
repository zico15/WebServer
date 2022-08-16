/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:30:52 by ezequeil          #+#    #+#             */
/*   Updated: 2022/08/16 13:31:20 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/server/Server.hpp"


static void update(void)
{
	Server s("localhost", 1500, 200);
	while (1)
	{
		s.listen();
	}
}

int main(void)
{
	update();
	std::cout << "exit\n";
	return (0);
}
