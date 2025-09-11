#include <iostream>
#include <map>
using namespace std;
class node
{
public:
    int data;
    node *prev;
    node *next;
    // constructor to create a new node and inititalise it.
    node(int val)
    {
        this->data = val;
        this->prev = NULL;
        this->next = NULL;
    }
};
// function to print DLL
void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
// function to find the length of a DLL(means total nodes present in it)
int length(node *head)
{
    int count = 0;
    node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
// function to insert at head(i.e. at starting postion)
void insertathead(node *&head, int data)
{
    node *temp = new node(data);
    temp->next = head;
    if (head != NULL)
    {                      // Check if the list is not empty
        head->prev = temp; // Link the old head to the new node
    }
    head = temp; // Update head to the new node
}
// fundtion to insert a node at the end of the DLL
void insertatend(node *&head, int data)
{
    node *fresh = new node(data);
    if (head == NULL)
    {                 // If the list is empty
        head = fresh; // New node becomes the head
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    { // Correct condition for traversal
        temp = temp->next;
    }
    temp->next = fresh; // Link the last node to the new node
    fresh->prev = temp; // Link the new node back to the last node
}
// function to insert at a particuar position
void insertinmid(node *&head, int data, int position)
{
    if (position == 1)
    {
        insertathead(head, data);
        return;
    }
    else
    {
        node *temp = head;
        for (int i = 1; i < (position - 1); i++)
        {
            temp = temp->next;
        }
        node *curr = new node(data);
        curr->prev = temp;
        curr->next = temp->next;
        temp->next = curr;
    }
}
void deletenode(node *&head, int pos)
{
    node *temp = head;
    if (pos == 1)
    {
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        temp->next = NULL;
        temp->prev = NULL;
        delete temp;
    }
}
// node * removeDuplicates(node* &head)
// {
//     map<int,bool> mp;
//     if(head == NULL){
//         return NULL;
//     }
//     else if(head->next == NULL){
//         return head;
//     }
//     node* temp = head;
//     while(temp!=NULL){
//         if(mp[temp->data]){
//             node* forward = temp->next;
//             temp->prev->next = temp->next;
//             if(temp->next){
//                 temp->next->prev = temp->prev;
//             }
//             node* todelete = temp;
//             temp = todelete->next;
//             delete todelete;
//         }
//         else{
//             mp[temp->data] = true;
//             temp = temp->next;
//         }

//     }
//     return head;
// }
node* removeDuplicates(node*& head) {
    if (head == NULL) {
        return NULL;
    }

    node* temp = head;

    while (temp != NULL) {
        node* current = temp->next;
        node* prev = temp;

        while (current != NULL) {
            if (current->data == temp->data) {
                // Duplicate found, adjust pointers
                if (current->next) {
                    current->next->prev = current->prev;
                }
                prev->next = current->next;
                delete current; // Free the memory
                current = prev->next; // Move to the next node
            } else {
                prev = current;
                current = current->next;
            }
        }

        temp = temp->next; // Move to the next unique node
    }

    return head;
}


int main()
{
    node *node1 = new node(10); // new node created dynamically (means node memory stored in heap
                                //  and accese through pointer)
    node *head = node1;
    print(head);
    insertathead(head, 20);
    insertathead(head, 30);
    print(head);
    insertatend(head, 40);
    insertatend(head, 89);
    print(head);
    insertinmid(head, 50, 3);
    print(head);
    insertinmid(head, 50, 3);
    print(head);
    insertinmid(head, 50, 3);
    print(head);
    cout << "After removal of duplicates" << endl;
    removeDuplicates(head);
    print(head);
    return 0;
}