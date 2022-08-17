/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 21:32:55 by edos-san          #+#    #+#             */
/*   Updated: 2022/08/17 00:03:57 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
# define CLIENT_HPP

#include <string>
#include <iostream>
#include <sys/socket.h>
#include <list>
#include <sys/poll.h>

#include "../stream/BaseStream.hpp"
#include "../util/File.hpp"

typedef struct event_pollfd event;

class Client {

	private:
		bool				_is_online = false;
        char                _buffer[1024];
		BaseStream 			*_response;
		BaseStream 			*_request;
		event				*_event;

	public:
		Client();
		~Client();
		void listen();
		void init(event	*event, int fd);
		void run();
		bool isOnline();
		int					_fd = -1;
};

struct event_pollfd
{
  	int 	  fd;			/* File descriptor to poll.  */
  	short int events;		/* Types of events poller cares about.  */
  	short int revents;	/* Types of events that actually occurred.  */
	Client	  client;
};

#endif