/*                                            NOTES
1.)  Memory which is alocated dynamically is allocateed in the heap 
2.)  We use (new) keyword to create dynamic variables
3.)  Normal memory allocation is done in stack .. and the memory in stack is freed up automatically
     but in heap we have to delete (or) free up the memory space manually..
 */
#include<iostream>
using namespace std;

int main(){
    int* a = new int;   // creating a variable of int type and accessing it with help of an pointer 
    *a = 10;           // assining some value to the varible
    cout<<*a;
    // freeing up the memory of the variable created above
    delete a;
    // creating a array dynamically
    int n;
    cout<<"Enter n:: ";
    cin>>n;
    int* arr = new int[n];
    // taking input
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //freeing up the memory    
    delete[] arr;
    // Dynamic memory allocation of a 2D array
    int row;
    cout<<"Enter the total rows in 2d array ::";
    cin>>row;
    int col;
    cout<<"Enter the total cols in 2d array ::";
    cin>>col;
    // creating a 2D aray
    int** arr2D = new int*[row];
    for(int i = 0;i<row;i++){
        arr2D[i] = new int[col];
    }
    //taking input
    for(int i = 0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>arr2D[i][j];
        }
    }
    cout<<endl;
    //print the aray
    for(int i = 0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr2D[i][j]<<" ";
        }
        cout<<endl;
    }
    //NOw freeing up the space 
    for(int i = 0;i<row;i++){
        delete[] arr2D[i];      // freeing up the space of inside arays
    }
    delete[] arr2D;    // freeing up the main outer array

    // Here construct an dynamically allocated jagged array and perform input ouput operations on it
    int r;
    int c;
    cout<<"Enter the total rows :: ";
    cin>>r;
    int* size = new int[row] ;  // it will be helpful to store the sizes(total elements) in each row  
    
    int** jagged_arr = new int*[r];
    for(int i = 0;i<r;i++){
        cout<<"enter no. of element in "<<i<<" Row"<<endl;
        cin>>c;         // taking input the no. of elements in specific row.
        size[i] = c; // storing the no. of elements in a array of name (size)
        jagged_arr[i] = new int[c];    
    }
    //taking input
    for(int i = 0;i<r;i++){
        for(int j = 0;j<size[i];j++){
            cin>>jagged_arr[i][j];
        }
    }
    // printing the jagged array
    for(int i = 0;i<r;i++){
        for(int j = 0;j<size[i];j++){
            cout<<jagged_arr[i][j]<<" ";
        }
        cout<<endl;
    }
    // freeing up the space
    for(int i=0;i<r;i++){
        delete[] jagged_arr[i];
    }
    delete[] jagged_arr;
    
    

    return 0;
}