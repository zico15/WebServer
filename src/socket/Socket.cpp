/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 21:59:02 by edos-san          #+#    #+#             */
/*   Updated: 2022/08/16 13:12:37 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Socket.hpp"

Socket::Socket(){}

Socket::Socket(std::string name,int port, int maxClient): _name(name), _port(port), _maxClient(maxClient)
{
	int on = 1;
	_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (_fd < 0) 
	{
		std::cout << "Error establishing socket..." << std::endl;
		exit(1);
	}
	_ic = setsockopt(_fd, SOL_SOCKET,  SO_REUSEADDR, (char *)&_addr, sizeof(on));
  	_ic = ioctl(_fd, FIONBIO, (char *)&on);
  	if (_ic < 0)
  	{
  	  perror("ioctl() failed");
  	  close(_fd);
  	  exit(-1);
  	}
	_addr.sin_family = AF_INET;
	_addr.sin_addr.s_addr = htons(INADDR_ANY);
	_addr.sin_port = htons(port);
	if ((bind(_fd, (struct sockaddr*)&_addr,sizeof(_addr))) < 0) 
	{
		std::cout << "=> Error binding connection, the socket has already been established..." << std::endl;
		return ;
	}
	_size = sizeof(_addr);
	listen(_fd, 1);
	_fds[0].fd = _fd;
  	_fds[0].events = POLLIN;
}

Socket::~Socket()
{
	std::cout << "~Socket\n";
}

int Socket::socketListen(void)
{
	return (poll(_fds, 1, TIME_OUT));
}

int		Socket::getMaxClient()
{
	return (_maxClient);
}

int		Socket::getFd()
{
	return (_fd);
}
	
event	*Socket::getEvent(int i)
{
	return (&_fds[i]);
}