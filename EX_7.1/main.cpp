// NAME: DANIEL ATTALI
// ID: 328780879
// COURSE: C++ WORKSHOP
// EX 7.1


#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "iostream"

enum SHAPES { CIRCLE = 1, TRIANGLE = 3, RECTANGLE };
int main() {
    Point p;

    int numShapes, choice;
    std::cout << "How many shapes you would like to define?\n";
    std::cin >> numShapes;
    Shape ** shapes = new Shape * [numShapes];
    for (int i = 0; i < numShapes; i++) {
        std::cout << "Which shape will you choose? Circle - 1, Triangle - 3, Rectangle - 4\n";
        std::cin >> choice;
        switch (choice) {
            case CIRCLE:
                int radius;
                std::cout << "Enter radius :\n";
                std::cin >> radius;
                shapes[i] = new Circle(radius);
                break;
            case TRIANGLE:
                shapes[i] = new Triangle();
                break;
            case RECTANGLE:
                shapes[i] = new Rectangle();
                break;
            default:
                std::cout << "invalid input\n";
                i--;
        }

    }

    for (int i = 0; i < numShapes; i++) {
        std::cout << *(shapes[i]);
        std::cout << " area is: " << shapes[i]->area() << std::endl;
        shapes[i]->printSpecial();
        std::cout << std::endl;
    }
    return 0;
}