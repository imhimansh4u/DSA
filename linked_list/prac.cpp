// // // #include<iostream>
// // // using namespace std;
// // // class node{
// // //     public:
// // //         int data;
// // //         node* next;
// // //         node(int val){        // constructor to create a new node.
// // //             this->data = val;
// // //             this->next = NULL;
// // //         }
// // // };
// // // // function to convert the array into linked list
// // // node* convert(int arr[],int n){
// // //     node* head = new node(arr[0]);
// // //     node* current = head;
// // //     for(int i=1;i<n;i++){
// // //         current ->next = new node(arr[i]);
// // //         current = current ->next;
// // //     }
// // //     return head;
// // // }
// // // // function to print the linked list
// // // void print(node* &head){
// // //     node* temp = head;
// // //     while(temp != NULL){            // traversing till the last node and printing it
// // //         cout<<temp->data<<" ";
// // //         temp = temp->next;
// // //     }
// // //     cout<<endl;
// // // }

// // // int main(){
// // //     int arr[5] = {1,2,3,4,5};
// // //     node* head = convert(arr,5);
// // //     print(head);
// // //     return 0;
// // // }
// // #include <iostream>

// // struct Node {
// //     int data;
// //     Node* next;
// // };

// // // Function to find the middle node
// // Node* findMiddle(Node* head) {
// //     if (head == NULL) return NULL; // Handle the empty list case

// //     Node* slow = head;
// //     Node* fast = head;

// //     while (fast != NULL && fast->next != NULL) {
// //         fast = fast->next->next;
// //         slow = slow->next;
// //     }

// //     // For even number of nodes, slow will point to the first middle node
// //     return slow; // slow points to the middle node (first middle for even)
// // }

// // // Function to create a new node
// // Node* createNode(int data) {
// //     Node* newNode = new Node();
// //     newNode->data = data;
// //     newNode->next = NULL;
// //     return newNode;
// // }

// // // Function to print the middle node's value
// // void printMiddle(Node* head) {
// //     Node* middleNode = findMiddle(head);
// //     if (middleNode) {
// //         std::cout << "Middle Node: " << middleNode->data << std::endl;
// //     } else {
// //         std::cout << "The list is empty." << std::endl;
// //     }
// // }

// // int main() {
// //     // Example for odd number of nodes
// //     Node* headOdd = createNode(1);
// //     headOdd->next = createNode(2);
// //     headOdd->next->next = createNode(3);
// //     headOdd->next->next->next = createNode(4);
// //     headOdd->next->next->next->next = createNode(5);
    
// //     std::cout << "For odd number of nodes:" << std::endl;
// //     printMiddle(headOdd); // Should return 3

// //     // Example for even number of nodes
// //     Node* headEven = createNode(1);
// //     headEven->next = createNode(2);
// //     headEven->next->next = createNode(3);
// //     headEven->next->next->next = createNode(4);
// //     headEven->next->next->next->next = createNode(5);
// //     headEven->next->next->next->next->next = createNode(6);
    
// //     std::cout << "For even number of nodes:" << std::endl;
// //     printMiddle(headEven); // Should return 3

// //     return 0;
// // }
// #include <iostream>

// struct Node {
//     int data;
//     Node* next;
// };

// // Function to find the middle node
// Node* findMiddle(Node* head) {
//     if (head == NULL) return NULL; // Handle the empty list case

//     Node* slow = head;
//     Node* fast = head;

//     // Move fast pointer two steps and slow pointer one step
//     while (fast != NULL && fast->next != NULL) {
//         fast = fast->next->next;
//         // Move slow one step only
//         slow = slow->next;
//     }

//     // If fast is NULL, we have an even number of nodes
//     // Slow is currently pointing to the second middle node
//     // We need to move slow one step back if we have even number of nodes
//     if (fast == NULL) {
//         Node* temp = head;
//         while (temp->next != slow) {
//             temp = temp->next;
//         }
//         return temp; // Return the first middle node
//     }

//     return slow; // Return the middle node for odd-length lists
// }

// // Function to create a new node
// Node* createNode(int data) {
//     Node* newNode = new Node();
//     newNode->data = data;
//     newNode->next = NULL;
//     return newNode;
// }

// // Function to print the middle node's value
// void printMiddle(Node* head) {
//     Node* middleNode = findMiddle(head);
//     if (middleNode) {
//         std::cout << "Middle Node: " << middleNode->data << std::endl;
//     } else {
//         std::cout << "The list is empty." << std::endl;
//     }
// }

// int main() {
//     // Example for odd number of nodes
//     Node* headOdd = createNode(1);
//     headOdd->next = createNode(2);
//     headOdd->next->next = createNode(3);
//     headOdd->next->next->next = createNode(4);
//     headOdd->next->next->next->next = createNode(5);
    
//     std::cout << "For odd number of nodes:" << std::endl;
//     printMiddle(headOdd); // Should return 3

//     // Example for even number of nodes
//     Node* headEven = createNode(1);
//     headEven->next = createNode(2);
//     headEven->next->next = createNode(3);
//     headEven->next->next->next = createNode(4);
//     headEven->next->next->next->next = createNode(5);
//     headEven->next->next->next->next->next = createNode(6);
    
//     std::cout << "For even number of nodes:" << std::endl;
//     printMiddle(headEven); // Should return 3

//     return 0;
// }
#include<iostream>
using namespace std;
//  creating a node
class Node{
    public:
        int data;
        Node* next;
        // constructor to initialise the values 
        Node(int val){
            this ->data;
            this->next = NULL;
        }
        // Destructor to delete 
        ~Node(){
            int val = this->data;
        }
        // function to find the length if the linked lsit 
        int length(Node* &head){
            int cnt = 0;
            Node* temp = head;
            while(temp!=NULL){
                cnt++;
                temp = temp->next;
            }
            return cnt;
        }
        // add a node in the starting of the linked list i.e.(at the head)
        void insertAthead(Node* &head,int val){
            Node* newnode = new Node(val);
            newnode->next = head;
            head = newnode;
        }
        // add a node in the end of the linked list(i.e. at the tail)
        void insertAtTail(Node* &head,int val){
            Node* newnode = new Node(val);
            Node* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next = NULL;
        }
        // Insert after a perticular postion
        void insertAtpos(Node* &head,int val,int pos){  // we have to insert at the new Node after a position p
            if(pos > length(head)+1 ){
                cout<<"Please enter a valid position";
            }
            else{
                int cnt = 1;
                Node* temp = head;
                Node* newnode = new Node(val);
                while(cnt!=pos){
                    temp = temp->next;
                    cnt++;
                }
                newnode->next = temp->next;
                temp->next = newnode;
            }
            
        }
};
int main(){
    return 0;
}