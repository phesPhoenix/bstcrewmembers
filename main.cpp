#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "BST.h"

using namespace std;




int main() {
    
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