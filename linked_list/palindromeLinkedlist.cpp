#include<iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return true;
        }
        //firstly find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        // Now reverse the second half.. here slow will point the middle of the linked list
        ListNode* prev = NULL;
        ListNode* curr = slow;
        ListNode* temp;
        while(curr){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        // Now prev will point to the head of the reversed linked list (the second half)
        // Now compare  the two halves
        ListNode* first = head;
        ListNode* second = prev;
        while(second){
            if(first->val != second->val)
                return false;
            first = first->next;
            second = second->next;
        }
        return true;
    }
};