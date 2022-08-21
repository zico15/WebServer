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
	int on = 1, ic;
	_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (_fd < 0) 
	{
		std::cout << "Error establishing socket..." << std::endl;
		exit(1);
	}
	ic = setsockopt(_fd, SOL_SOCKET,  SO_REUSEADDR, (char *)&_addr, sizeof(on));
	ic = setsockopt(_fd, SOL_SOCKET,  SO_REUSEPORT, (char *)&_addr, sizeof(on));
	//getsockopt(cliente, SOL_SOCKET, SO_RCVBUF, (void *)&_size, sizeof(_size));
	ic =  fcntl(_fd, F_SETFL, O_NONBLOCK);
  	if (ic < 0)
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
		exit(0);
	}
	_size = sizeof(_addr);
	_fds = new t_socket[_maxClient];
	_fds[0].fd = _fd;
  	_fds[0].events = POLLIN;
	for (size_t i = 1; i < _maxClient; i++)
		setEvent(i, -1, 0);
	listen(_fd, maxClient);
}

Socket::~Socket()
{
	std::cout << "~Socket\n";
	delete [] _fds;
}

int Socket::socketListen(void)
{
	struct timespec ts = { .tv_sec = 0, .tv_nsec = 10};
	return (ppoll((pollfd *) _fds, _maxClient, &ts, NULL));
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

t_socket	*Socket::getEvent(int i)
{
	return (&_fds[i]);
}

void	Socket::setEvent(int i, int fd, int event)
{
	_fds[i].fd = fd;
  	_fds[i].events = event;
}

bool Socket::createClient()
{
	int fd_client = socketAccept();
	if (fd_client < 0)
		return (false);
	for (size_t i = 1; i < _maxClient; i++)
    {
        if (_fds[i].fd == -1)
		{
			if (_clients[i])
				delete _clients[i];
			_fds[i].fd = fd_client;
			_fds[i].events = POLLIN;
			_clients[i] = new Client(&_fds[i]);
			std::cout << "new client: " << _fds[i].fd << "\n";
			return (true);
		}
    }
	return (false);
}

void	Socket::runClient(int i)
{
	if (_clients[i])
	{
		if (!_clients[i]->run())
		{
			delete _clients[i];
			_clients[i] = NULL;
			close(_fds[i].fd);
			setEvent(i, -1, 0);
		}
	}
}