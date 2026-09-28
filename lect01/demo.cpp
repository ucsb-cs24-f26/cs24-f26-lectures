#include "CustomList.h"
#include <iostream>
#include <list>

using namespace std;

/**
 * Lecture 1 Demo - CustomList
 *
 * Demo 1-2: our own CustomList, built from nodes and pointers.
 * Demo 3:   std::list does the same job, and you never write a single
 *           Node or pointer.
 */

void demonstrateBasics() {
    cout << "=== Demo 1: Basic Usage ===" << endl;

    CustomList playlist;
    playlist.push_back("Bad");
    playlist.push_back("Beat It");
    playlist.push_back("Thriller");

    cout << "Using print(): ";
    playlist.print();
    cout << endl;
}

void demonstrateMultipleLists() {
    cout << "=== Demo 2: Two independent lists ===" << endl;

    CustomList playlist1;
    playlist1.push_back("Thriller");
    playlist1.push_back("Bad");

    CustomList playlist2;
    playlist2.push_back("Dangerous");
    playlist2.push_back("Black or White");

    cout << "Playlist 1: ";
    playlist1.print();
    cout << "Playlist 2: ";
    playlist2.print();

    cout << endl;
}

void demonstrateSTLComparison() {
    cout << "=== Demo 3: This is what std::list gives you for free ===" << endl;

    std::list<string> playlist;
    playlist.push_back("Bad");
    playlist.push_back("Beat It");
    playlist.push_back("Thriller");

    cout << "std::list, same operations, zero node/pointer code: ";
    for (const string& song : playlist) {
        cout << "[" << song << "]->";
    }
    cout << "null" << endl;

    cout << "No manual new/delete. No tail pointer to manage yourself." << endl;
    cout << "std::list (and std::forward_list, std::vector, ...) are ADTs:" << endl;
    cout << "you get the interface, the library owns the implementation." << endl;
    cout << endl;
}

int main() {
    cout << "========================================" << endl;
    cout << "  CS24 Lecture 1: CustomList Demo" << endl;
    cout << "========================================" << endl;
    cout << endl;

    demonstrateBasics();
    demonstrateMultipleLists();
    demonstrateSTLComparison();

    cout << "========================================" << endl;
    cout << "  End of Demo" << endl;
    cout << "========================================" << endl;

    return 0;
}
