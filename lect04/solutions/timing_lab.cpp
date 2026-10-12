// timing_lab.cpp -- answer key. Doubles N three times so growth is visible.

#include <algorithm>
#include <chrono>
#include <iostream>
#include <list>
#include <random>
#include <set>
#include <vector>

using namespace std;

double now_ms() {
    auto t = chrono::steady_clock::now().time_since_epoch();
    return chrono::duration<double, milli>(t).count();
}

int main() {
    for (int N = 20000; N <= 80000; N *= 2) {
        cout << "N = " << N << endl;

        vector<int> v;
        double start = now_ms();
        for (int i = 0; i < N; i++) v.insert(v.begin(), i);
        cout << "  insert front, vector: " << now_ms() - start << " ms" << endl;

        list<int> l;
        start = now_ms();
        for (int i = 0; i < N; i++) l.push_front(i);
        cout << "  insert front, list:   " << now_ms() - start << " ms" << endl;

        mt19937 gen(1);
        vector<int> vals;
        set<int> s;
        for (int i = 0; i < N; i++) {
            int x = gen();
            vals.push_back(x);
            s.insert(x);
        }
        vector<int> queries;
        for (int i = 0; i < 1000; i++) queries.push_back(gen());

        int found = 0;
        start = now_ms();
        for (int x : queries)
            if (find(vals.begin(), vals.end(), x) != vals.end()) found++;
        cout << "  1000 lookups, vector: " << now_ms() - start << " ms" << endl;

        start = now_ms();
        for (int x : queries)
            if (s.find(x) != s.end()) found++;
        cout << "  1000 lookups, set:    " << now_ms() - start << " ms" << endl;
        cout << "  (found " << found << ")" << endl;
    }
    return 0;
}
