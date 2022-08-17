/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:30:52 by ezequeil          #+#    #+#             */
/*   Updated: 2022/08/16 23:45:31 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/server/Server.hpp"
#include "src/util/File.hpp"

static void update(void)
{
	Server s("localhost", 1501, 200);
	while (1)
	{
		s.listen();
	}
}

int main(void)
{
	update();
	std::cout << "\nexit\n";
	return (0);
}
