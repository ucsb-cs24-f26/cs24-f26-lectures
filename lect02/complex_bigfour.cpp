// complex_bigfour.cpp -- the Big Four on a class that owns no heap memory.
// Every "copy" below is member-wise, exactly what the compiler-generated
// default would do. The prints show the hidden calls.

#include <iostream>

using namespace std;

class Complex {
public:
    // 1. Constructor: build / initialize
    Complex(double re = 0, double im = 0) : real(re), imag(im) {
        cout << "  constructor" << endl;
    }

    // 2. Copy constructor: initialize new object from an existing one


    // 3. Copy assignment: overwrite an existing object


    // 4. Destructor: any tear down routine


    // Prints as "a + bj" or "a - bj"
    void print() const {
        cout << real << (imag >= 0 ? " + " : " - ")
             << (imag >= 0 ? imag : -imag) << "j";
    }

private:
    double real, imag;
};

int main() {
    cout << "Complex a(1, 2);" << endl;
    Complex a(1, 2);

    cout << "Complex b = a;   // new object" << endl;
    Complex b = a;

    cout << "Complex c(5, 6);" << endl;
    Complex c(5, 6);

    cout << "b = c;           // existing object" << endl;
    b = c;

    cout << "a = b = c;       // chaining" << endl;
    a = b = c;

    cout << "a = "; a.print();
    cout << ", b = "; b.print();
    cout << ", c = "; c.print();
    cout << endl;
    return 0;
}
