/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ResponseStream.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:38:44 by edos-san          #+#    #+#             */
/*   Updated: 2022/08/18 00:02:50 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESPONSE_STREAM_HPP
# define RESPONSE_STREAM_HPP

# include "../BaseStream.hpp"

class ResponseStream: public BaseStream
{
	private:
		BaseStream	*_request;
	public:
		ResponseStream();
		ResponseStream(BaseStream *request);
		~ResponseStream();
		virtual BaseStream *run();
};



#endif