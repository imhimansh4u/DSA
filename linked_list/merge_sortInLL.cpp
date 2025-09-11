#include <iostream>
using namespace std;
//    Following is the representation of the Singly Linked List Node:

class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// This is helping function for merge function which is written after this
node *solve(node *first, node *second)
{
    if (first->next == NULL)
    {
        first->next = second;
        return first;
    }
    node *prev = first;
    node *t1 = prev->next;
    node *t2 = second;
    while (t1 != NULL && t2 != NULL)
    {
        node *forward = t2->next;
        if ((t2->data) >= (prev->data) && (t2->data) <= (t1->data))
        {
            t2->next = t1;
            prev->next = t2;
            // update the pointers
            t2 = forward;
            prev = prev->next;
        }
        else
        {
            prev = prev->next;
            t1 = t1->next;
            if (t1 == NULL)
            {
                prev->next = t2;
            }
        }
    }
    return first;
}
// function to merge two sorted LL
node *merge(node *first, node *second)
{
    if (first == NULL)
    {
        return second;
    }
    if (second == NULL)
    {
        return first;
    }
    if (first->data <= second->data)
    {
        return solve(first, second);
    }
    else
    {
        return solve(second, first);
    }
}
// function to find the mid element of an LL
node *findmid(node *head)
{
    node *slow = head;
    node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

node *mergeSort(node *head)
{
    // base case
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    // break your code into two halves after finding mid element
    node *mid = findmid(head);
    // left part of the LL.
    node *left = head;
    // right part of the LL.
    node *right = mid->next;
    // to make sure that right part end after mid
    mid->next = NULL;
    // recursive calls
    left = mergeSort(left);   // sort the left part
    right = mergeSort(right); // sort the right part
    // now merge them
    return merge(left, right);
}