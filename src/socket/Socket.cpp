/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 21:59:02 by edos-san          #+#    #+#             */
/*   Updated: 2022/08/16 02:39:50 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Socket.hpp"


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
	
}

void Socket::socketListen(void)
{
	int    timeout, ic;
  	timeout = (3 * 60 * 1000);

	while (1)
	{
		ic = poll(_fds, 1, timeout);
		if (ic <= 0)
			return ;
		for (int i = 0; i < _maxClient; i++)
    	{
    		if(_fds[i].revents == 0)
    			continue;
			std::cout << "socket: " << _fd << " poll: " << ic << "\n";
			if (_fds[i].fd == _fd)
				
			_fds[i].fd = 0;
		}
	}
}
	
  