#include <iostream>

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtTail(Node* &tail, Node* curr) {
    tail->next = curr;
    tail = curr;
}

Node* sortList(Node* head)
{
    Node* zeroHead = new Node(-1);  //points to dummy node now
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr = head;   //traverse the current list of 0,1,2

    // create separate list 0s, 1s and 2s
    while (curr != NULL) {  //till end of it
        int value = curr->data;

        if (value == 0) {
            insertAtTail(zeroTail, curr);  //add element in 0 specific list
        }
        else if (value == 1) {
            insertAtTail(oneTail, curr);
        }
        else if (value == 2) {
            insertAtTail(twoTail, curr);
        }
        curr = curr->next;
    }   //till here all lists are created

    // merge 3 sublists

    // 1s list not empty
    if (oneHead->next != NULL) {    //agar 1's wali list khaali nhi hai, toh merge them
        zeroTail->next = oneHead->next;  //zero list ki tail pe 1's list ka head laga do
    }
    else {
        // 1s list -> empty
        zeroTail->next = twoHead->next;  //agar khaali hai toh 0 ko seedha 2 se join krdo
    }

    oneTail->next = twoHead->next;     //1 ki tail pe 2 ki list laga do
    twoTail->next = NULL;       //point 2's tail to null

    // setup head
    head = zeroHead->next;  //0 ki dummy ka next is head

    // delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main() {
    // Creating a sample linked list
    Node* head = new Node(1);
    head->next = new Node(0);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(2);

    std::cout << "Original List: ";
    printList(head);

    Node* sortedHead = sortList(head);

    std::cout << "Sorted List: ";
    printList(sortedHead);

    // Clean up the memory
    Node* temp = sortedHead;
    while (temp != NULL) {
        Node* current = temp;
        temp = temp->next;
        delete current;
    }

    return 0;
}
