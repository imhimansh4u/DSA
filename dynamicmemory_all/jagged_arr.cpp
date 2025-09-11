#include<iostream>
using namespace std;

int main(){
    // Here construct an dynamically allocated jagged array and perform input ouput operations on it

    int r;
    int c;
    cout<<"Enter the total rows :: ";
    cin>>r;
    int* size = new int[r] ;  // it will be helpful to store the sizes(total elements) in each row  
    
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
    cout<<endl;
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

// Below is the program to implemnt jagged array using static array
// C++ Program to implement Jagged Array 
// 1st way: static arrays 
/*
#include <iostream> 
using namespace std; 

int main() 
{ 
	// create 3 row arrays having different sizes 
	// ( no ofcolumns) 
	int row1[] = { 1, 2, 3, 4 }; 
	int row2[] = { 5, 6 }; 
	int row3[] = { 7, 8, 9 }; 

	// storing base address of each row array 
	int* jagged[] = { row1, row2, row3 }; 

	int sizes[] = { 4, 2, 3 }; 

	cout << "elements in matrix form as follow" << endl; 
	for (int i = 0; i < 3; i++) { 

		// getting current(ith) row 
		int* ptr = jagged[i]; 

		for (int j = 0; j < sizes[i]; j++) { 
			// for ith row having sizes[i] no. of 
			// columns 

			cout << *(ptr + j) << " "; 
			// *ptr have base address 
			// adding j means access jth 
			// element for particular(ith) row 
		} 
		cout << endl; 
	} 

	return 0; 
}
*/