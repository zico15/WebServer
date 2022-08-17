/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 21:36:54 by edos-san          #+#    #+#             */
/*   Updated: 2022/08/17 00:05:43 by edos-san         ###   ########.fr       */
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
        _socket->socketListen();
        for (int i = 0; i < _socket->getMaxClient(); i++)
    	{
    		if(_socket->getEvent(i)->revents == 0)
    			continue;
			if (_socket->getEvent(i)->fd == _socket->getFd())
				createClient();
            else if (_socket->getEvent(i)->client.isOnline())
            {
                //int f = _socket->getEvent(i)->client._fd;
               // std::cout << "Run Client: " << std::to_string(f) << "\n";
                _socket->getEvent(i)->client.run();
            }
		}
        /*for(int i = 0; i < actions.size(); i++)
            actions[i]->run();*/
    }
    catch(const std::exception& e)
    {
        std::cout << "error: " << e.what() << '\n';
    }   
}

void Server::createClient()
{
    int fd = _socket->socketAccept();
    if (fd < 0)
        return ;
    Client *client = _socket->createClient(fd);
    std::cout << "Create Client: " << std::to_string(fd) << "\n";
}

void Server::runClient(int fd)
{
    try
    {
        //std::cout << "runClient: " <<  _clients[fd]->_fd << "\n" ;
      
        //actions.push_back(_clients[fd]);
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