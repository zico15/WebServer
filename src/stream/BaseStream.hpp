/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseStream.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:36:04 by edos-san          #+#    #+#             */
/*   Updated: 2022/08/17 23:51:48 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_STREAM_HPP
# define BASE_STREAM_HPP

# include <string>
# include <iostream>
# include <sys/socket.h>
# include <sys/poll.h>
# include  <bits/stdc++.h>

# include "object/ObjectStream.hpp"
# include "../util/File.hpp"


typedef struct pollfd t_socket;

enum e_method
{
	GET,
	POST,
	DELET
};

class BaseStream
{
	protected:
		int				_status;
		e_method		_method;
		std::string		_domian;
		std::string		_file;
		std::string		_initiator;
		std::string		_type;
		size_t			_transferred;
		size_t			_size;
		int				_fd;
		char        	_buffer[1025];

	public:
		virtual ~BaseStream();
		virtual BaseStream *run() = 0;
		t_socket			*_socket;
		ObjectStream		*_out;
		int					_id;
		
};

#endif