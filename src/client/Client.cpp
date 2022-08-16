/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 22:40:38 by edos-san          #+#    #+#             */
/*   Updated: 2022/08/16 14:47:51 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"

Client::Client()
{
    
}

Client::~Client() 
{
    
}

void Client::listen()
{
    std::cout << "Client: ";
    do {
        recv(fd, buffer, 1024, 0);
        std::cout << buffer << " ";
        if (*buffer == '#')
            *buffer = '*';
    } while (*buffer != '*');
      std::cout << "Client filizer\n";
}

void Client::run()
{
    
}