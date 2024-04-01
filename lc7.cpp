#include <iostream>
using namespace std;

// Define a Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to insert a new node into the binary tree
Node* insertNode(Node* root, int value, char direction) {
    if (root == nullptr) {
        return new Node(value);
    }
    if (direction == 'L' || direction == 'l') {
        root->left = insertNode(root->left, value, direction);
    } else if (direction == 'R' || direction == 'r') {
        root->right = insertNode(root->right, value, direction);
    }
    return root;
}

// Function to perform preorder traversal of the binary tree
void preorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " "; // Process current node
    preorderTraversal(root->left); // Traverse left subtree
    preorderTraversal(root->right); // Traverse right subtree
}

int main() {
    Node* root = nullptr;

    // Input the elements of the binary tree
    cout << "Enter the elements of the binary tree (-1 to stop):\n";
    int value;
    char direction;
    while (true) {
        cout << "Enter element: ";
        cin >> value;
        if (value == -1) {
            break;
        }
        cout << "Enter direction (L for left, R for right): ";
        cin >> direction;
        root = insertNode(root, value, direction);
    }

    // Printing the preorder traversal of the binary tree
    cout << "Preorder Traversal: ";
    preorderTraversal(root);
    cout << endl;

    // Clean up memory
    // Not necessary for user-driven input as the program exits immediately after traversal

    return 0;
}
