// NAME: DANIEL ATTALI
// ID: 328780879
// COURSE: C++ WORKSHOP
// EX 9.2

#include "BookStore.h"
#include <cstring>
//  setter and getter

int BookStore::getBookId() const {
    return bookId;
}

void BookStore::setBookId(int bookId) {
    BookStore::bookId = bookId;
}

const std::string &BookStore::getBookName() const {
    return bookName;
}

void BookStore::setBookName(const std::string &bookName) {
    BookStore::bookName = bookName;
}

const std::string &BookStore::getBookAuthor() const {
    return bookAuthor;
}

void BookStore::setBookAuthor(const std::string &bookAuthor) {
    BookStore::bookAuthor = bookAuthor;
}
//  operator overloading

bool BookStore::operator==(const BookStore &rhs) const {
    return bookName == rhs.bookName &&
           bookAuthor == rhs.bookAuthor &&
           bookId == rhs.bookId;
}

bool BookStore::operator!=(const BookStore &rhs) const {
    return !(rhs == *this);
}

//  constructors and destructor
BookStore::BookStore(int bookId, const std::string &bookName, const std::string &bookAuthor) : bookId(bookId),
                                                                                               bookName(bookName),
                                                                                               bookAuthor(bookAuthor) {}

bool BookStore::operator<(const BookStore &rhs) const {
    if((bookAuthor == rhs.bookAuthor) && (bookName == rhs.bookName))
        return bookId < rhs.bookId;
    return strcmp((bookName+bookAuthor).c_str(), (rhs.bookName+rhs.bookAuthor).c_str()) < 0;
}

bool BookStore::operator>(const BookStore &rhs) const {
    return rhs  < (*this);
}

bool BookStore::operator<=(const BookStore &rhs) const {
    return *(this) < rhs || *(this) == rhs;
}

bool BookStore::operator>=(const BookStore &rhs) const {
    return *(this) > rhs || *(this) == rhs;
}

std::ostream &operator<<(std::ostream &os, const BookStore &rhs) {
    os << rhs.bookId << " " << rhs.bookName << " " << rhs.bookAuthor;
    return os;
}

std::istream &operator>>(std::istream &is, BookStore &rhs) {
    is >> rhs.bookId >> rhs.bookName >> rhs.bookAuthor;
    return is;
}
