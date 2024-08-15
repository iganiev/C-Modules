/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:19:55 by iganiev           #+#    #+#             */
/*   Updated: 2024/06/07 21:19:55 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &copy) {
    *this = copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy) {
    if (this != &copy)
        *this = copy;
    return *this;
}

PmergeMe::PmergeMe(std::vector<int> &vec, std::list<int> &lst) : _vec(vec), _lst(lst) {}

PmergeMe::~PmergeMe() {}


bool isPositiveInteger(const std::string& str)
{
    if (str.empty())
        return false;

    // Check for leading zeros
    if (str.size() > 1 && str[0] == '0')
        return false;

    for (std::string::size_type i = 0; i < str.size(); ++i)
    {
        if (!std::isdigit(str[i]))
            return false;
    }
    // Convert string to integer and check bounds
    char* endPtr;
    long num = std::strtol(str.c_str(), &endPtr, 10);
    
    // Check if conversion was successful and if it's a positive integer
    if (*endPtr != '\0' || num <= 0 || num > std::numeric_limits<int>::max())
        return false;
    return true;
}

bool isSorted(int argc, char** argv)
{
    if (argc == 1)
        return true;

    int prev = std::stoi(argv[1]);
    for (int i = 2; i < argc; ++i) 
    {
        int current = std::stoi(argv[i]);
        if (current < prev)
            return false;
        prev = current;
    }
    return true;
}

int parseArguments(int argc, char** argv)
{
    for (int i = 1; i < argc; ++i)
    {
        std::string arg = argv[i];
        if (!isPositiveInteger(arg))
            return -1;
    }

    if (isSorted(argc, argv))
        return -2;

    return 0;
}

void PmergeMe::sortVector()
{
    int unpaired = INT_MAX;
    if (_vec.size() % 2 != 0)
    {
        unpaired = _vec.back();
        _vec.pop_back();
    }

    std::vector<std::pair<int, int> > vecPairs = pairSequence(_vec);
    sortPairsBySmallest(vecPairs);

    std::pair<std::vector<int>, std::vector<int> > sequences = splitPair(vecPairs, unpaired);
    std::vector<int> mainChain = sequences.first;
    std::vector<int> elements = sequences.second;

    _vec = insertElements(mainChain, elements);
}


std::vector<std::pair<int, int> > PmergeMe::pairSequence(const std::vector<int>& sequence)
{
    std::vector<std::pair<int, int> > pairs;
        
    size_t n = sequence.size();
    
// Base case: if there's only one element left, leave it unpaired
    if (n == 1) {
        pairs.push_back(std::make_pair(sequence[0], INT_MAX)); // Unpaired last element
        return pairs;
    }
    
    // Pair elements and call recursively on the remaining sequence
    for (size_t i = 0; i < n - 1; i += 2)
    {
        if (sequence[i] > sequence[i + 1])
            pairs.push_back(std::make_pair(sequence[i + 1], sequence[i]));
        else
            pairs.push_back(std::make_pair(sequence[i], sequence[i + 1]));
    }

    // Sort elements within each pair
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        std::pair<int, int>& pair = pairs[i];
        if (pair.second != INT_MAX && pair.first > pair.second)
            std::swap(pair.first, pair.second);
    }

    return pairs;
}


void PmergeMe::sortPairsBySmallest(std::vector<std::pair<int, int> >& pairs)
{
    // Bubble sort to sort pairs by the smallest element
    for (size_t i = 0; i < pairs.size() - 1; ++i)
    {
        for (size_t j = 0; j < pairs.size() - i - 1; ++j)
        {
            if (pairs[j].second > pairs[j + 1].second)
                // Swap the pairs
                std::swap(pairs[j], pairs[j + 1]);
        }
    }
}


std::pair<std::vector<int>, std::vector<int> > PmergeMe::splitPair(const std::vector<std::pair<int, int> >& pairs, int unpaired)
{
    std::vector<int> firstSeq, secondSeq;
    
    // Replace range-based loop with a traditional loop
    for (std::vector<std::pair<int, int> >::const_iterator it = pairs.begin(); it != pairs.end(); ++it)
    {
        if (it->second != INT_MAX)
        {
            firstSeq.push_back(it->second);
            secondSeq.push_back(it->first);
        }
    }

    if (unpaired != INT_MAX)
        secondSeq.push_back(unpaired);

    return std::make_pair(firstSeq, secondSeq);
}



int PmergeMe::binarySearch(const std::vector<int>& sequence, int target)
{
    int left = 0;
    int right = sequence.size() - 1;

    while (left <= right)
    {
        int middle = (left + right) / 2;

        if (sequence[middle] == target)
            return middle;
        else if (sequence[middle] < target)
            left = middle + 1;
        else
            right = middle - 1;
    }

    return left;
}


std::vector<size_t> PmergeMe::generateJacobsthalNumbers(size_t limit)
{
    std::vector<size_t> jacobsthal;
    int jacobsthalSequence[limit + 1];

    jacobsthalSequence[0] = 0;
    jacobsthalSequence[1] = 1;
    int lastJacobsthalNumber = 2;

    for (size_t i = 2; jacobsthal.size() < limit; i++)
    {
        // Generate the next Jacobsthal number
        jacobsthalSequence[i] = jacobsthalSequence[i - 1] + 2 * jacobsthalSequence[i - 2];

        // Push the jacobsthal number
        i != 2 ? jacobsthal.push_back(jacobsthalSequence[i]) : (void)0;

        // Push back the indexes between the last Jacobsthal number and the current one
        for (int j = jacobsthalSequence[i] - 1; j > lastJacobsthalNumber; j--)
            jacobsthal.push_back(j);

        // Update the last Jacobsthal number
        lastJacobsthalNumber = jacobsthalSequence[i];
    }
    return jacobsthal;
}






std::vector<int> PmergeMe::insertElements(const std::vector<int>& mainChain, const std::vector<int>& elements)
{
    std::vector<int> result = mainChain;
    std::vector<size_t> jacobsthalNumbers = generateJacobsthalNumbers(elements.size());

    std::vector<int> elementsCopy = elements;
    std::vector<int> sortedMainChain = result;

    // The first element of elementsCopy is already in sortedMainChain by default
    sortedMainChain.insert(sortedMainChain.begin(), elementsCopy[0]);
    elementsCopy.erase(elementsCopy.begin());

    // Insert the rest of the elements based on Jacobsthal numbers
    for (size_t i = 0; i < jacobsthalNumbers.size(); ++i)
    {
        if (jacobsthalNumbers[i] >= elementsCopy.size())
            continue;

        int elementToInsert = elementsCopy[jacobsthalNumbers[i]];

        // Find the correct position to insert using binary search
        int position = binarySearch(sortedMainChain, elementToInsert);

        // Insert the element at the correct position
        sortedMainChain.insert(sortedMainChain.begin() + position, elementToInsert);
    }

    // Insert any remaining elements that are not covered by Jacobsthal numbers
    for (size_t i = 0; i < elementsCopy.size(); ++i)
    {
        if (std::find(jacobsthalNumbers.begin(), jacobsthalNumbers.end(), i) == jacobsthalNumbers.end())
        {
            int elementToInsert = elementsCopy[i];
            int position = binarySearch(sortedMainChain, elementToInsert);
            sortedMainChain.insert(sortedMainChain.begin() + position, elementToInsert);
        }
    }
    return sortedMainChain;
}


/* ********************************************** LIST *************************************************** */


