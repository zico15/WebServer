/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 21:54:58 by edos-san          #+#    #+#             */
/*   Updated: 2022/08/16 23:24:06 by edos-san         ###   ########.fr       */
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

#include  "../client/Client.hpp"

#define BUFFER_SIZE 1024
#define TIME_OUT 3 * 60 * 1000

class Socket 
{
	private:
		std::string 		_name;
		struct sockaddr_in	_addr;
		socklen_t         	_size;
		char				_buffer[BUFFER_SIZE];
		int					_port;
		int					_fd;
		int					_ic = 0;
		int					_maxClient;
		event				_fds[201];

	public:
		Socket();
		Socket(std::string name,int port, int maxClient);
		~Socket();
		int		socketListen(void);
		int		getMaxClient();
		int		getFd();
		event	*getEvent(int i);
		int		socketAccept(void);
		void	setEvent(int i, int fd, int event);
		Client *createClient(int fd_client);
};

#endif