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
            {
                std::cout << "createClient: " <<  i << "\n" ;
				createClient();
            }
            else if (1)
            {
                std::cout << "runClient: " <<  i << "\n";
                for(size_t i = 0; i < actions.size(); i++)
                    actions[i]->run();
                //int f = _socket->getEvent(i)->client._fd;
               // std::cout << "Run Client: " << std::to_string(f) << "\n";
            }
		}

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
    Client *c = _socket->createClient(fd);
    if (c)
        actions.push_back(c);
}

void Server::runClient(int fd)
{
    try
    {
        (void) fd;
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