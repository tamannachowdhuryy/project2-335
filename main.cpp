#include "myVector.hpp"
#include "myAVLtree.hpp"
#include "myList.hpp"
#include "myHeap.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>


int main() {
    std::ifstream file("testinput.txt"); // Assuming the file name is instructions.txt
    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::vector<int> instructions;
    std::string line;
    while (std::getline(file, line)) {
        if (line.find("insert") != std::string::npos) {
            // Extracting the number to insert
            int num = std::stoi(line.substr(line.find(" ") + 1));
            instructions.push_back(num);
        } else if (line == "pop median") {
            instructions.push_back(-1);
        }
    }

    //check if it is bring read in correctly 
    // std::cout << std::endl;
    // for (int num : instructions) {
    //     std::cout << num << " ";
    // }
    // std::cout << std::endl;

    // //Print only the median of the vector
    // std::cout << "Vector Median: " << std::endl;
    // vectorMedian(&instructions); // Pass the address of the vector
    // std::cout << std::endl;
    // std::cout << std::endl;

    // // Print only the median of the list
    // std::cout << "List Median: " << std::endl;
    // listMedian(&instructions); // Pass the address of the list
    // std::cout << std::endl;
    // std::cout << std::endl;

    // // // Print only the median of the list
    // std::cout << "Heap Median: " << std::endl;
    // heapMedian(&instructions); // Pass the address of the list
    // std::cout << std::endl;
    // std::cout << std::endl;

    // // Print only the median of the list
    std::cout << "AVL Median: " << std::endl;
    AvlTree<int> avlTree; // Create an instance of AvlTree
    // Call treeMedian function on the avlTree instance
    avlTree.treeMedian(&instructions);

    // std::vector<int> testList = {5, 2, 8, 3, -1, 6, 4, -1, 7, 10, 30, -1}; //  2, 3, 5, 8   -> 3 
    // // 2, 4, 5, 6, 8 -> 5
    // // 2, 4, 5, 6, 7, 8, 10, 30
    // heapMedian(&testList);
    // std::cout << std::endl;


    file.close();

    return 0;
}










