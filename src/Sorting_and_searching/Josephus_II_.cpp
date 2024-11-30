#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

Node* constructCircularLinkedList(int n) {
    Node* head = new Node(1);
    Node* curr = head;

    for (int i = 2; i <= n; ++i) {
        curr->next = new Node(i);
        curr = curr->next;
    }

    curr->next = head;  // Connect the last node with the head to form a circular linked list

    return head;
}

void eliminateJosephus(int n, int k) {
    Node* head = constructCircularLinkedList(n);
    Node* prev = nullptr;
    Node* curr = head;

    // Find the last node in the circular linked list
    while (curr->next != head) {
        prev = curr;
        curr = curr->next;
    }

    // Perform elimination until only one node is left
    int count = 0;
    while (curr->next != curr) {
        count++;

        if (count == k) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
            count = 0;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    // Print the remaining node, which is the survivor
    std::cout << "The last person standing is: " << curr->data << std::endl;

    // Free the memory
    delete curr;
}

int main() {
    int n, k;
    std::cout << "Enter the number of people (n): ";
    std::cin >> n;
    std::cout << "Enter the elimination step (k): ";
    std::cin >> k;

    eliminateJosephus(n, k);

    return 0;
}
