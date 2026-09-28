#include "Complex.h"
#include <iostream>

using namespace std;

double Complex::getReal() const {
    return real;
}

double Complex::getImag() const {
    return imag;
}

void Complex::conjugate() {
    imag = -imag;
}

void Complex::print() const {
    if (imag >= 0) {
        cout << real << " + " << imag << "j" << endl;
    } else {
        cout << real << " - " << -imag << "j" << endl;
    }
}
