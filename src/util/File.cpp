/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:48:35 by edos-san          #+#    #+#             */
/*   Updated: 2022/08/16 16:15:53 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File.hpp"

File::File(std::string path): path(path)
{
	
}

File::~File()
{
	
}

std::string File::read()
{
	std::string       out = "";
	std::string		  txt;

	try
	{
		std::ifstream r(path);
		while (getline (r, txt))
		 	out += txt + "\n";
		r.close();
	}
	catch(const std::exception& e)
	{
		std::cout << "File ERROR: " << e.what() << '\n';
	}
	return (out);
}

void		File::write(std::string value)
{
	try
	{
		std::ofstream w(path);

		w << value;
		w.close();
	}
	catch(const std::exception& e)
	{
		std::cout << "File ERROR: " << e.what() << '\n';
	}
}