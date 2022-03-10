#include "iostream"
#include "Rational.h"
using std::cout;
using std::endl;

// Name: Daniel Attali
// id: 328780879
// course: C++ Work Shop
// EX 3.1

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
    if (this->denominator != 1) {
        cout << this->numerator << "/" << this->denominator << endl;
    } else {
        cout << this->numerator << endl;
    }

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
    if (divisor < 0) {
        this->denominator /= divisor * -1;
        this->numerator /= divisor * -1;
    } else {
        this->denominator /= divisor;
        this->numerator /= divisor;
    }
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
// ctor
Rational::Rational() {
    this->numerator = 1;
    this->denominator = 1;
}
// ctor
Rational::Rational(int n, int d) {
    this->numerator = n;
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
// copy ctor
Rational::Rational(Rational &r) {
    this->numerator = r.numerator;
    this->denominator = r.denominator;
}
// operator overloading

// operator + (addition)
Rational Rational::operator+(const Rational& r2) const{
    Rational res;
    res.denominator = this->denominator * r2.denominator;
    res.numerator = (this->numerator * r2.denominator) + (r2.numerator * this->denominator);
    res.reduction();
    return res;
}
// operator - (sub)
Rational Rational::operator-(const Rational& r2) const {
    Rational res;
    res.denominator = this->denominator * r2.denominator;
    res.numerator = (this->numerator * r2.denominator) - (r2.numerator * this->denominator);
    res.reduction();
    return res;
}
// operator * (multi)
Rational Rational::operator*(const Rational &r2) const {
    Rational res;
    res.denominator = this->denominator * r2.denominator;
    res.numerator = this->numerator * r2.numerator;
    res.reduction();
    return res;
}
// operator / (div)
Rational Rational::operator/(const Rational& r2) const {
    Rational res;
//    explanation: (a/b) / (c/d) = (ad)/(bc)
    res.denominator = this->denominator * r2.numerator;
    res.numerator = this->numerator * r2.denominator;
    res.reduction();
    return res;
}
// operator prefix ++
Rational Rational::operator++(){
    this->numerator += this->denominator;
    return *this;
}
// operator postfix ++
Rational Rational::operator++(int) {
    Rational temp(this->numerator, this->denominator);
    this->numerator += this->denominator;
    return temp;
}
// operator prefix --
Rational Rational::operator--() {
    this->numerator -= this->denominator;
    return *this;
}
// operator postfix --
Rational Rational::operator--(int) {
    Rational temp(this->numerator, this->denominator);
    this->numerator -= this->denominator;
    return temp;
}
// operator = (eql)
Rational& Rational::operator=(Rational r2) {
    this->numerator = r2.numerator;
    this->denominator = r2.denominator;
    return *this;
}
// copy ctor
Rational::Rational(Rational const &rational) {
    this->numerator = rational.numerator;
    this->denominator = rational.denominator;
}
// operator == (equality)
bool Rational::operator==(const Rational &r2) const {
    Rational temp1(this->numerator, this->denominator);
    Rational temp2(r2.numerator, r2.denominator);
    temp1.reduction();
    temp2.reduction();
    return (temp1.numerator == temp2.numerator && temp1.denominator == temp2.denominator);
}
// operator != (not equal)
bool Rational::operator!=(const Rational &r2) const {
//    using already established operator, instead of rewriting code
    return !(*this == r2);
}
// operator > (greater than)
bool Rational::operator>(const Rational &r2) const {
    // converting to float in order to compare the numbers
    float n1 = (float) this->numerator / (float) this->denominator;
    float n2 = (float) r2.numerator / (float) r2.denominator;
    return (n1 > n2);
}
// operator < (less than)
bool Rational::operator<(const Rational &r2) const {
//    using already established operator, instead of rewriting code
    return (r2 > *this);
}
// operator >= (greater than or equal)
bool Rational::operator>=(const Rational &r2) const {
//    using already established operator, instead of rewriting code
    return (*this > r2 || *this == r2);
}
// operator <= (less than or equal)
bool Rational::operator<=(const Rational &r2) const {
//    using already established operator, instead of rewriting code
    return (*this < r2 || *this == r2);
}