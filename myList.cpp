/*
CSCI 335 Spring 2024
Assignment 2
Name: Tamanna Chowdhury
myList.cpp: insert and pop median using a vector that's kept sorted
*/

#include "myList.hpp"


void listMedian(const std::vector<int>* instructions) {
    if (!instructions)
        return;

    std::list<int> lst;
    for (int num : *instructions) {
        if (num != -1) {
            // Insert the number into the list while keeping it sorted
            auto it = std::lower_bound(lst.begin(), lst.end(), num);
            lst.insert(it, num);
        } else {
            // Output median
            size_t size = lst.size();
            auto mid = std::next(lst.begin(), size / 2);
            if (size % 2 == 0) {
                // Even-sized list
                auto prevMid = std::prev(mid);
                std::cout << *prevMid << " ";
                // Remove only one of the middle elements
                lst.erase(prevMid);
            } else {
                // Odd-sized list
                std::cout << *mid << " ";
                // Remove the single middle element
                lst.erase(mid);
                
            }
        }
    }
}


/*
even and odd
inset each case grater than or smaller than the median 

- heap and avl and vector
*/

