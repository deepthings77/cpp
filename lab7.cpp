#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode() {
        left = nullptr;
        right = nullptr;
    }
    TreeNode(int val) { 
        data = val; 
        left = nullptr;
        right = nullptr;
    }
};


void preorder(TreeNode *node);
void postorder(TreeNode *node);
void inorder(TreeNode *node);

void preorder(TreeNode *node) {
    if (node == nullptr) {
        return;
    }
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

void postorder(TreeNode *node) {
    if (node == nullptr) {
        return;
    }
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}

void inorder(TreeNode *node) {
    if (node == nullptr) {
        return;
    }
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

int main() {
    TreeNode *root = nullptr; 

    cout << "Enter root: ";
    int rootVal;
    cin >> rootVal;
    cout << endl;

    root = new TreeNode(rootVal);

    while (true) {
        int val;
        cout << "1: Enter Node" << endl;
        cout << "2: Preorder" << endl;
        cout << "3: Postorder" << endl;
        cout << "4: Inorder" << endl;
        cout << "5: Exit" << endl;
        cout << "Enter choice: ";
        cin >> val;
        cout << endl;

        switch (val) {
            case 1: {
                int newVal;
                cout << "Enter value: ";
                cin >> newVal;
                cout << endl;

                TreeNode *newNode = new TreeNode(newVal); 

                TreeNode *temp = root;
                while (true) {
                    if (newNode->data > temp->data) {
                        if (temp->right == nullptr) {
                            temp->right = newNode;
                            break;
                        } else {
                            temp = temp->right;
                        }
                    } else {
                        if (temp->left == nullptr) {
                            temp->left = newNode;
                            break;
                        } else {
                            temp = temp->left;
                        }
                    }
                }
                break;
            }
            case 2: {
                preorder(root);
                cout << endl;
                break;
            }
            case 3: {
                postorder(root);
                cout << endl;
                break;
            }
            case 4: {
                inorder(root);
                cout << endl;
                break;
            }
            case 5:
                return 0;
        }
    }

    return 0;
}
