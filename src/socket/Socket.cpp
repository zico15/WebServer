/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 21:59:02 by edos-san          #+#    #+#             */
/*   Updated: 2022/08/17 22:24:20 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Socket.hpp"

Socket::Socket(){}

Socket::Socket(std::string name,int port, size_t maxClient): _name(name), _port(port), _maxClient(maxClient)
{
	int on = 1;
	_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (_fd < 0) 
	{
		std::cout << "Error establishing socket..." << std::endl;
		exit(1);
	}
	_ic = setsockopt(_fd, SOL_SOCKET,  SO_REUSEADDR, (char *)&_addr, sizeof(on));
	_ic = setsockopt(_fd, SOL_SOCKET,  SO_REUSEPORT, (char *)&_addr, sizeof(on));
	_ic =  fcntl(_fd, F_SETFL, O_NONBLOCK);
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
		exit(0) ;
	}
	_size = sizeof(_addr);
	_fds[0].fd = _fd;
  	_fds[0].events = POLLIN;
	for (size_t i = 1; i < _maxClient; i++)
		setEvent(i, -1, 0);
	listen(_fd, maxClient);
}

Socket::~Socket()
{
	std::cout << "~Socket\n";
}

int Socket::socketListen(void)
{
	struct timespec ts = { .tv_sec = 0, .tv_nsec = 10};
	return (ppoll(_fds, _maxClient, &ts, NULL));
}

int		Socket::getMaxClient()
{
	return (_maxClient);
}

int		Socket::getFd()
{
	return (_fd);
}

int	Socket::socketAccept(void)
{
	return (accept(_fd, (struct sockaddr*)&_addr, &_size));
}

t_event	*Socket::getEvent(int i)
{
	return (&_fds[i]);
}

void	Socket::setEvent(int i, int fd, int event)
{
	_fds[i].fd = fd;
  	_fds[i].events = event;
}

Client *Socket::createClient(int fd_client)
{
	for (size_t i = 1; i < _maxClient; i++)
    {
        if (_fds[i].fd == -1)
		{
			_fds[i].fd = fd_client;
			_fds[i].events = POLLIN;
			return (new Client(&_fds[i]));
		}
    }
	return (NULL);
}