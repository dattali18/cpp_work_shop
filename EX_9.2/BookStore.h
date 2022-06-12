// NAME: DANIEL ATTALI
// ID: 328780879
// COURSE: C++ WORKSHOP
// EX 9.2

#ifndef EX_9_2_BOOKSTORE_H
#define EX_9_2_BOOKSTORE_H

#include "string"
#include "iostream"

class BookStore {
private:
//    private filed
    int bookId;

    std::string bookName;

    std::string bookAuthor;

public:
//  constructors and destructor
    explicit BookStore(int bookId = 0, const std::string &bookName = "", const std::string &bookAuthor = "");


//    operator overloading

//    equality operator
    bool operator==(const BookStore &rhs) const;

    bool operator!=(const BookStore &rhs) const;

    bool operator<(const BookStore &rhs) const;

    bool operator>(const BookStore &rhs) const;

    bool operator<=(const BookStore &rhs) const;

    bool operator>=(const BookStore &rhs) const;

//    input output operator
    friend std::ostream& operator<<(std::ostream& os, const BookStore &rhs);

    friend std::istream& operator>>(std::istream& is, BookStore &rhs);

//    setter and getter
    int getBookId() const;

    void setBookId(int bookId);

    const std::string &getBookName() const;

    void setBookName(const std::string &bookName);

    const std::string &getBookAuthor() const;

    void setBookAuthor(const std::string &bookAuthor);
};


#endif //EX_9_2_BOOKSTORE_H
