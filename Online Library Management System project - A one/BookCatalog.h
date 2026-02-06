#ifndef BOOK_CLASSES_H
#define BOOK_CLASSES_H

#include <iostream>
#include <string>
#include <vector>

class book {
private:
    std::string title;
    std::string author;
    int bookID;
    bool isAvailable;
public:
    book(std::string t, std::string a, int id) : title(t), author(a), bookID(id), isAvailable(true) {}
    
    void displayInfo() const {
        std::cout << "Title: " << title << ", Available: " << (isAvailable ? "Yes" : "No") << std::endl;
    }
    
    bool isBookAvailable() const { return isAvailable; }
    void setAvailability(bool avail) { isAvailable = avail; }
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
};

class BookCatalog {
private:
    std::vector<book> books;
public:
    void addBook(book b) { books.push_back(b); }
    
    book* findBookByTitle(std::string title) {
        for (auto& b : books) {
            if (b.getTitle() == title) return &b;
        }
        return nullptr;
    }
};

#endif