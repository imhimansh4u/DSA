#include<iostream>
#include<set>
#include<unordered_set>
using namespace std;
void print(set<string> s){
    // how to traverse and print through help of loops
    for(auto i: s){             // print the elements in lexicographical order  (sorted)
        cout<<i<<" ";
    }
    cout<<endl<<"now printing with help of iterators"<<endl;
    set<string> :: iterator it = s.begin();
    while(it != s.end()){
        cout<<*it<<" ";
        it++;
    }
}

int main(){
    set<string> s;                        // It stores the elements in sorted order  , thereforre the elements will be stored in lexicohraphical order
    // insertion process                  //T.C.-> is O(logn)
    s.insert("himanshu");
    s.insert("is");
    s.insert("a");
    s.insert("a");                 //set only contains unique elements , therefore this string will not be added in the set 
    s.insert("good");
    s.insert("boy");
    print(s);
    //To access any element through iterator
    auto itt = s.find("a");        // if this element is not present in the set , then the iterator will point to the end of the set .. 
    cout<<endl<<*itt<<endl;
    if(itt != s.end()){
        cout<<"Present";
    }
    s.insert("Heeehe");
    auto it4 = s.find("boy");
    s.erase(it4);   // erase function will delete that element from the set  (here we are giving iterator inside the erase function)
    s.erase("good");  // it can also direct take entry of the elements
    print(s);
    return 0;
}
