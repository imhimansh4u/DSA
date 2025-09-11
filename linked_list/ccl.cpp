#include <iostream>
using namespace std;

class node {
public:
    int data;
    int key; // key is unique for each element in the linked list
    node* next;

    node(int val, int k) {
        this->data = val;
        this->next = NULL;
        this->key = k;
    }
};

// Function to check if the circular linked list is empty
bool isempty(node* tail) {
    return tail == NULL;
}

// Function to insert an element after a node with a particular key
void insert(node*& tail, int data, int key, int insert_after_key) {
    node* new_node = new node(data, key);
    
    if (isempty(tail)) {
        // If the list is empty
        tail = new_node;
        new_node->next = new_node; // Points to itself
    } else {
        node* temp = tail->next; // Start from head
        bool found = false;

        // Find the node with insert_after_key
        do {
            if (temp->key == insert_after_key) {
                found = true;
                break;
            }
            temp = temp->next;
        } while (temp != tail->next);

        if (found) {
            new_node->next = temp->next;
            temp->next = new_node;
            // If we're inserting after the tail, update tail
            if (temp == tail) {
                tail = new_node;
            }
        } else {
            cout << "Node with key " << insert_after_key << " not found!" << endl;
            delete new_node; // Free the allocated memory
        }
    }
}

// Function to print the circular linked list
void print(node* tail) {
    if (isempty(tail)) {
        cout << "Elements hi nahi hai chutiya !! " << endl;
        return;
    }

    node* temp = tail->next; // Start from the head
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next);
    cout << endl;
}

int main() {
    node* tail = NULL; // Initialize tail as NULL

    insert(tail, 10, 1, 20); // Attempt to insert when list is empty
    insert(tail, 20, 2, 1); // Insert after 1
    insert(tail, 30, 3, 2); // Insert after 2
    insert(tail, 40, 4, 3); // Insert after 3
    insert(tail, 50, 5, 4); // Insert after 4
    insert(tail, 60, 6, 5); // Insert after 5

    print(tail); // Print the list

    return 0;
}
