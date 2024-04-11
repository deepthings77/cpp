#include <iostream>
#include <queue>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *leftptr;
    TreeNode *rightptr;

    TreeNode(int d)
    {
        this->data = d;
        this->leftptr = NULL;
        this->rightptr = NULL;
    }
};

void inorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->leftptr);
    cout << root->data << " ";
    inorder(root->rightptr);
}

void preorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preorder(root->leftptr);
    preorder(root->rightptr);
}

void postorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->leftptr);
    postorder(root->rightptr);
    cout << root->data << " ";
}

void buildFromLevelOrder(TreeNode *&root)
{
    queue<TreeNode *> q;
    cout << "Enter the data for root: ";
    int data;
    cin >> data;
    root = new TreeNode(data);
    q.push(root);

    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();

        cout << "Enter leftptr node for " << temp->data << " (-1 for no leftptr child): ";
        int leftdata;
        cin >> leftdata;

        if (leftdata != -1)
        {
            temp->leftptr = new TreeNode(leftdata);
            q.push(temp->leftptr);
        }

        cout << "Enter rightptr node for " << temp->data << " (-1 for no rightptr child): ";
        int rightdata;
        cin >> rightdata;

        if (rightdata != -1)
        {
            temp->rightptr = new TreeNode(rightdata);
            q.push(temp->rightptr);
        }
    }
}

int main()
{
    TreeNode *root = NULL;
    int choice;

    do
    {
        cout << "Enter your choice: " << endl;
        cout << "\n1. Build Binary Tree from Level Order" << endl;
        cout << "2. Inorder Traversal" << endl;
        cout << "3. Preorder Traversal" << endl;
        cout << "4. Postorder Traversal" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            buildFromLevelOrder(root);
            break;
        case 2:
            cout << "Inorder Traversal: ";
            inorder(root);
            cout << endl;
            break;
        case 3:
            cout << "Preorder Traversal: ";
            preorder(root);
            cout << endl;
            break;
        case 4:
            cout << "Postorder Traversal: ";
            postorder(root);
            cout << endl;
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 5);


    return 0;
}