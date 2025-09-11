// TASK ->
/*Given two numbers, num1, and num2, represented by linked lists. The task is to return the head of the linked list representing the sum
 of these two numbers.
For example, the number 190 will be represented by the linked list, 1->9->0->null, similarly 25 by 2->5->null. Sum of these two numbers
is 190 + 25 = 215, which will be represented by 2->1->5->null. You are required to return the head of the linked list 2->1->5->null.
*/
#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
class Solution
{
public:
    // function to insert at tail
    void insertattail(Node *&head, Node *&tail, int val)
    {
        Node *temp = new Node(val);
        // check if the head is NULL
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        // other conditions
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    // function to add two linked list
    Node *add(Node *num1, Node *num2)
    {
        Node *head = NULL; // inintailly head and tail of the answer LInked list is NULL
        Node *tail = NULL;
        int carry = 0;
        Node *t1 = num1;
        Node *t2 = num2;
        while (t1 != NULL || t2 != NULL || carry != 0)
        {   // This condition will check for three things and will run until one all of them
            // fails to pass the condition
            int val1 = 0;
            if (t1 != NULL)
            {
                val1 = t1->data;
            }
            int val2 = 0;
            if (t2 != NULL)
            {
                val2 = t2->data;
            }
            int sum = val1 + val2 + carry; // sum
            int digit = sum % 10;          // digit which is to be added in the linked list
            insertattail(head, tail, digit);  //  link the digit to our required linked list
            // now calculate the carry
            carry = sum / 10;
            // to increase the t1
            if (t1 != NULL)
            {
                t1 = t1->next;
            }
            if (t2 != NULL)
            {
                t2 = t2->next;
            }
        }
        return head;
    }
    // function to reverse two lists
    Node *reverseit(Node *head)
    {
        Node *prev = NULL;
        Node *curr = head;
        while (curr != NULL)
        {
            Node *forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    // Function to add two numbers represented by linked list.
    Node *addTwoLists(Node *num1, Node *num2)
    {
        // code here
        // step->1)) reverse the two LL
        num1 = reverseit(num1);
        num2 = reverseit(num2);
        // step -2)  add
        Node *ans = add(num1, num2);
        // step 3) reverse the answer linked list
        ans = reverseit(ans);
        return ans;
    }
};