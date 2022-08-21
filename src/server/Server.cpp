/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 21:36:54 by edos-san          #+#    #+#             */
/*   Updated: 2022/08/17 22:40:55 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

Server::Server(){}

Server::Server(std::string name, int port, int maxClient)
{
    _socket = new Socket(name, port, maxClient);
    std::cout << "Server has been created: " << port;
    std::cout << " MaxClient: " << _socket->getMaxClient() << std::endl;
}

void Server::listen()
{
    try
    {
        int s = _socket->socketListen();
        if(s <= 0)
            return ;
        for (int i = 0; i < _socket->getMaxClient(); i++)
    	{
    		if(_socket->getEvent(i)->revents == 0)
    			continue;
			else if (_socket->getEvent(i)->fd == _socket->getFd())
				_socket->createClient();
            else
                _socket->runClient(i);
		}
    }
    catch(const std::exception& e)
    {
        std::cout << "error: " << e.what() << '\n';
    }   
}

Server::~Server()
{
    std::cout << "~Server\n";
    delete _socket;
}