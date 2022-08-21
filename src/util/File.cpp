/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:48:35 by edos-san          #+#    #+#             */
/*   Updated: 2022/08/18 00:34:37 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File.hpp"

File::File(std::string path): _path(path)
{
	if (path == "/")
		_path = "public/index.html";
	else
		_path = "public" + _path;
}

File::File(std::string absolute, std::string file)
{
	_path = absolute + "/" + file;
}

File::~File()
{
	
}

std::string File::getExtensao()
{
	if (_path.empty() || _path.find_last_of('.') >= _path.length())
		return ("");
	return (_path.substr(_path.find_last_of('.') + 1, _path.length()));
}

std::string File::read()
{
	std::stringstream      out;

	try
	{
		std::ifstream ifs (_path.c_str(), std::ifstream::in);
		char c = ifs.get();
  		while (ifs.good()) 
		{
    		out << c;
			c = ifs.get();
		}
  		ifs.close();
	}
	catch(const std::exception& e)
	{
		std::cout << "File ERROR: " << e.what() << '\n';
	}
	return (out.str());
}

void		File::write(std::string value)
{
	try
	{
		std::ofstream outfile (_path.c_str(),std::ofstream::binary);
		outfile.write(value.c_str(), value.length());
		outfile.close();
	}
	catch(const std::exception& e)
	{
		std::cout << "File ERROR: " << e.what() << '\n';
	}
}