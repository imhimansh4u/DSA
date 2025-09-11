#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int val){
            this->data = val;
            this->left = NULL;
            this->right = NULL;
        }
};
/*(TASK - 1)..........TOP VIEW
You are given a binary tree, and your task is to return its top view. The top view of a binary tree is the set of nodes visible 
when the tree is viewed from the top.

Note: 

1.Return the nodes from the leftmost node to the rightmost node.
2.If two nodes are at the same position (horizontal distance) and are outside the shadow of the tree, 
consider the leftmost node only. 

*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        vector<int> ans;
        map<int,int> mp;  // here HD->top value at that HD (hr HD pe hm uska top first element dekh lenge bs ar store kr lege)....
        queue<pair<Node* , int>> q;  // here Node and HD respectively
        q.push(make_pair(root,0));
        while(!q.empty()){
            pair<Node* , int> temp = q.front();
            q.pop();
            Node* frontNode = temp.first;
            int HD = temp.second;
            if(mp[HD] ==  NULL){
                mp[HD] = frontNode->data;
            }
            if(frontNode->left){
                q.push(make_pair(frontNode->left,HD-1));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right,HD+1));
            }
        }
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};
/*  TASK 2->> BOTTOM VIEW......>>>>>
Given a binary tree, return an array where elements represent the bottom view of the binary tree from left to right.

Note: If there are multiple bottom-most nodes for a horizontal distance from the root, then the latter one in the level traversal
is considered. For example, in the below diagram, 3 and 4 are both the bottommost nodes at a horizontal distance of 0, here 4 will
be considered.

                      20
                    /    \
                  8       22
                /   \     /   \
              5      3 4     25
                     /    \      
                 10       14

For the above tree, the output should be 5 10 4 14 25.*/
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;   // To store our main answer        
        map<int,int> mp;   // outer int for HD and inner int for answer at that place 
        queue<pair<Node*,int>> q;
        q.push(make_pair(root,0));     // since for root , the value of HD is 0
        while(!q.empty()){
            pair<Node*,int> temp = q.front();
            q.pop();
            Node* frontNode = temp.first;
            int HD = temp.second;
            mp[HD] = frontNode->data;
            if(frontNode->left){
                q.push(make_pair(frontNode->left,HD-1));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right,HD+1));
            }
        }
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};
/* TASK 3->> LEFT VIEW
You are given the root of a binary tree. Your task is to return the left view of the binary tree. The left view of a binary tree is
the set of nodes visible when the tree is viewed from the left side. If the tree is empty, return an empty list.
*/
class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        
        map<int,int> mp; // here relation is for (level->ans(at that level))
        queue<pair<Node*,int>> q; // here int is for level again 
        q.push(make_pair(root,0)) ;  // since for root the level is 0...
        while(!q.empty()){
            pair<Node*,int> temp = q.front();
            q.pop();
            Node* frontNode = temp.first;
            int level = temp.second;
            /*NOTE AND STUDY POINT
            The find() method of a std::map is used to search for a key in the map.
                It takes a key as an argument and returns an iterator:
                If the key exists in the map, the iterator points to the key-value pair in the map.
                If the key does not exist, the iterator returned points to mp.end(), which is a special iterator representing "one past the last element" in the map.
            */
            if(mp.find(level) == mp.end()){   // it means ki kisi perticular level jo bhi hme 
                                  // first element milega , use store kr lena hai 
                mp[level] = frontNode->data;
            }
            if(frontNode->left){
                q.push(make_pair(frontNode->left,level+1));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right,level+1));
            }
        }
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};
/* RIGHT VIEW....>>>>
Given a Binary Tree, Your task is to return the values visible from Right view of it.

Right view of a Binary Tree is set of nodes visible when tree is viewed from right side.
*/
class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your Code here
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        
        map<int,int> mp; // here relation is for (level->ans(at that level))
        queue<pair<Node*,int>> q; // here int is for level again 
        q.push(make_pair(root,0)) ;  // since for root the level is 0...
        while(!q.empty()){
            pair<Node*,int> temp = q.front();
            q.pop();
            Node* frontNode = temp.first;
            int level = temp.second;
            mp[level] = frontNode->data;  // YE us level pe present last element ko insert kr dega
                                            // joki rightmost element hoga
            
            if(frontNode->left){
                q.push(make_pair(frontNode->left,level+1));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right,level+1));
            }
        }
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};
int main(){

    return 0;
}