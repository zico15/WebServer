/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:37:00 by ezequeil          #+#    #+#             */
/*   Updated: 2022/08/16 02:31:08 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
#define SERVER_HPP

#include <string>
#include <iostream>

#include "../socket/Socket.hpp"
#include  "../client/Client.hpp"
#include	"Array.hpp"

class Server {

	private:
		Socket 			*_socket;
		Array<Client>	_clients;
	public:
		Server(std::string name, int port);
		Server(std::string name, int port, int maxClient);
		~Server();
		void listen(void);
	
};


#endif
