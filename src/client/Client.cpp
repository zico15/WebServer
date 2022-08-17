/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 22:40:38 by edos-san          #+#    #+#             */
/*   Updated: 2022/08/17 00:11:15 by edos-san         ###   ########.fr       */
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

Client::~Client() 
{
    if (_response)
        delete _response;
    if (_request)
        delete _request;
    _event->fd = -1;
    _event->events = 0;
}

void Client::init(event	*event, int fd)
{
    _is_online = true;
    _response = NULL;
    _request = NULL;
    event = event;
    event->fd = fd;
    event->events = POLLIN;
    _event = event;
    _fd = fd;
}

void Client::listen()
{
   
}

bool Client::isOnline()
{
    return (_is_online);
}

void Client::run()
{
    if (_event == NULL)
        return ;
   static int i = 0;
   std::cout << "(" << std::to_string(i) << ") Client: " << _fd << " ";
   if ( _event->events == POLLIN)
   {
        while (recv(_fd, _buffer, 1024, __THROW) > 0 && *_buffer != '*')
            std::cout << _buffer << " ";
        _buffer[0] = 0;
        std::cout << "POLLIN" << std::endl;
        _event->events = POLLOUT;
   }
   else if (_event->events == POLLOUT)
   {
        File file("public/index.html");
        std::string a;
        std::string body = file.read();
        a = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: ";
        a += std::to_string(body.size()) + "\r\nServer: WebServer\r\nConnection: Keep-Alive\r\n\r\n";
        a += body;
        send(_fd, a.c_str(), a.size(), 0);
        std::cout << "POLLOUT" << std::endl;
        _event->events = POLLIN;
   }
}