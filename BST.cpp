#include "BST.h"
#include <iostream>

using namespace std;


// Constructor
BST::BST() {
    root = nullptr;
}


// --------------------------------------------------
// INSERT
// --------------------------------------------------

BST::Node* BST::insert(Node* node, std::string callsign) {

    // We found an empty position
    if (node == nullptr) {
        return new Node(callsign);
    }

    // Smaller keys go left
    if (callsign < node->callsign) {
        node->left = insert(node->left, callsign);
    }

    // Larger keys go right
    else if (callsign > node->callsign) {
        node->right = insert(node->right, callsign);
    }

    return node;
}


// Public insert function
void BST::insert(std::string callsign) {
    root = insert(root, callsign);
}


// --------------------------------------------------
// SEARCH
// --------------------------------------------------

BST::Node* BST::search(Node* node, std::string callsign) {

    // Key was not found
    if (node == nullptr) {
        return nullptr;
    }

    // Key was found
    if (callsign == node->callsign) {
        return node;
    }

    // Search left subtree
    if (callsign < node->callsign) {
        return search(node->left, callsign);
    }

    // Search right subtree
    return search(node->right, callsign);
}


// Public search function
bool BST::search(std::string callsign) {
    return search(root, callsign) != nullptr;
}


// --------------------------------------------------
// IN-ORDER TRAVERSAL
// --------------------------------------------------

void BST::inorder(Node* node) {

    if (node == nullptr) {
        return;
    }

    inorder(node->left);

    cout << node->callsign << " ";

    inorder(node->right);
}


// Public inorder function
void BST::inorder() {
    inorder(root);
    cout << endl;
}


// --------------------------------------------------
// MINIMUM
// --------------------------------------------------

BST::Node* BST::findMin(Node* node) {

    if (node == nullptr) {
        return nullptr;
    }

    while (node->left != nullptr) {
        node = node->left;
    }

    return node;
}


std::string BST::findMin() {

    Node* node = findMin(root);

    if (node == nullptr) {
        return 0;
    }

    return node->callsign;
}


// --------------------------------------------------
// MAXIMUM
// --------------------------------------------------

BST::Node* BST::findMax(Node* node) {

    if (node == nullptr) {
        return nullptr;
    }

    while (node->right != nullptr) {
        node = node->right;
    }

    return node;
}


std::string BST::findMax() {

    Node* node = findMax(root);

    if (node == nullptr) {
        return 0;
    }

    return node->callsign;
}