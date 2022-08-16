/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:37:00 by ezequeil          #+#    #+#             */
/*   Updated: 2022/08/16 14:51:17 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
#define SERVER_HPP

#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>

#include "../socket/Socket.hpp"
#include  "../client/Client.hpp"

class Server {

	private:
		Socket 								*_socket;
		std::unordered_map<int, Client*>	_clients;
		std::vector<Client*>					actions;
	public:
		Server();
		Server(std::string name, int port, int maxClient);
		~Server();
		void	listen();
		void	createClient();
		void	runClient(int fd);
	
};


#endif
