#include "myAVLtree.hpp"

    /*
    AVL Tree -> implementation
        - traverse tree to find the max or the min
        - two trees that has max so all the way in the bottom while min is also in the bottom
        - CASE ONE: even tree will get the small min 
                2,3,4,5 -> min => 3
        - CASE TWO: odd tree will get the small min 
                1, 2, [3], 4, 5 -> min => 3 -> biggest on the tree
        - CASE THREE: even inserted from max
                2, 3, [4], 5, 6  -> max => 4 -> biggest on the tree 

    
    */
    
// Function to find the median of elements in a vector using AVL trees
void treeMedian(const std::vector<int> * instructions) {
    AvlTree<int> small; // AVL tree to store the smaller half of elements
    AvlTree<int> large; // AVL tree to store the larger half of elements

    // Iterate through the vector of instructions
    for (int i = 0; i < instructions->size(); ++i) {
        int num = (*instructions)[i]; // Get the next number from the instructions

        // Insert the number into the appropriate AVL tree
        if (small.isEmpty() || num <= small.findMax()) {
            small.insert(num);
        } else {
            large.insert(num);
        }

        // Balance the AVL trees
        if (small.findMax() - large.findMin() > 1) {
            int temp = small.findMax();
            small.remove(temp);
            large.insert(temp);
        } else if (large.findMin() - small.findMax() > 1) {
            int temp = large.findMin();
            large.remove(temp);
            small.insert(temp);
        }

        // Calculate the median and print it
        int smallSize = small.isEmpty() ? 0 : small.findMax();
        int largeSize = large.isEmpty() ? 0 : large.findMin();
        if (smallSize == largeSize) {
            std::cout << "Median: " << smallSize << std::endl;
        } else {
            std::cout << "Median: " << (smallSize + largeSize) / 2 << std::endl;
        }
    }
}

