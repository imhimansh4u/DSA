#include<iostream>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;  // marks that this is the end of any Word or not

    TrieNode(char ch){
        this->data = ch;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

class Trie{
    public:

    TrieNode* root = new TrieNode('\0');
    void TrieBuilder(TrieNode* root,string word){
        if(word.size() == 0){
            root->isTerminal = true;
            return;
        }
        TrieNode* child;
        int index = word[0]-'a';  // I am inserting Everything in small Letters
        if(root->children[index] != NULL){  // It means that letter is present on required place
            child = root->children[index];
        }else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        TrieBuilder(child,word.substr(1));
    }
    void insertWordInTrie(string word){
        TrieBuilder(root,word);
    }
    bool searchUtil(TrieNode* root,string word){
        if(word.length() == 0){
            return root->isTerminal; //  if the current is terminal then yes that word is present
        }
        int index = word[0]-'a';
        TrieNode* child;
        if(root->children[index] != NULL){
            child = root->children[index];
        }else{
            return false;
        }
        return searchUtil(child,word.substr(1));
    }
    bool searchWordInTrie(string word){
        return searchUtil(root,word);
    }
    // Now Functionality To Delete a word from a Trie 
    /*This is a Little Complex task bcs we have to do mainly Three things
        1. mark the isTerminal to be false
        2. Delete the Nodes that are only used by the word to be Deleted , For this Make Sure->>
            1.Those Nodes are Not isTerminal==True &&
            2.those nodes doesnt have any Children

    */
  bool deleteUtil(TrieNode* root, string word) {
    if (word.length() == 0) {
        root->isTerminal = false;

        for (int i = 0; i < 26; i++) {
            if (root->children[i] != NULL)
                return false;
        }

        return true;
    }

    int idx = word[0] - 'a';
    TrieNode* child = root->children[idx];

    if (child == NULL)
        return false;

    bool shouldDeleteChild = deleteUtil(child, word.substr(1));

    if (shouldDeleteChild) {
        delete child;
        root->children[idx] = NULL;
    }

    if (root->isTerminal)
        return false;

    for (int i = 0; i < 26; i++) {
        if (root->children[i] != NULL)
            return false;
    }

    return true;
}
   bool deleteWordInTrie(string word){
    // Firstly Make sure that Word is Present in the Trie
        return deleteUtil(root,word);
   }
};

int main(){
    Trie *t = new Trie();
    t->insertWordInTrie("himanshu");         // Please keep in mind to insert only capital letters 
    t->insertWordInTrie("arm");
    t->insertWordInTrie("art");
    t->insertWordInTrie("army");
    bool ans = t->searchWordInTrie("arm");
    cout<<ans;
    return 0;

}

// T.C. for insertion is  O(L) //  Word Length
// T.C. for Searching is  O(L) //  Word Length
// T.C. for deletion is  O(L) //  Word Length