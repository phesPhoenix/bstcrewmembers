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

BST::Node* BST::insert(Node* node, CrewMember crew) {

    // We found an empty position
    if (node == nullptr) {
        return new Node(crew);
    }

    // Smaller keys go left
    if (crew.callsign < node->data.callsign) {
        node->left = insert(node->left, crew);
    }

    // Larger keys go right
    else if (crew.callsign > node->data.callsign) {
        node->right = insert(node->right, crew);
    }

    return node;
}


// Public insert function
void BST::insert(CrewMember crew) {
    root = insert(root, crew);
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
    if (callsign == node->data.callsign) {
        return node;
    }

    // Search left subtree
    if (callsign < node->data.callsign) {
        return search(node->left, callsign);
    }

    // Search right subtree
    return search(node->right, callsign);
}


// Public search function
CrewMember* BST::search(std::string callsign) {

    Node* node = search(root, callsign);

    if (node == nullptr) {
        return nullptr;
    }

    return &node->data;
}


// --------------------------------------------------
// IN-ORDER TRAVERSAL
// --------------------------------------------------


void BST::inorder(Node* node) {

    if (node == nullptr) {
        return;
    }

    inorder(node->left);

    cout << node->data.callsign << " | "
         << node->data.role << " | "
         << node->data.home_base << " | Level "
         << node->data.level << " | Missions "
         << node->data.missions << endl;

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
        return "";
    }

    return node->data.callsign;
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
        return "";
    }

    return node->data.callsign;
}