/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 21:36:54 by edos-san          #+#    #+#             */
/*   Updated: 2022/08/16 02:37:49 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

Server::Server(std::string name, int port){
    Server(name, port, 200);
}

Server::Server(std::string name, int port, int maxClient): _clients(maxClient)
{

    _socket = new Socket(name, port, maxClient);
    std::cout << "Server has been created: " << port;
    std::cout << " MaxClient: " << _socket->getMaxClient() << std::endl;
    for (size_t i = 0; i < maxClient; i++)
        _clients[i].init(i);
    _socket->socketListen();
}

void Server::listen()
{

}

Server::~Server()
{
    std::cout << "asdasda";
    delete _socket;
}