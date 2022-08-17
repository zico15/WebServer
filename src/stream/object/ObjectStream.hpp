/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ObjectStream.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 19:45:38 by edos-san          #+#    #+#             */
/*   Updated: 2022/08/17 23:28:45 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_STREAM_HPP
# define OBJECT_STREAM_HPP

# include <string>
# include <iostream>
# include <bits/stdc++.h>
# include <map>


class ObjectStream
{
	public:
		ObjectStream(std::string str);
		~ObjectStream();
		void addItem(std::string line);
		void addItem(std::string key, std::string value);
		std::string getKey(std::string key);
		std::map<std::string, std::string> values;
};

std::ostream &operator<<(std::ostream &os, ObjectStream &object);

#endif