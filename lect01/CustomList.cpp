#include "CustomList.h"

// Initialization happens in the member initializer list, before the
// constructor body runs.
CustomList::CustomList() : head(nullptr), tail(nullptr) {
}

void CustomList::clear() {
    clearHelper(head);
    head = nullptr;
    tail = nullptr;
}

void CustomList::clearHelper(Node* h) {
    if (h == nullptr) return;
    clearHelper(h->next);
    delete h;
}

// Keeping a tail pointer makes this O(1) instead of walking the whole
// list every time.
void CustomList::push_back(const string& val) {
    Node* newNode = new Node(val, nullptr);

    if (head == nullptr) {          // empty list
        head = newNode;
        tail = newNode;
    } else {                        // non-empty list - O(1), no traversal!
        tail->next = newNode;
        tail = newNode;
    }
}

void CustomList::print() const {
    Node* current = head;
    while (current != nullptr) {
        cout << "[" << current->value << "]->";
        current = current->next;
    }
    cout << "null" << endl;
}
