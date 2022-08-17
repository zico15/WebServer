/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RequestStream.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:38:44 by edos-san          #+#    #+#             */
/*   Updated: 2022/08/17 23:50:53 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STREAM_HPP
# define STREAM_HPP

#include "../BaseStream.hpp"
# include "../response/ResponseStream.hpp"

class RequestStream: public BaseStream
{
	private:
		/* data */
	public:
		RequestStream(t_event *event);
		~RequestStream();
		virtual BaseStream *run();
};


#endif