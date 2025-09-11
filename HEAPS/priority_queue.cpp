#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // To create a maxHeap
    priority_queue<int> maxHeap;
    maxHeap.push(3);
    maxHeap.push(8);
    maxHeap.push(1);
    maxHeap.push(9);
    maxHeap.push(6);
    maxHeap.push(4);
    while (!maxHeap.empty())
    {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    cout << endl;
    // Creating a minHeap using priority queue
    // priority queue can also act as a Minheap , we have to just provide some extra arguments in the constructor to act as a min heap
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(3);
    minHeap.push(8);
    minHeap.push(1);
    minHeap.push(9);
    minHeap.push(6);
    minHeap.push(4);
    while (!minHeap.empty())
    {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    return 0;
}

// T.C. of push and pop is O(logN)