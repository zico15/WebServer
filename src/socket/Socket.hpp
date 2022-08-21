/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 21:54:58 by edos-san          #+#    #+#             */
/*   Updated: 2022/08/17 22:24:25 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOCKET_HPP
# define SOCKET_HPP

#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/poll.h>
#include <fcntl.h>
#include <map>
#include  "../client/Client.hpp"

#define BUFFER_SIZE 1024
#define TIME_OUT 3 * 60 * 1000

class Socket 
{
	private:
		std::string 			_name;
		struct sockaddr_in		_addr;
		socklen_t         		_size;
		char					_buffer[BUFFER_SIZE];
		int						_port;
		int						_fd;
		size_t					_maxClient;
		t_socket				*_fds;
		std::map<int, Client *>	_clients;

	public:
		Socket();
		Socket(std::string name,int port, size_t maxClient);
		~Socket();
		int		socketListen(void);
		int		getMaxClient();
		int		getFd();
		t_socket	*getEvent(int i);
		int		socketAccept(void);
		void	setEvent(int i, int fd, int event);
		bool	createClient(void);
		void	runClient(int i);
};

#endif