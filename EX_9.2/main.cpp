// NAME: DANIEL ATTALI
// ID: 328780879
// COURSE: C++ WORKSHOP
// EX 9.2


#include <iostream>
#include "BookStore.h"
#include "SearchTree.h"


int main() {
    SearchTree<BookStore> store;
    BookStore temp;
    char choice;
    std::cout << "enter a-e:\n";
    std::cin >> choice;

    while(choice != 'e') {
        switch(choice) {
            case 'a':
                std::cout << "enter a book\n";
                std::cin >> temp;
                store.insert(temp);
                break;
            case 'b':
                std::cout << "enter a book\n";
                std::cin >> temp;
                store.remove(temp);
                break;
            case 'c':
                std::cout << "enter a book\n";
                std::cin >> temp;
                if(store.search(temp)) {
                    std::cout << "exist\n";
                } else {
                    std::cout << "not exist\n";
                }
                break;
            case 'd':
                store.inOrder();
                break;
            case 'e':
                break;
            default:
                std::cout << "error\n";
        }
        std::cout << "enter a-e:\n";
        std::cin >> choice;
    }
    return 0;
}

/*enter a-e:
a
enter a book
2 b b
enter a-e:
a
enter a book
1 d
d
enter a-e:
c
enter a book
2 b v
not exist
enter a-e:
d
2 b b
1 d d
enter a-e:
e*/