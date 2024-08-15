/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:18:48 by iganiev           #+#    #+#             */
/*   Updated: 2024/06/07 21:18:48 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <limits.h>
#include <ctime>
#include <iomanip>


class PmergeMe
{

private:
    std::vector<int> _vec;
    std::list<int> _lst;

    std::vector<std::pair<int, int> > pairSequence(const std::vector<int>& sequence);
    void sortPairsBySmallest(std::vector<std::pair<int, int> >& pairs);
    std::pair<std::vector<int>, std::vector<int> > splitPair(const std::vector<std::pair<int, int> >& pairs, int unpaired);
    std::vector<size_t> generateJacobsthalNumbers(size_t limit);
    std::vector<int> insertElements(const std::vector<int>& mainChain, const std::vector<int>& elements);
    int binarySearch(const std::vector<int>& sequence, int target);


    std::list<std::pair<int, int> >pairSequence(const std::list<int>& sequence);
    void sortPairsBySmallest(std::list<std::pair<int, int> >& pairs);
    std::pair<std::list<int>, std::list<int> > splitPair(const std::list<std::pair<int, int> >& pairs, int unpaired);
    std::list<int> insertElements(const std::list<int>& mainChain, const std::list<int>& elements);
    std::list<int>::iterator binarySearch(std::list<int>& sequence, int target);
    
public:
    PmergeMe();
    PmergeMe(const PmergeMe &copy);
    PmergeMe(std::vector<int> &vec, std::list<int> &lst);
    PmergeMe &operator=(const PmergeMe &copy);
    ~PmergeMe();

    void sortVector();
    void sortList();
    void printVector() const;
    void printList() const;
};

bool isPositiveInteger(const std::string& str);
int parseArguments(int argc, char** argv);
bool isSorted(int argc, char** argv);



template<typename T>
void printSequence(const T& container)
{
    typename T::const_iterator it;
    for (it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}





#endif