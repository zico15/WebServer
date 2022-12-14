/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 21:32:55 by edos-san          #+#    #+#             */
/*   Updated: 2022/08/17 23:48:42 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
# define CLIENT_HPP

# include <string>
# include <iostream>
# include <sys/socket.h>
# include <list>

# include "../stream/BaseStream.hpp"
# include "../stream/request/RequestStream.hpp"
# include "../stream/response/ResponseStream.hpp"
# include "../util/File.hpp"

class Client {

	private:
		BaseStream 			*_response;
		BaseStream 			*_request;
		t_socket 			*_socket;

	public:
		Client();
		Client(t_socket *socket);
		~Client();
		bool run();
};
#endif