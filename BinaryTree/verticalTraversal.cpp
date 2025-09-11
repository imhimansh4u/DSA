/*Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
If there are multiple nodes passing through a vertical line, then they should be printed as they appear in 
level order traversal of the tree.
*/
#include<iostream>
#include<map>
#include<queue>
#include<vector>

using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
};
vector<int> VerticalTraversal(Node* root){
    vector<int> ans;  // to store the main answer and return it ....
    map<int,map<int,vector<int>>> mp;  //  HD->level->(vector of Nodes data)    // storage information   ....
    queue<pair<Node*,pair<int,int>>> q;   // here the inner pair<int,int> contains data about Horizontal distance and level respectively...
    if(root == NULL){
        return ans;
    }
    q.push(make_pair(root,make_pair(0,0))); // for the root element both HD and level are 0
    while(!q.empty()){
        pair<Node*,pair<int,int>> temp = q.front();
        q.pop();
        Node* frontNode = temp.first ;
        int HD = temp.second.first ;
        int level = temp.second.second ;
        mp[HD][level].push_back(frontNode->data);
        if(frontNode->left){
            q.push(make_pair(frontNode->left,make_pair(HD-1,level+1)));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right,make_pair(HD+1,level+1)));
        }
    }
    for(auto i:mp){
        for(auto j: i.second){
            for(auto k : j.second ){
                ans.push_back(k);
            }
        }
    }
    return ans;
}
int main(){

    return 0;
}

/*NOTES--))) 

Here map<int,pair<int,vector<>>>    ........

In this the first (int) is for Horizontal distance (HD)  and second inner int is for level...
So, a quetion may arise that why we have to manage level also..
This is because , in question we have given that if two or more elements are present at the same level then we have to print them
in the order of their level order travesal   ..
*/