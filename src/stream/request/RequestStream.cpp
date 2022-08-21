/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RequestStream.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:47:58 by edos-san          #+#    #+#             */
/*   Updated: 2022/08/17 23:46:55 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RequestStream.hpp"

std::string replace(std::string str, char c, char j)
{
	std::stringstream os;

	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] != c)
			os << str[i];
		else if (j)
			os << j;
	}
	return (os.str());
}

RequestStream::RequestStream(t_socket *event)
{
	static int id = 100;
	std::string str;
	_fd = event->fd;
	_socket = event;
	size_t size;

	_id = id++;
	while ((size =   recv(_fd, _buffer, 1024, 0)) > 0)
	{
		str += _buffer;
		if (size != 1024)
			break ;
	}
	_out = new  ObjectStream(str);
	event->events = POLLOUT;
}

RequestStream::~RequestStream()
{
	if (_out)
		delete _out;
}

BaseStream *RequestStream::run(void)
{
	std::cout << "RequestStream: " << _fd;
	std::cout << " id: " << _id << "\n";
	return (new ResponseStream(this));
}