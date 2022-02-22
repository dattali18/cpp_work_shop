#ifndef EX_1_RATIONAL_H
#define EX_1_RATIONAL_H

// Name: Daniel Attali
// id: 328780879
// course: C++ Work Shop
// EX 1.1

// declaring the Rational class
class Rational {
private:
    int numerator;
    int denominator;
    int findGCD(int a, int b); // this function is private because it's only used by the class method
public:
    void setNumerator(int n);
    void setDenominator(int d);
    int getNumerator() const{ // for small function I write the function in the .h file
        return numerator;
    }
    int getDenominator() const{
        return denominator;
    }
    void print() const;
    bool equal(Rational r2) const;
    void reduction();
    Rational add(Rational r2) const;
};


#endif //EX_1_RATIONAL_H
