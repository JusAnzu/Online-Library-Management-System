#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

class book {
private:
    std::string title;
    std::string author;
    int bookID;
    bool isAvailable;
public:
    book(std::string t, std::string a, int id) : title(t), author(a), bookID(id), isAvailable(true) {}
    
    void displayInfo() const {
        std::cout << "Book Title: " << title << ", Author: " << author << ", Book ID: " << bookID << ", Available: " << (isAvailable ? "Yes" : "No") << std::endl;
    }
    
    bool isBookAvailable() const { return isAvailable; }
    void setAvailability(bool avail) { isAvailable = avail; }
    void returnBook() { isAvailable = true; }
    
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    int getBookID() const { return bookID; }
};

#endif