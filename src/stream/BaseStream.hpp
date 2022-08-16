/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseStream.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:36:04 by edos-san          #+#    #+#             */
/*   Updated: 2022/08/16 14:40:29 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_STREAM_HPP
# define BASE_STREAM_HPP

#include <string>
#include <iostream>

enum e_method
{
	GET,
	POST,
	DELET
};

class BaseStream
{
	protected:
		int			status;
		e_method	method;
		std::string	domian;
		std::string	file;
		std::string	initiator;
		std::string	type;
		size_t		transferred;
		size_t		size;

	public:
		virtual void run() = 0;
		
};


#endif