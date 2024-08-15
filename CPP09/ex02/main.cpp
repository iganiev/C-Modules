/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:17:29 by iganiev           #+#    #+#             */
/*   Updated: 2024/06/07 21:17:29 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"



int main(int argc, char** argv)
{
    if (argc < 2 || parseArguments(argc, argv) == -1)
    {
        std::cout << "Error" << std::endl;
        return 1;
    }
    if (parseArguments(argc, argv) == -2)
    {
        std::cout << "Sequence is sorted" << std::endl;
        return 1;
    }

    std::vector<int> vec;
    std::list<int> lst;
    for (int i = 1; i < argc; ++i)
    {
        int num = std::stoi(argv[i]);
        vec.push_back(num);
        lst.push_back(num);
    }

    PmergeMe sorter(vec, lst);

    std::cout << "Before: ";
    sorter.printVector();

    // Measure time for sorting vector
    std::clock_t startVec = std::clock();
    sorter.sortVector();
    std::clock_t endVec = std::clock();
    double durationVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1e6; // Convert to microseconds

    // Measure time for sorting list
    std::clock_t startLst = std::clock();
    sorter.sortList();
    std::clock_t endLst = std::clock();
    double durationLst = static_cast<double>(endLst - startLst) / CLOCKS_PER_SEC * 1e6; // Convert to microseconds

    std::cout << "After: ";
    sorter.printList();

    std::cout << std::fixed << std::setprecision(10);
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << durationVec << " us" << std::endl;
    std::cout << "Time to process a range of " << lst.size() << " elements with std::list: " << durationLst << " us" << std::endl;

    return 0;
}


