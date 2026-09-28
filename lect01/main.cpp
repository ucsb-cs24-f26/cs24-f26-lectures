// main.cpp -- Activity 1: Critique this implementation.
//
// This "playlist" has real problems - including one that crashes it
// immediately. Find at least 3, with a partner, before we build the
// improved version together in class.

#include <iostream>
#include <string>

using namespace std;

struct Node {
    string value;
    Node* next;
};

class CustomList {
public:
    Node* head;

    void push_back(string val) {
        Node* newNode = new Node{val, nullptr};
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }

    void print() {
        Node* temp = head;
        while (temp) {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }
};

void createPlaylist() {
    CustomList playlist;
    playlist.push_back("Song 1");
    playlist.push_back("Song 2");
    playlist.push_back("Song 3");
    playlist.print();
}

int main() {
    createPlaylist();
    return 0;
}
