// complex_demo.cpp -- exercises the Complex class: construction with
// and without arguments, copying, and conjugate().

#include "Complex.h"
#include <iostream>

using namespace std;

int main() {
    cout << "=== Default constructor: Complex p; ===" << endl;
    Complex p;  // re = 0, im = 0 via the default parameters
    p.print();
    cout << endl;

    cout << "=== Constructor with args: Complex w(1, 2); ===" << endl;
    Complex w(1, 2);
    w.print();
    cout << endl;

    cout << "=== Copying ===" << endl;
    cout << "Complex z(p);   // copy constructor (member-wise copy)" << endl;
    Complex z(p);
    z.print();

    cout << "Complex w2(3, 4);" << endl;
    Complex w2(3, 4);

    cout << "z = w2;         // copy assignment (also member-wise)" << endl;
    z = w2;
    z.print();
    cout << endl;

    cout << "=== conjugate() ===" << endl;
    cout << "w before: ";
    w.print();
    w.conjugate();
    cout << "w after conjugate(): ";
    w.print();

    return 0;
}