void PmergeMe::sortList()
{
    int unpaired = INT_MAX;
    if (_lst.size() % 2 != 0)
    {
        unpaired = _lst.back();
        _lst.pop_back();
    }

    std::list<std::pair<int, int> > lstPairs = pairSequence(_lst);
    sortPairsBySmallest(lstPairs);

    std::pair<std::list<int>, std::list<int> > sequences = splitPair(lstPairs, unpaired);
    std::list<int> mainChain = sequences.second;
    std::list<int> elements = sequences.first;

    _lst = insertElements(mainChain, elements);
}


std::list<std::pair<int, int> > PmergeMe::pairSequence(const std::list<int>& sequence)
{
    std::list<std::pair<int, int> > pairs;
    std::list<int>::const_iterator it = sequence.begin();
    
    while (it != sequence.end())
    {
        int first = *it++;
        int second = (it != sequence.end()) ? *it++ : INT_MAX;
        
        // Ensure the pair is sorted by smallest element
        if (first > second)
            std::swap(first, second);
        
        pairs.push_back(std::make_pair(first, second));
    }
    
    return pairs;
}


void PmergeMe::sortPairsBySmallest(std::list<std::pair<int, int> >& pairs)
{
    // Bubble sort to sort pairs by the smallest element
    bool swapped = true;
    while (swapped)
    {
        swapped = false;
        for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
        {
            std::list<std::pair<int, int> >::iterator nextIt = it;
            ++nextIt;
            if (nextIt != pairs.end() && it->second > nextIt->second)
            {
                std::swap(*it, *nextIt);
                swapped = true;
            }
        }
    }
}


