/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:30:52 by ezequeil          #+#    #+#             */
/*   Updated: 2022/08/18 00:37:28 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/server/Server.hpp"
#include "src/util/File.hpp"
# include "src/stream/object/ObjectStream.hpp"

void update(void)
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
	/*std::string value;
	std::string str = "Host: localhost:1500\nDNT: 1\nReferer: http://localhost:1500/\nSec-Fetch-Dest: style";
	ObjectStream os(str);
	
	std::cout << "\nvalue: " << os.getKey("Host") << "\nexit\n";*/
	return (0);
}
