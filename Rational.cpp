#include "iostream"
#include "Rational.h"

// Name: Daniel Attali
// id: 328780879
// course: C++ Work Shop
// EX 1.1

void Rational::setDenominator(int d) {
    if (d == 0) // checking the validity of the output
    {
        this->denominator = 1; // I decided to make the Denominator
    } else if (d < 0) {
        this->denominator = d * (-1); // if the Denominator is negative we make the Numerator negative
        this->numerator *= -1;
    } else {
        this->denominator = d;
    }
}

void Rational::setNumerator(int n) {
    this->numerator = n; // Numerator can be every whole number
}

void Rational::print() const {
    std::cout << this->numerator << "/" << this->denominator << std::endl;
}

bool Rational::equal(Rational r2) const {
    // two Rational number are equal if and only if both the denominator and numerator are equal (by some definition)
    if (this->numerator == r2.numerator && this->denominator == r2.denominator)
    {
        return true;
    }
    return false;
}

void Rational::reduction() {
    // finding the Greatest Common Denominator (GCD) and divisor
    int divisor = this->findGCD(this->denominator, this->numerator);
    this->denominator /= divisor;
    this->numerator /= divisor;
}


Rational Rational::add(Rational r2) const {
    Rational res;
    // if the denominator are equal we add the numerator
    if (this->denominator == r2.denominator) {
        res.setDenominator(this->denominator);
        res.setNumerator(this->numerator + r2.numerator);
        res.reduction();
//    if the denominator aren't equal we make a common denominator by multiplying the denominator
    } else {
        res.setDenominator(this->denominator * r2.denominator);
        res.setNumerator((this->numerator * r2.denominator) + (r2.numerator * this->denominator));
        res.reduction();
    }
    return res;
}


// this function calculate the GCD between two positive number
int Rational::findGCD(int a, int b) {
    {
        if(a < 0 || b < 0)
            return -1;

        if (a == 0)
            return b;
        else if (b == 0)
            return a;
        else
            return findGCD(b, a % b);
    }
}
