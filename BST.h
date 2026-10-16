#include <string>
#ifndef BST_H
#define BST_H




struct CrewMember { 
    std::string callsign;                     
    std::string role;
    std::string home_base;
    int level = 0;
    int missions = 0;
};
    

class BST {
private:


    // A node in the Binary Search Tree
    struct Node {
        CrewMember data;
        
        
        Node* left;
        Node* right;

        Node(CrewMember k) {
            data = k;
            left = nullptr;
            right = nullptr;
        }
    };

    // Root of the entire tree
    Node* root;

    // Recursive helper functions
    Node* insert(Node* node, CrewMember crew);
    Node* search(Node* node, CrewMember crew);
    void inorder(Node* node);

    Node* findMin(Node* node);
    Node* findMax(Node* node);

public:

    // Constructor
    BST();

    // Functions students use
    void insert(CrewMember crew);
    CrewMember* search(std::string callsign);

    void inorder();

   CrewMember* findMin();
   CrewMember* findMax();
};

#endif