#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &arr, int s, int e, int mid)
{
    int n1 = mid - s + 1;
    int n2 = e - mid;
    vector<int> arr1(n1);
    vector<int> arr2(n2);
    // left part copy karo
    //  k is the index to use in the main array
    for (int i = 0; i < n1; i++)
    {
        arr1[i] = arr[s + i];
    }
    // right part copy karo

    for (int i = 0; i < n2; i++)
    {
        arr2[i] = arr[mid + 1 + i];
    }
    // merge karo
    int i1 = 0; // using double pointer
    int i2 = 0;
    int k = s;
    while (i1 < n1 && i2 < n2)
    {
        if (arr1[i1] < arr2[i2])
        {
            arr[k] = arr1[i1];
            i1++;
            k++;
        }
        else
        {
            arr[k] = arr2[i2];
            i2++;
            k++;
        }
    }
    while (i1 < n1)
    {
        arr[k++] = arr1[i1++];
    }
    while (i2 < n2)
    {
        arr[k++] = arr2[i2++];
    }
}
void sorting(vector<int> &arr, int s, int e)
{
    int mid = s + (e - s) / 2;
    // base case
    if (s >= e)
    {
        return;
    }
    // sort left part
    sorting(arr, s, mid);
    // sort right part
    sorting(arr, mid + 1, e);
    // merge
    merge(arr, s, e, mid);
}
void mergeSort(vector<int> &arr, int n)
{
    int s = 0;
    int e = n - 1;
    sorting(arr, s, e);
}
int main()
{
    int n;
    cout << "Enter total no. of elements in the arary ::";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements in the array :: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    mergeSort(arr, n);
    cout << "The sorted array is ::" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}

/****
 * Final Table
Case	Time Complexity
Best	O(n log n)
Average	O(n log n)
Worst	O(n log n)
 */