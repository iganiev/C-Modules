/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 22:45:02 by iganiev           #+#    #+#             */
/*   Updated: 2024/05/21 22:45:02 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ARRAY_TPP
# define ARRAY_TPP

template <typename T>
Array<T>::Array() : array(NULL), length(0)
{
    std::cout << "Empty Array Created" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : array(new T[n]), length(n) {}

template <typename T>
Array<T>::Array(Array const &copy) : array(new T[copy.length]), length(copy.length)
{
    for (size_t i = 0; i < length; i++)
    {
        array[i] = copy.array[i];
    }
}

template <typename T>
Array<T>::~Array()
{
    delete[] array;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &src)
{
    if (this == &src)
        return *this;
    delete[] array;
    array = new T[src.length];
    length = src.length;
    for (size_t i = 0; i < length; i++)
    {
        array[i] = src.array[i];
    }
    return *this;
}

template <typename T>
T &Array<T>::operator[](size_t i)
{
    if (i >= length)
        throw std::out_of_range("Index out of range");
    return array[i];
}


template <typename T>
size_t Array<T>::size() const
{
    return length;
}


#endif