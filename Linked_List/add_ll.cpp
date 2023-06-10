#include <iostream>

// Define the Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Solution {
private:
    Node* reverse(Node* head) {
        Node* curr = head;
        Node* prev = nullptr;
        Node* next = nullptr;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    void insertAtTail(Node* &head, Node* &tail, int val) {
        Node* temp = new Node(val);
        if (head == nullptr) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    Node* add(Node* first, Node* second) {
        int carry = 0;

        Node* ansHead = nullptr;
        Node* ansTail = nullptr;

        while (first != nullptr || second != nullptr || carry != 0) {
            int val1 = (first != nullptr) ? first->data : 0;
            int val2 = (second != nullptr) ? second->data : 0;

            int sum = carry + val1 + val2;

            int digit = sum % 10;

            insertAtTail(ansHead, ansTail, digit);

            carry = sum / 10;
            if (first != nullptr)
                first = first->next;
            if (second != nullptr)
                second = second->next;
        }
        return ansHead;
    }

public:
    Node* addTwoLists(Node* first, Node* second) {
        first = reverse(first);
        second = reverse(second);

        Node* ans = add(first, second);

        ans = reverse(ans);

        return ans;
    }
};

int main() {
    // Test the Solution class
    Solution solution;

    // Create the first linked list: 3 -> 4 -> 2
    Node* first = new Node(3);
    first->next = new Node(4);
    first->next->next = new Node(2);

    // Create the second linked list: 4 -> 6 -> 5
    Node* second = new Node(4);
    second->next = new Node(6);
    second->next->next = new Node(5);

    // Add the two linked lists
    Node* result = solution.addTwoLists(first, second);

    // Print the result
    while (result != nullptr) {
        std::cout << result->data << " ";
        result = result->next;
    }

    return 0;
}