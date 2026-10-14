// stl_tour.cpp 
// Phonebook app: insert and search to be fast 
// Design decision is what data structure to use...
// Good news! You don't have to code the data structure from scratch --- C++ STL already implements
// called Containers --- ADTS that implement .... linked list, vector (dynamic array), ... set!
// 
#include <iostream>
#include <list> // doubly linked-list
#include <set>
#include <vector>
#include <algorithm>

using namespace std;
void print(vector<int> & v){
    for (auto e : v){ // e is the loop variable, auto keyword is automatically figures out the type of e.
        cout << e << " ";
    }
    cout << endl;
}

void print(list<int> & v){
    for (auto e : v){ // e is the loop variable, auto keyword is automatically figures out the type of e.
        cout << e << " ";
    }
    cout << endl;
}

int main() {
    vector<int> v {10, 20, 5, 50}; // Array --- dynamic array
    v.push_back(1);
    v.push_back(60);
    v.push_back(100);
    v.push_back(2); // O(1) Running time (amortized), sometimes you pay a higher price
    cout << v[1] << " "<< v.at(1) << endl;

    // finding an element in the contact list (v) ... assume 10,000 contacts.
    // 1. vector doesn't have a member function! 
    // find method free function
    int target = 20;
    if (find(v.begin(), v.end(), target) != v.end()){ // Assume your vector has n elements. Find a specific element- O(n)
        cout << "Found target "<< target << endl;
    } // walk through every single element: worst case, O(n) 
    cout << "Print all the elements of the vector: ";
    print(v);
    //linked list
    list<int> l {10, 20, 5, 50}; //  linked list!
    l.push_back(1);
    l.push_back(60);
    l.push_back(100);
    l.push_back(2); // O(1)
   //  cout << l[1] << " "<< l.at(1) << endl; // Is this valid? Not an efficient on a linked list, so its not supported!

    // finding an element in the contact list (v) ... assume 10,000 contacts.
    // 1. vector doesn't have a member function! 
    // find method free function
    if (find(l.begin(), l.end(), target) != l.end()){ // find in an unsorted linked list: worst case ,
        // we are looking for the mid element or a key that is not in the linked list
        // In botgh those cases we have to examine O(n) elements
        cout << "Found target "<< target << endl;
    }
    cout << "Print all the elements of the linked list: ";
    print(l);
    // std::set that has both fast insertions and fast search.
    set<int> s {10, 20, 5, 50};
    s.insert(1);
    s.insert(60);
    s.insert(100);
    s.insert(2); // If there are n keys in the set, then the running time for inserting a new key is O(logn)
    target = 21;
    cout <<"Find " << target << " in the set " << endl;
    cout<< s.count(target) <<" " << (s.find(target) != s.end()) << endl;   //search operation
    // search: O(logn )
    // What is the under the hood of set that allows fast insertions and fast search??
    // set is a balanced BST, h = O(logn) which is why insert and find are both O(logn)
    auto it = s.begin(); // "it" is an iterator, next lecture!!
    cout << "min " << *it << endl;  // should print 1 //O(lo gn )
    it++; // successor of a key : O(log n )
    cout << "next larger value (successor): " << *it << endl; // this line should print the next larger key after 1
                                                              // also called successor(1), which is 2






    return 0;
}
