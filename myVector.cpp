/*
CSCI 335 Spring 2024
Assignment 2
Name: Tamanna Chowdhury
myVector.cpp: insert and pop median using a vector that's kept sorted
*/
#include "myVector.hpp"

void vectorMedian(const std::vector<int>* instructions) {
    if (instructions->empty())
        return;

    std::vector<int> vec;
    for (int num : *instructions) {
        if (num != -1) {
            std::vector<int>::iterator low;
            low=std::lower_bound (vec.begin(), vec.end(), num); 
            vec.insert(low, num);
        } else {
           
            // Output median
            size_t size = vec.size();
            auto mid = vec.begin() + size / 2;
            if (size % 2 == 0) {
                // Even-sized vector               
                std::cout << vec[(size / 2) - 1] << " ";
                vec.erase(mid - 1);
            } else {
                // Odd-sized vector
                std::cout << vec[(size / 2)] << " ";
                vec.erase(mid);
            }
        }
    }
}










