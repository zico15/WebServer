/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ResponseStream.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:38:44 by edos-san          #+#    #+#             */
/*   Updated: 2022/08/16 14:38:00 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STREAM_HPP
# define STREAM_HPP

#include "../BaseStream.hpp"

class ResponseStream: public BaseStream
{
	private:
		/* data */
	public:
		ResponseStream(/* args */);
		~ResponseStream();
};


#endif