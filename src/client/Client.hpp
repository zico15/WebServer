/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 21:32:55 by edos-san          #+#    #+#             */
/*   Updated: 2022/08/16 02:38:48 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
# define CLIENT_HPP

#include <string>
#include <iostream>
#include <sys/socket.h>

class Client {

	private:
		int					fd;
		bool				is_online;
        char                buffer[1024];
	public:
		Client();
		~Client();
		void init(int fd)
		{
			fd = 0;
			is_online = false;
		}

		void listen();
		
		void setStatus(bool	v)
		{
			is_online = v;
		};
		
		bool getStatus(void)
		{
			return is_online;
		};
	
};

#endif