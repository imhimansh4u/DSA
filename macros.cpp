#include<iostream>
using namespace std;
/*
1.) In macro we do not have to define the data type 
2.) macro dosnt take ant extra memory in space
*/
#define pi 3.14     // This is called as macro 

int main(){
    int r;
    cin>>r;
    float area = (pi)*r*r;
    cout<<"The area of circle is :: "<<area<<endl;
    float circum = 2*(pi)*r;
    cout<<"The circumference of the circle is :: "<<circum;
    return 0;
}