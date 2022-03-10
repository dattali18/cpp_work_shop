#ifndef EX_1_RATIONAL_H
#define EX_1_RATIONAL_H

// Name: Daniel Attali
// id: 328780879
// course: C++ Work Shop
// EX 3.1

// declaring the Rational class
class Rational {
private:

    int numerator;
    int denominator;
    int findGCD(int a, int b); // this function is private because it's only used by the class method
public:
//    empty ctor
    Rational();
//  ctor
    Rational(int n, int d);
//  copy ctor
    Rational(Rational& r);
    Rational(const Rational &rational);
// setters
    void setNumerator(int n);
    void setDenominator(int d);
//    getters
    int getNumerator() const{ // for small function I write the function in the .h file
        return numerator;
    }
    int getDenominator() const{
        return denominator;
    }
//    help methods
    void print() const;
    bool equal(Rational r2) const;
    void reduction();
    Rational add(Rational r2) const;
//    operator overloading
    Rational operator+(const Rational& r2) const;
    Rational operator-(const Rational& r2) const;
    Rational operator*(const Rational& r2) const;
    Rational operator/(const Rational& r2) const;
    Rational operator++();
    Rational operator++(int);
    Rational operator--();
    Rational operator--(int);
    Rational& operator=(Rational r2);
    bool operator==(const Rational& r2) const;
    bool operator!=(const Rational& r2) const;
    bool operator>(const Rational& r2) const;
    bool operator<(const Rational& r2) const;
    bool operator>=(const Rational& r2) const;
    bool operator<=(const Rational& r2) const;
};


#endif //EX_1_RATIONAL_H
