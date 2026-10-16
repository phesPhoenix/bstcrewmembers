#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "BST.h"

using namespace std;


std::vector<std::vector<std::string>> readCSV(const std::string& filename) {
    std::vector<std::vector<std::string>> data;
    std::ifstream file(filename);
    
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return data;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::vector<std::string> row;
        std::stringstream ss(line);
        std::string cell;

        while (std::getline(ss, cell, ',')) {
            row.push_back(cell);
            row.push_back(",");
            std::cout << cell;
        }

        data.push_back(row);
    }

    file.close();
    return data;
}

int main() {
    readCSV("galactic_crew.csv");
    BST tree;

    // Insert keys
    tree.insert("Nova");
    tree.insert("Atlas");
    tree.insert("Orion");
    tree.insert("Echo");
    tree.insert("Lyra");
    tree.insert("Zenith");
    tree.insert("Comet");

    cout << "In-order traversal:" << endl;
    tree.inorder();

    cout << endl;

    // Search
    cout << "Search for Nova: ";

    if (tree.search("Nova")) {
        cout << "Found" << endl;
    }
    else {
        cout << "Not found" << endl;
    }


    cout << "Search for PhePhe: ";

    if (tree.search("Phe")) {
        cout << "Found" << endl;
    }
    else {
        cout << "Not found" << endl;
    }


    cout << endl;

    // Minimum and maximum
    cout << "Minimum: " << tree.findMin() << endl;
    cout << "Maximum: " << tree.findMax() << endl;

    return 0;
}