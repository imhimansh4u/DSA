#include<iostream>
using namespace std;
class TrieNode{
    public:
        char data;
        TrieNode* children[26];          // Here each index is associated with a capital alphabetical letter here like 0->A,1->B .... and more
        bool isTerminal;

        TrieNode(char ch){
            data = ch;
            for(int i = 0;i<26;i++){
                children[i] = NULL;
            }
            isTerminal = false;
        }
};
class Trie{
    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode('\0');    // initialising root with NULL character
    }
    // Inserting new word 
    void InsertUtil(TrieNode* root , string word){
        // base case
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }
        // Assumption - > here we are assuming that all the words are in capital letter.
        int index = word[0]-'A';
        TrieNode* child;
        if(root->children[index] != NULL){    // if present 
            child = root->children[index];
        }
        // if absent
        else{   
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        // Recursion
        InsertUtil(child,word.substr(1));
    }
    void Insertword(string word){
        InsertUtil(root,word);
    }
    // searching for a new word
    bool SearchUtil(TrieNode* root, string word){
        // base case
        if(word.length() == 0){
            return root->isTerminal;               // because the ending letter or node must be terminal node for the word to be present 
        }
        TrieNode* child;
        int index = word[0]-'A' ;         // here we are assuming that all the letters in the word are present in capital letter
        // below means that the letter is present
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        // if the letter is not present it means the whole word is not present  
        else{
            return false;
        }
        // recursion
        return SearchUtil(child,word.substr(1));
    }
    bool SearchWord(string word){
        return SearchUtil(root,word);
    }
    // Removing any word // here the simple logic is to remove only the isTerminal to false  ..
    void RemoveUtil(TrieNode* root,string word){
        // base case
        if(word.length() == 0){
            root->isTerminal = false;
            cout<<"Word removed succesfully"<<endl;
            return;
        }
        TrieNode* child;
        int index = word[0] - 'A';
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            cout<<"The Word is Already not present";
            return;
        }
        return RemoveUtil(child,word.substr(1));
    }
    void RemoveWord(string word){
        return RemoveUtil(root,word);
    }

};

int main(){
    Trie *t = new Trie();
    t->Insertword("HIMANSHU");         // Please keep in mind to insert only capital letters 
    t->Insertword("ARM");
    t->Insertword("ART");
    t->Insertword("ARMY");
    cout<<"Present or not :: "<<t->SearchWord("HIMANSHU")<<endl;
    cout<<"Present or not :: "<<t->SearchWord("ARM")<<endl;
    t->RemoveWord("ARM");
    cout<<"Present or not :: "<<t->SearchWord("ARM")<<endl;
    return 0;
}