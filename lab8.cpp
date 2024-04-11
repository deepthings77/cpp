#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode()
    {
        left = nullptr;
        right = nullptr;
    }
    TreeNode(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void inorder(TreeNode *node)
{
    if (node == nullptr)
    {
        return;
    }
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}
TreeNode *lastRight(TreeNode *root)
{
    if (root->right == NULL)
    {
        return root;
    }
    return lastRight(root->right);
}
TreeNode *helper(TreeNode *root)
{
    if (root->left == NULL)
    {
        return root->right;
    }
    if (root->right == NULL)
    {
        return root->left;
    }
    TreeNode *rightNode = root->right;
    TreeNode *last = lastRight(root->left);
    last->right = rightNode;

    return root->left;
}

TreeNode* deleteNode(TreeNode *root, int key)
{

    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return helper(root);
    }
    TreeNode *temp = root;
    while (root != NULL)
    {
        if (root->data > key)
        {
            if (root->left != NULL && root->left->data == key)
            {
                root->left = helper(root->left);
                break;
            }
            else
            {
                root = root->left;
            }
        }
        else
        {
            if (root->right != NULL && root->right->data == key)
            {
                root->right = helper(root->right);
                break;
            }
            else
            {

                root = root->right;
            }
        }
    }
    return temp;
}

int main()
{
    cout << "DEEPAK KUMAWAT" << endl
         << "22BCS034" << endl;
    TreeNode *root = nullptr;

    cout << "Enter root: ";
    int rootVal;
    cin >> rootVal;
    cout << endl;

    root = new TreeNode(rootVal);

    while (true)
    {
        int val;
        cout << "1: Enter Node" << endl;
        cout << "2: Delete" << endl;
        cout << "3: Inorder" << endl;
        cout << "4: Exit" << endl;
        cout << "Enter choice: ";
        cin >> val;
        cout << endl;

        switch (val)
        {
        case 1:
        {
            int newVal;
            cout << "Enter value: ";
            cin >> newVal;
            cout << endl;

            TreeNode *newNode = new TreeNode(newVal);

            TreeNode *temp = root;
            while (true)
            {
                if (newNode->data > temp->data)
                {
                    if (temp->right == nullptr)
                    {
                        temp->right = newNode;
                        break;
                    }
                    else
                    {
                        temp = temp->right;
                    }
                }
                else
                {
                    if (temp->left == nullptr)
                    {
                        temp->left = newNode;
                        break;
                    }
                    else
                    {
                        temp = temp->left;
                    }
                }
            }
            break;
        }
        case 2:
        {
            int key;
            cout << "Enter value to be Deleted" << endl;
            cin >> key;
            cout << endl;
           root =  deleteNode(root, key);
            break;
        }
        case 3:
        {
            inorder(root);
            cout << endl;
            break;
        }
        case 4:
            return 0;
        }
    }

    return 0;
}
