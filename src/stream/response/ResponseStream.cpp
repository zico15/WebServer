/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ResponseStream.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:51:47 by edos-san          #+#    #+#             */
/*   Updated: 2022/08/18 00:34:08 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ResponseStream.hpp"

ResponseStream::ResponseStream()
{
    
}
ResponseStream::ResponseStream(BaseStream *request): _request(request)
{
    File file(request->_out->getKey("File"));
    std::stringstream a;
    std::string body = file.read();
    a << "HTTP/1.1 200 OK\r\n";
    a << "Content-Type: text/html\r\n";
    a << "Content-Length: " << body.size() << "\r\n";
    a << "Server: WebServer\r\n";
    a << "Connection: Keep-Alive\r\n\r\n";
    a << body << "\r\n";
    _file = a.str();
    _size = _file.size();
    _socket = request->_socket;
    _id = request->_id;
    _fd = _socket->fd;
}

ResponseStream::~ResponseStream()
{
	if (_request)
		delete _request;
}

BaseStream *ResponseStream::run(void)
{
    std::cout << "ResponseStream: " << _fd;
    std::cout << " id: " << _id << "\n";
    send(_socket->fd, _file.c_str(), _size, 0);
	_socket->events = POLLIN;
	return (NULL);
}