// stl_tour.cpp -- the full code typed live in class (instructor copy).

#include <algorithm>
#include <iostream>
#include <list>
#include <set>
#include <vector>

using namespace std;

// Prints any container as [a, b, c]
template <class Container>
void print(const Container& c) {
    cout << "[";
    bool first = true;
    for (const auto& x : c) {
        if (!first) cout << ", ";
        cout << x;
        first = false;
    }
    cout << "]" << endl;
}

int main() {
    // ---- vector ----
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    cout << v[1] << " " << v.at(1) << endl;
    v.insert(v.begin(), 5);         // who moved everything over?
    print(v);
    // vector has no find() member: use std::find, which walks the elements
    if (find(v.begin(), v.end(), 20) != v.end()) {
        cout << "found 20 in vector" << endl;
    }

    // ---- list ----
    list<int> l;
    l.push_back(2);
    l.push_back(3);
    l.push_front(1);
    auto it = l.begin();
    ++it;
    l.insert(it, 7);                // before the element it points to
    print(l);
    // cout << l[2];                // compile error: no operator[]
    // std::find works on the list too (same call, but it walks the nodes)
    if (find(l.begin(), l.end(), 7) != l.end()) {
        cout << "found 7 in list" << endl;
    }

    // ---- set ----
    set<int> s;
    s.insert(5);
    s.insert(1);
    s.insert(5);
    s.insert(3);
    print(s);                       // [1, 3, 5]
    cout << s.count(3) << " " << (s.find(3) != s.end()) << endl;
    s.erase(3);
    print(s);
    // cout << s[0];                // compile error
    // s.push_back(9);              // compile error

    return 0;
}
