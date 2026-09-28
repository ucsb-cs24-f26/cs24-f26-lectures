#ifndef COMPLEX_H
#define COMPLEX_H

/**
 * Complex - a small ADT for numbers of the form a + jb.
 *   a is the real part, b is the imaginary part.
 *
 * The constructor takes default parameter values, so the same
 * declaration covers both Complex p; (0 + 0j) and Complex p(1, 2);
 */
class Complex {
public:
    Complex(double re = 0, double im = 0) : real(re), imag(im) {}

    double getReal() const;
    double getImag() const;

    // Negates the imaginary part in place: a + jb -> a - jb
    void conjugate();

    void print() const;

private:
    double real, imag;
};

#endif
