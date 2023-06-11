#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* bottom;
    
    Node(int val) {
        data = val;
        next = nullptr;
        bottom = nullptr;
    }
};

Node* mergeTwoLists(Node* a, Node* b) {
    Node* temp = new Node(0);
    Node* res = temp;

    while (a != nullptr && b != nullptr) {
        if (a->data < b->data) {
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        } else {
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
    }

    if (a)
        temp->bottom = a;
    else
        temp->bottom = b;

    return res->bottom;
}

Node* Flatten(Node* root) {
    while (root && root->next) {  //root and uska bhai shoudn't be null
        Node* temp = root->next->next;  //temp stores address of 3rd node from stat
        root = mergeTwoLists(root, root->next);  //merge two lists, 1 and root ka next jaha hai, store at first
        root->next = temp;  //move root ka next to temp, matalb jo list pehele merge kari thi, usi ka next
    }
    return root;
}

void printList(Node* node) {
    while (node != nullptr) {
        std::cout << node->data << " ";
        node = node->bottom;
    }
    std::cout << std::endl;
}

int main() {
    // Create the linked list with bottom lists
    Node* root = new Node(5);
    root->next = new Node(10);
    root->next->next = new Node(19);
    root->next->next->next = new Node(28);

    root->bottom = new Node(7);
    root->bottom->bottom = new Node(8);
    root->bottom->bottom->bottom = new Node(30);

    root->next->bottom = new Node(20);

    root->next->next->bottom = new Node(22);
    root->next->next->bottom->bottom = new Node(50);

    root->next->next->next->bottom = new Node(35);
    root->next->next->next->bottom->bottom = new Node(40);
    root->next->next->next->bottom->bottom->bottom = new Node(45);

    // Flatten the list
    root = Flatten(root);

    // Print the flattened list
    printList(root);

    return 0;
}
