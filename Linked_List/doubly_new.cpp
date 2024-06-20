#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Define a Node class for doubly linked list
class Node {
public:
    int data;   
    Node* next;     
    Node* back;     

    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

// Function to convert an array to a doubly linked list
Node* convertArr2DLL(vector<int> arr) {
    Node* head = new Node(arr[0]);
    Node* prev = head;            

    for (vector<int>::size_type i = 1; i < arr.size(); i++) {
        // Create a new node with data from the array and set its 'back' pointer to the previous node
        Node* temp = new Node(arr[i], nullptr, prev);
        // Update the 'next' pointer of the previous node to point to the new node
        prev->next = temp; 
         // Move 'prev' to the newly created node for the next iteration
        prev = temp;       
    }
    // Return the head of the doubly linked list
    return head;  
}

// Function to print the elements of the doubly linked list
void print(Node* head) {
    while (head != nullptr) {
        // Print the data in the tail node
        cout << head->data << " ";  
         // Move to the next node
        head = head->next;         
    }
}

 


// Function to insert a new node with value 'k' at the end of the doubly linked list
Node* insertAtTail(Node* head, int k) {
    // Create a new node with data 'k'
    Node* newNode = new Node(k);

    // If the doubly linked list is empty, set 'head' to the new node
    if (head == nullptr) {
        return newNode;
    }

    // Traverse to the end of the doubly linked list
    Node* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
 
    // Connect the new node to the last node in the list
    tail->next = newNode;
    newNode->back = tail;

    return head;
}

Node* insert_ll(Node* head, Node* ins, int pos){
    
    Node* temp=head;
    if(pos==0){

        ins->next=temp;
        head->back=ins;
        head=ins;

        return head;
    }
    int i=0;
    while(temp!=NULL && i<=pos-1 ){
        temp=temp->next;
        i++;
    }

    Node* temp1=temp->next;

    temp->next=ins;
    ins->back=temp;
    ins->next=temp1;

     // Update the 'back' pointer of the node after the inserted node

    if (temp1 != nullptr) {
        temp1->back = ins;
    }    
    return head;
}




int main() {
    vector<int> arr = {12, 5, 8, 7, 4};
    Node* head = convertArr2DLL(arr);

cout << "Doubly Linked List Initially: " << endl;
    print(head);

cout<< "Input the position and data to be inserted: " <<endl;
int d=0,pos=0;
cin>>d>>pos;
Node* ins=new Node(d);
Node* temp=insert_ll(head,ins,pos);
print(temp);

    cout << endl << "Doubly Linked List After Inserting at the tail with value 10: " << endl;
     // Insert a node with value 10 at the end
    head = insertAtTail(head, 10);
    print(head);

    return 0;
}