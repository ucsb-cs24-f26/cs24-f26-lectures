// list_demo.cpp -- Demo 1 and Demo 2 (see README.md).
// Run it, watch it crash, find out why, fix it, run it again.

#include <iostream>
#include <string>

using namespace std;

class CustomList {
public:
    CustomList():head(nullptr){}
    ~CustomList() {
        clear();
    }

    // Frees all nodes and resets the list to empty
    void clear() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    void push_back(const string& val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {          // empty list
            head = newNode;
        } else {                        // walk to the last node
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void print() const {
        Node* current = head;
        while (current != nullptr) {
            cout << "[" << current->value << "]->";
            current = current->next;
        }
        cout << "null" << endl;
    }

private:
    struct Node {
        string value;
        Node* next;
        Node(const string& val, Node* nxt = nullptr) : value(val), next(nxt) {}
    };

    Node* head;
};

void demo1_first_list() {
    cout << "=== Demo 1: build a playlist ===" << endl;
    CustomList playlist;
    playlist.push_back("Thriller");
    playlist.push_back("Bad");
    playlist.push_back("Beat It");
    playlist.print();
    cout << endl;
}

void demo2_copy_a_list() {
    cout << "=== Demo 2: copy a playlist ===" << endl;
    CustomList original;
    original.push_back("Thriller");
    original.push_back("Bad");
    original.push_back("Beat It");

    CustomList backup = original;   // copy constructor
    cout << "original: "; original.print();
    cout << "backup:   "; backup.print();
    cout << "leaving demo2..." << endl;
}  

int main() {
    demo1_first_list();
    demo2_copy_a_list();
    cout << "done" << endl;
    return 0;
}
