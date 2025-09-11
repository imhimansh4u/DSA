#include <iostream>
#include <queue>
using namespace std;

class node
{ // Node for a tree
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
node *buildtree(node *root)
{
    cout << "Enter the data:: ";
    int data;
    cin >> data;
    root = new node(data);
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
void LevelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL); // NULL will help us to understand that when we have to move to the next level ( It is separator ) ..
                  // here after root level 0 has ended , so added the separator   ........
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // it means that purana level complete traverse ho chuka hai
            cout << endl;
            if (!q.empty())
            {
                // it means queue has still some child nodes
                q.push(NULL); // separator added after the child node
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void InOrderTraversal(node *root)
{ // LNR
    // base case
    if (root == NULL)
    {
        return;
    }

    InOrderTraversal(root->left);
    cout << root->data << " ";
    InOrderTraversal(root->right);
}

void PreOrderTraversal(node *root)
{ // NLR
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}

void PostOrderTraversal(node *root)
{ // LRN
    if (root == NULL)
    {
        return;
    }
    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout << root->data << " ";
}

// Build a tree from levelorder traversal
node *BuildFromlevelOrder(node *root)
{
    queue<node *> q;
    int data;
    cout << "Enter data for root ::" << endl;
    cin >> data;
    root = new node(data);
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << "Enter left node for ::" << temp->data << endl;
        int LeftData;
        cin >> LeftData;
        if (LeftData != -1)
        {
            temp->left = new node(LeftData);
            q.push(temp->left);
        }

        cout << "Enter right node for ::" << temp->data << endl;
        int RightData;
        cin >> RightData;

        if (RightData != -1)
        {
            temp->right = new node(RightData);
            q.push(temp->right);
        }
    }
    return root;
}
// Function to return the height of a tree (is function ko copy pe dry run kr lena sb smjh me aa jaega)
int height(node* root)
{
    // code here    
    if (root == NULL)
    {
        return -1;
    }
    int lefth = height(root->left);   // for calculation of height in the left side
    int righth = height(root->right); // for calculation of height in the right side
    return max(lefth, righth) + 1;
}

int main()
{
    node *root = NULL;
    // root = buildtree(root);           // normal approach
    root = BuildFromlevelOrder(root);
    cout << " Level order traversal is :: " << endl;
    LevelOrderTraversal(root);
    cout << endl
         << "Inorder Traversal is :: " << endl;
    InOrderTraversal(root);
    cout << endl
         << "Preorder Traversal is :: " << endl;
    PreOrderTraversal(root);
    cout << endl
         << "Postorder Traversal is :: " << endl;
    PostOrderTraversal(root);
    int h;
    h = height(root);
    cout<<endl<<"Height of the tree is :: "<<h<<endl; 
    return 0;
}
// 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 -1    -->> dataset for normal building tree (example)
// 1 2 3 4 5 6 -1 -1 -1 -1 -1 -1 -1    -->> dataset for buildfromlevelorder (example)
