#include <iostream>
using namespace std;
void search_key(int arr[][4], int key)
{
    bool keyfound = false;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (arr[i][j] == key)
            {
                keyfound = true;
                cout << "key found at position :: (" << i << "," << j << ")" << endl;
                break;
            }
        }
    }
    if(!keyfound){
        cout<<"key is not present in the matrix :: "<<endl;
    }
}

int main()
{
    int row = 3;
    int col = 4;
    int key;
    int max_sum = 0; // helps to find the largest row wise sum
    int arr[row][4];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << "enter the key to search" << endl;
    cin >> key;
    search_key(arr, key);
    cout << endl;
    // below line of code print the row wise sum and aslo find the largest row wise sum ....
    for (int i = 0; i < row; i++)
    {
        cout << "the sum for " << i << " row is::" << endl;
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum += arr[i][j];
        }
        cout << sum;
        cout << endl;
        if (sum > max_sum)
        {
            max_sum = sum;
        }
    }
    cout << endl;
    cout << "The largest row wise sum is::: " << max_sum;
    return 0;
}