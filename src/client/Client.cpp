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
    _is_online = false;
    _response = NULL;
    _request = NULL;
    _event = NULL;
}

Client::Client(t_event *event)
{
    _is_online = true;
    _response = NULL;
    _request = NULL;
    _event = event;
}

Client::~Client() 
{
    if (_response)
        delete _response;
    if (_request)
        delete _request;
    _event->fd = -1;
    _event->events = 0;
}


void Client::listen()
{
   
}

bool Client::isOnline()
{
    return (_is_online);
}

int Client::getFd()
{
    if (_event)
        return (_event->fd);
    return (-1);
}

void Client::run()
{

   if ( _event->revents == POLLIN)
   {
        _request = new RequestStream(_event);
        _response = _request->run();
        std::cout << "request ok\n";
   }
   else if (_event->revents == POLLOUT && _response)
   {
        std::cout << "response init\n";
        _response->run();
        delete _response;
        _response = NULL;
        std::cout << "response ok\n";
   }
}