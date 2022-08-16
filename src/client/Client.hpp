/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 21:32:55 by edos-san          #+#    #+#             */
/*   Updated: 2022/08/16 14:43:15 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
# define CLIENT_HPP

#include <string>
#include <iostream>
#include <sys/socket.h>
#include <list>

#include "../stream/BaseStream.hpp"

class Client {

	private:
		int					fd;
		bool				is_online;
        char                buffer[1024];
		BaseStream 			*response;
		BaseStream 			*request;
	public:
		Client();
		~Client();
		void init(int fd)
		{
			fd = 0;
			is_online = false;
		}

		void listen();
		void run();
};

#endif