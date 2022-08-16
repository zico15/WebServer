/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 21:36:54 by edos-san          #+#    #+#             */
/*   Updated: 2022/08/16 14:53:00 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

Server::Server(){}

Server::Server(std::string name, int port, int maxClient): _clients(maxClient)
{

    _socket = new Socket(name, port, maxClient);
    std::cout << "Server has been created: " << port;
    std::cout << " MaxClient: " << _socket->getMaxClient() << std::endl;
}

void Server::listen()
{
    try
    {
        _socket->socketListen();
        for (int i = 0; i < _socket->getMaxClient(); i++)
    	{
    		if(_socket->getEvent(i)->revents == 0)
    			continue;
			if (_socket->getEvent(i)->fd == _socket->getFd())
				createClient();
            else
                runClient(_socket->getEvent(i)->fd);
		}
        for(int i = 0; i < actions.size(); i++)
            actions[i]->run();
    }
    catch(const std::exception& e)
    {
        std::cout << "error: " << e.what() << '\n';
    }         
}

void Server::createClient()
{
     _clients[0] = new Client();
}

void Server::runClient(int fd)
{
    try
    {
        actions.push_back(_clients[fd]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

Server::~Server()
{
    std::cout << "~Server\n";
    delete _socket;
}