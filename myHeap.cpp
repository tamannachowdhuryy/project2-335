/*
CSCI 335 Spring 2024
Assignment 2
Name: Tamanna Chowdhury
myHeap.cpp: insert and pop median using a vector that's kept sorted


the approach you'll take for using heaps and trees is simple:
You'll keep 2 containers, let's call them "small" and "large", with small holding the median and all values less than the median, and large holding all values greater than the median.
Thus, the median will be the maximum element in small, and small will always be of equal size or 1 element larger than large.
While inserting or popping the median, you may need to rebalance the containers, requiring you to move the largest element in "small" to "large", or the smallest element in "large" to "small", as appropriate.
As a reminder, for a container with an even number of elements, the median will be the lesser of the two middle elements.
For heaps, you may use https://cplusplus.com/reference/queue/priority_queue/. If you look at the template parameters, you'll see 3: T, Container, Compare. If you leave Container and Compare blank, you'll get the default heap - 
a max heap using a vector. If you want a min heap, you need to specify all the parameters, and use "greater than" as the comparison.
*/

    #include "myHeap.hpp"


    void heapMedian(const std::vector<int>* instructions) {
        if (!instructions)
            return;

        std::priority_queue<int> small; // Max heap for smaller half
        std::priority_queue<int, std::vector<int>, std::greater<int>> large; // Min heap for larger half

        for (int num : *instructions) {
            if (num != -1) {
                // Insert the number into appropriate container
                if (small.empty() || num < small.top())
                    small.push(num);
                else
                    large.push(num);

                // Balance the heaps if necessary
                if (small.size() > large.size() + 1) {
                    large.push(small.top());
                    small.pop();
                } else if (large.size() > small.size()) {
                    small.push(large.top());
                    large.pop();
                }
            } else {
                // Output and remove median
                if (small.size() > large.size()) {
                    std::cout << small.top() << " ";
                    small.pop();
                } else if (small.size() == large.size()) {
                    std::cout << small.top() << " ";
                    small.pop();
                } else {
                    std::cout << large.top() << " ";
                    large.pop();
                }

                // Balance the heaps after removing median
                if (small.size() > large.size() + 1) {
                    large.push(small.top());
                    small.pop();
                } else if (large.size() > small.size()) {
                    small.push(large.top());
                    large.pop();
                }
            }
        }
    }

// void heapMedian(const std::vector<int>* instructions) {
//     if (!instructions)
//         return;

//     std::priority_queue<int> small; // Max heap for smaller half
//     std::priority_queue<int, std::vector<int>, std::greater<int>> large; // Min heap for larger half

//     for (int num : *instructions) {
//         if (num != -1) {
//             // Insert the number into appropriate container
//             if (small.empty() || num < small.top())
//                 small.push(num);
//             else
//                 large.push(num);

//             // Rebalance the heaps if necessary
//             if (small.size() > large.size() + 1) {
//                 large.push(small.top());
//                 small.pop();
//             } else if (large.size() > small.size()) {
//                 small.push(large.top());
//                 large.pop();
//             }
//         } else {
//             // Output median
//             if (small.size() > large.size()){
//                 if (!small.empty()) {
//                     std::cout << small.top() << " ";
//                     small.pop();
//                 }
//                 if (small.size() > large.size() + 1) {
//                 large.push(small.top());
//                 small.pop();
//             } else if (large.size() > small.size()) {
//                 small.push(large.top());
//                 large.pop();
//             }
//             }
//             else if (small.size() == large.size()) {
//                 if (!small.empty()) {
//                     std::cout << small.top() << " ";
//                     small.pop();
//                 }
//                 if (small.size() > large.size() + 1) {
//                 large.push(small.top());
//                 small.pop();
//             } else if (large.size() > small.size()) {
//                 small.push(large.top());
//                 large.pop();
//             }
//             } else {
//                 std::cout << large.top() << " ";
//                 if (small.size() > large.size() + 1) {
//                 large.push(small.top());
//                 small.pop();
//             } else if (large.size() > small.size()) {
//                 small.push(large.top());
//                 large.pop();
//             }
//             }
//         }
//     }
//     std::cout << std::endl; 
//}


