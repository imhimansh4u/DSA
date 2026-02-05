/*  TASK -->..    Print the Inorder Traversal of a Binary Tree without using Recursion or Stack (Use T.C. -> O(n) and space complexity of O(1))
 */
#include <iostream>
#include <vector>
using namespace std;
// Binary Tree Node Construction
class Node
{
public:
    Node *left;
    Node *right;
    int data;
    Node(int val)
    {
        left = NULL;
        right = NULL;
        data = val;
    }
};
// Now Morris Traversal(Getting Inorder Traversal of a tree using Morris Traversal )
vector<int> Morris(Node *&root)
{
    Node *curr = root;
    vector<int> ans;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            ans.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            Node *prev = curr->left;
            while (prev->right != NULL && prev->right != curr)
            {
                prev = prev->right;
            }
            if (prev->right == NULL)
            {
                prev->right = curr;
                curr = curr->left;
            }
            else
            { // This part means that whole right subtree of the Curr node has been visited so  move to the rightsubTree
                prev->right = NULL;
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return ans;
}
// Function to construct a tree
Node *buildtree(Node *&root)
{
    cout << "Enter the data:: ";
    int data;
    cin >> data;
    root = new Node(data);
    if (data == -1)
    { // assume that for data == -1 , it is showing NULL
        return NULL;
    }
    cout << "Enter the data to insert in left of " << data << endl;
    root->left = buildtree(root->left);
    cout << "Enter the data to insert in right of " << data << endl;
    root->right = buildtree(root->right);
    return root;
}

int main()
{
    Node *root = NULL;
    buildtree(root);
    vector<int> inorder;
    inorder = Morris(root);
    for (int i = 0; i < inorder.size(); i++)
    {
        cout << inorder[i] << " ";
    }
    return 0;
}
// 1 2 -1 3 -1 -1 4 -1 -1
