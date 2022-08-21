/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 22:40:38 by edos-san          #+#    #+#             */
/*   Updated: 2022/08/18 00:36:45 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"

Client::Client()
{
    _response = NULL;
    _request  = NULL;
    _socket = NULL;
}

Client::Client(t_socket *socket): _socket(socket)
{
    _response = NULL;
    _request  = NULL;
}

Client::~Client() 
{
    if (_response)
        delete _response;
    if (_request)
        delete _response;
}



bool Client::run()
{
    if (_socket->revents == POLLIN)
    {
        RequestStream *reuest = new RequestStream(_socket);

        _response = reuest->run();
    }
    else if (_response && _socket->revents == POLLOUT)
    {
         _response->run();
         delete _response;
         _response = NULL;
    }
    else
    {
        std::cout << "CLOSE EVENT\n";
        return (false);
    }
    return (true);
}