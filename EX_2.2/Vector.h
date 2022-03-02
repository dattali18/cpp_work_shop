#ifndef EX_2_2_VECTOR_H
#define EX_2_2_VECTOR_H

// NAME: DANIEL ATTALI
// ID: 328780879
// COURSE: C++ WORKSHOP
// EX 2.2

// declaring the Vector class
class Vector {
private:
    int * data;
    int capacity;
    int size;
public:
    // CONSTRUCTOR
    explicit Vector(int cap = 0);
    // DECONSTRUCTOR
    ~Vector();
    // THIS FUNCTION IS FOR CALCULATING THE CAPACITY OF THE VECTOR FOR A CERTAIN SIZE
    static int calcRequestedSize(int requested_size);
    // RETURN CAPACITY
    int getCapacity() const;
    // RETURN SIZE
    int getSize() const;
    // PRINT THE CURRENT STATE OF THE VECTOR
    void print();
    // ASSIGN THE CALLING VECTOR THE VALUE IN THE PARAMETER VECTOR
    void assign(const Vector& v);
    // EVALUATE IF TWO VECTOR ARE EQUAL (EQUALITY IS DEFINED TO BE THAT ALL THE FIELD OF BOTH OBJECT ARE EQUAL
    bool isEqual(const Vector& v);
    // IS USED LIKE THE [] OPERATOR (RETURN A REFERENCE TO THE VALUE AT THE CERTAIN INDEX
    int & at(int index);
    // RETURN THE VALUE OF THE SCALAR MULTIPLICATION BETWEEN TWO VECTOR
    int scalmul(const Vector& v);
    // CONCATENATE THE PARAMETER VECTOR TO THE CALLING VECTOR
    Vector strnewcat(const Vector& v);
    // CLEAR THE VECTOR (PUT 0 IN EVERY CELL OF THE VECTOR)
    void clear();
    // DELETE THE LAST VALUE IN THE VECTOR
    void delLast();
    // INSERT A VALUE IN THE VECTOR
    void insert(int val);
};


#endif //EX_2_2_VECTOR_H
