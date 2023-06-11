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
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr = head;

    // create separate list 0s, 1s and 2s
    while (curr != NULL) {
        int value = curr->data;

        if (value == 0) {
            insertAtTail(zeroTail, curr);
        }
        else if (value == 1) {
            insertAtTail(oneTail, curr);
        }
        else if (value == 2) {
            insertAtTail(twoTail, curr);
        }
        curr = curr->next;
    }

    // merge 3 sublists

    // 1s list not empty
    if (oneHead->next != NULL) {
        zeroTail->next = oneHead->next;
    }
    else {
        // 1s list -> empty
        zeroTail->next = twoHead->next;
    }

    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    // setup head
    head = zeroHead->next;

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
