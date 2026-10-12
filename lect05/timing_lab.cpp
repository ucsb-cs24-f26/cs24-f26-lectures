// timing_lab.cpp -- time it yourself.
// Use the Big-O table from lecture to PREDICT first, then measure.

#include <algorithm>
#include <chrono>
#include <iostream>
#include <list>
#include <random>
#include <set>
#include <vector>

using namespace std;

// Current time in milliseconds.
// double start = now_ms(); ...code to time...; double elapsed = now_ms() - start;
double now_ms() {
    auto t = chrono::steady_clock::now().time_since_epoch();
    return chrono::duration<double, milli>(t).count();
}

int main() {
    int N = 20000;

    // TODO 1: time N inserts at the FRONT of a vector<int>  (v.insert(v.begin(), i))
    // TODO 2: time N inserts at the FRONT of a list<int>    (l.push_front(i))
    // TODO 3: double N and rerun. By what factor did each time grow? Does it match the table?
    // TODO 4: fill a vector<int> and a set<int> with N random ints (mt19937).
    //         Time 1000 lookups in each: std::find(v.begin(), v.end(), x) vs s.find(x).
    //         Print how many were found so the compiler can't delete your loop.

    return 0;
}
