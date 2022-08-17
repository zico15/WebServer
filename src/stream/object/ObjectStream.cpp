/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ObjectStream.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 19:46:03 by edos-san          #+#    #+#             */
/*   Updated: 2022/08/17 23:18:23 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ObjectStream.hpp"

ObjectStream::ObjectStream(std::string str)
{
	std::string parsed;
	std::stringstream input(str);
	size_t i = 0;
	while (getline(input,parsed,'\n'))
	{
		if (i == 0)
		{
			std::stringstream head(parsed);
			while (getline(head, parsed,' '))
			{
				if (i == 0)
					parsed = "Method: " + parsed;
				if (i == 1)
					parsed = "File: " + parsed;
				if (i == 2)
					parsed = "Version: " + parsed;
				addItem(parsed);
				i++;
			}
			i++;
		}
		else
			addItem(parsed);
	}
}

void ObjectStream::addItem(std::string key, std::string value)
{
	if (key.empty() || value.empty())
		return ;
	//std::cout << " key: " << key << "  value: " << value << "\n";
	values[key] = value;
}

void ObjectStream::addItem(std::string line)
{
	bool is_key = true;
	std::string key;
	std::string value;
	for (size_t i = 0; i < line.length(); i++)
	{
		if (line[i] == ':' && line[i + 1] == ' ')
		{
			i += (is_key == true);
			is_key = false;
		}
		else
		{
			if (is_key)
				key += line[i];
			else
				value += line[i];
		}
	}
	addItem(key, value);
}

std::string ObjectStream::getKey(std::string key)
{
	return (values[key]);
}

ObjectStream::~ObjectStream()
{
	
}

std::ostream &operator<<(std::ostream &os, ObjectStream &object)
{
	std::map<std::string, std::string>::iterator iter;
	for (iter = object.values.begin(); iter != object.values.end(); ++iter)
	 	os << iter->first << ": " << iter->second<< std::endl;
	return (os);
}