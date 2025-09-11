#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
    // creation done
    unordered_map<string , int> ump;
    // insertion process
    pair<string,int> p1;
    p1 = make_pair("Himanshu",20);
    ump.insert(p1);
    pair<string,int> p2("deepu",22);
    ump.insert(p2);
    // 3rd way of insertion
    ump["laddoo"] = 10;
    // finding  or searching
    cout<<"value at Himanshu "<<ump["Himanshu"]<<endl;
    cout<<"value at deepu "<<ump.at("deepu")<<endl;
    //koi aisa key jo (ump) me present hi na hoga , usko access krne ki kosis krenge  to wo zero se initialise kr dega
    
    cout<<"Value at unknown "<<ump["unknown"]<<endl;
    //size
    cout<<"Size of hashmap "<<ump.size()<<endl;
    
    // to check presence of any key
    cout<<ump.count("bro")<<endl; // it will give 0 when the key is not present 
    cout<<ump.count("Himanshu")<<endl;  // it will give 1 when the key is present 
    // how to access all the elements in the ump(unorederd map)
    for(auto i:ump){
        cout<<i.first << " " <<i .second<<endl;
    }
    // using iterators 
    unordered_map<string,int> :: iterator it = ump.begin();

    cout<<"Iterating the whole unordered map using iterators"<<endl;
    while(it != ump.end()){
        cout<<it->first <<" "<<it->second <<endl;
        it++;  // it means increase the iterator
    }
    unordered_map<string,int> :: iterator it2 = ump.find("Himanshu");
    // OR , shortcut is
    auto it3 = ump.find("deepu");  // If this key is present in the map , then (itt will point to that key , otherwise ,(itt) will point to the end of map)
    if(it2 != ump.end()){
        cout<<"present";
    }
    return 0;
}

