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
    Complex(const Complex& other){
        real = other.real;
        imag = other.imag;
    }

    // 3. Copy assignment: overwrite an existing object
   // a = b; --> a.operator(b); // a is the implicit object, b is "other"
   // a = (b = c);
   // a = b.operator=(c); // opertaor= should return something of type complex;
   //
    Complex& operator=(Complex& other){
        // Precondition is that other is an existing object
        // and the implicit object is also an existing object (possibly with its own data)
        this->real = other.real;
        this->imag = other.imag;
        return *this;
    }


    // 4. Destructor: any tear down routine
    ~Complex(){
        cout << "Destructor is executed"<< endl;
    }

    // Prints as "a + bj" or "a - bj"
    void print() const {
        cout << real << (imag >= 0 ? " + " : " - ")
             << (imag >= 0 ? imag : -imag) << "j";
    }

private:
    double real, imag;
};
// cout << c;
// cout.operator<<(c);  
// c << cout;

ostream& operator<<(ostream& out, Complex& c){
    c.print();
    return out;
}

int main() {
    Complex *z = new Complex(6, 7);
    z->print();
    cout << "Complex a(1, 2);" << endl;
    Complex a(1, 2);  // Constructor  

    cout << "Complex b = a;   // new object" << endl;
    Complex b = a; // Copy constructor  Complex b(a); 

    cout << "Complex c(5, 6);" << endl;
    Complex c(5, 6);

    cout << "b = c;           // existing object" << endl;
    b = c;  // Copy assignment operator

    cout << "a = b = c;       // chaining" << endl;
    a = b = c; // Copy assignment operator

    cout << "a = "; a.print();
    cout << ", b = "; b.print();
    cout << ", c = "; c.print();
    cout << endl;
    delete z;
    cout << a;
    cout << "\n End of program"<< endl;
    return 0;
}