std::pair<std::list<int>, std::list<int> > PmergeMe::splitPair(const std::list<std::pair<int, int> >& pairs, int unpaired)
{
    std::list<int> firstSeq, secondSeq;
    
    for (std::list<std::pair<int, int> >::const_iterator it = pairs.begin(); it != pairs.end(); ++it)
    {
        firstSeq.push_back(it->first);
        secondSeq.push_back(it->second);
    }

    if (unpaired != INT_MAX)
        firstSeq.push_back(unpaired);
    
    return std::make_pair(firstSeq, secondSeq);
}



std::list<int>::iterator PmergeMe::binarySearch(std::list<int>& sequence, int target)
{
    std::list<int>::iterator left = sequence.begin();
    std::list<int>::iterator right = sequence.end();

    while (left != right)
    {
        std::list<int>::iterator middle = left;
        std::advance(middle, std::distance(left, right) / 2);

        if (*middle == target)
            return middle;
        else if (*middle < target)
            left = ++middle;
        else
            right = middle;
    }

    return left;
}


std::list<int> PmergeMe::insertElements(const std::list<int>& mainChain, const std::list<int>& elements)
{
    std::list<int> result = mainChain;
    std::vector<size_t> jacobsthalNumbers = generateJacobsthalNumbers(elements.size());

    std::list<int> elementsCopy = elements;
    std::list<int> sortedMainChain = result;

    // The first element of elementsCopy is already in sortedMainChain by default
    sortedMainChain.push_front(elementsCopy.front());
    elementsCopy.pop_front();

    // Insert the rest of the elements based on Jacobsthal numbers
    for (size_t i = 0; i < jacobsthalNumbers.size(); ++i)
    {
        if (jacobsthalNumbers[i] >= elementsCopy.size())
            continue;

        std::list<int>::iterator it = elementsCopy.begin();
        std::advance(it, jacobsthalNumbers[i]);
        int elementToInsert = *it;

        std::list<int>::iterator position = binarySearch(sortedMainChain, elementToInsert);
        sortedMainChain.insert(position, elementToInsert);
    }

    // Insert any remaining elements that are not covered by Jacobsthal numbers
    for (std::list<int>::iterator it = elementsCopy.begin(); it != elementsCopy.end(); ++it)
    {
        size_t idx = std::distance(elementsCopy.begin(), it);

        if (std::find(jacobsthalNumbers.begin(), jacobsthalNumbers.end(), idx) == jacobsthalNumbers.end())
        {
            int elementToInsert = *it;
            std::list<int>::iterator position = binarySearch(sortedMainChain, elementToInsert);
            sortedMainChain.insert(position, elementToInsert);
        }
    }

    return sortedMainChain;
}

void PmergeMe::printVector() const
{
    printSequence(_vec);
}

void PmergeMe::printList() const
{
    printSequence(_lst);
}

