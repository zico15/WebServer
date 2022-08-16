/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 13:16:04 by edos-san          #+#    #+#             */
/*   Updated: 2022/08/16 02:32:31 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <typeinfo>

template <typename T>
class Array
{
    private:
        T       *values;
        size_t  _size;

    public:
        Array()
        {
            values = NULL;
            _size = 0;
        }

		Array(size_t n)
        {
            values = new T[n];
            _size =  n;
        }

		~Array() 
        {
            delete[] values;
        };

        size_t size()const
        {
            return (_size);
        }
        
        Array &operator=(Array const &a)
        {
           if (this == &a)
				return (*this);
			delete[] values;
			values = new T[a.size()];
			for (size_t i = 0; i < a.size(); i++)
            {
				this->values[i] = a.values[i];
            }
			return (*this);
        }

        
        class ExceptionBounds: public std::exception
        {
             private:
	            virtual const char* what() const throw()
                {
                    return ("Index out of bounds");
                }
        };
        
        T &operator[](unsigned int i)
		{
			if (i < 0 || i >= size())
				throw (Array::ExceptionBounds());
			return (values[i]);
		}

};


#endif