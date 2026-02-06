#include <iostream>
#include <string>
#include <vector>
using namespace std;

class user {
private:
    string name;
    int userID;

public:
    user(string n, int id) : name(n), userID(id) {}
    void displayInfo() {
        cout << "Hello "<<name<<" ,welcome to Hekima library"<<endl;
    }
};

class book {
private:
    string title;
    string author;
    int bookID;
    bool isAvailable;
public:
    book(string t, string a, int id) : title(t), author(a), bookID(id), isAvailable(true) {}
    void displayInfo() const {
        cout << "Book Title: " << title << ", Author: " << author << ", Book ID: " << bookID << ", Available: " << (isAvailable ? "Yes" : "No") << endl;
    }
    bool isBookAvailable() const {
        return isAvailable;
    }
    void setAvailability(bool avail) {
        isAvailable = avail;
    }
    void returnBook() {
        isAvailable = true;
    }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    int getBookID() const { return bookID; }
};
class BookCatalog {
private:
    vector<book> books;
public:
    void addBook(book b) {
        books.push_back(b);
    }

    book* findBookByTitle(string title) {
        for (auto& b : books) {
            if (b.getTitle() == title) {
                return &b;
            }
        }
        return nullptr;
    }

    void searchByTitle(string title) const {
        cout << "\nSearch results for Title: " << title << endl;
        bool found = false;
        for (const auto& b : books) {
            if (b.getTitle() == title) {
                b.displayInfo();
                found = true;
            }
        }
        if (!found) cout << "No books found with that title." << endl;
    }

    void searchByAuthor(string author) const {
        cout << "\nSearch results for Author: " << author << endl;
        bool found = false;
        for (const auto& b : books) {
            if (b.getAuthor() == author) {
                b.displayInfo();
                found = true;
            }
        }
        if (!found) cout << "No books found by that author." << endl;
    }

    void displayAllBooks() const{
        cout << "\nAll books in catalog:" << endl;
        for (const auto& b : books) {
            b.displayInfo();
        }
    }
};
class transaction {
private:
    int transactionID;
    user* usr;
    const book* bk;
public:
    transaction(int tid, user* u, const book* b) : transactionID(tid), usr(u), bk(b) {
        if (bk) const_cast<book*>(bk)->setAvailability(false);
    }
    void displayInfo() {
        cout << "Transaction ID: " << transactionID << endl;
        usr->displayInfo();
        bk->displayInfo();
    }
};
int main() {
    cout << "Welcome to Hekima Online Library Management System!" << endl;

    BookCatalog catalog;

    // sample books in book catalog
    catalog.addBook(book("Fundamentals Of IT", "Peter Kamau", 101));
    catalog.addBook(book("Cultures of the World", "Henry Lynne", 201));
    catalog.addBook(book("The Global Village", "John Paul", 103));
    catalog.addBook(book("Basics of Business", "David Githinji", 301));
    catalog.addBook(book("Communications", "Nicholas Wafula", 401));
    catalog.addBook(book("Basic Mathematics", "Thomas Victor", 103));

    cout << "Enter user details:" << endl;
    cout << "Name: ";
    string userName;
    cin >> userName;
    cout << "User ID: ";
    string userIDStr;
    cin >> userIDStr;
    int userID = stoi(userIDStr);

    user u1(userName, userID);
    u1.displayInfo();

    int mainOption = 0;
    while (mainOption != 3) {
        cout << "\n=== Main Menu ===" << endl;
        cout << "1. Search for a book" << endl;
        cout << "2. Borrow/Return a book" << endl;
        cout << "3. Exit" << endl;
        cout << "Select option (1-3): ";
        string mainChoice;
        cin >> mainChoice;
        cin.ignore();
        mainOption = stoi(mainChoice);

        if (mainOption == 1) {
            cout << "\nSearch options:" << endl;
            cout << "1. Search by Title" << endl;
            cout << "2. Search by Author" << endl;
            cout << "3. View all books" << endl;
            cout << "Select option (1-3): ";
            string option;
            cin >> option;
            cin.ignore();

            if (option == "1") {
                cout << "Enter book title: ";
                string searchTitle;
                getline(cin, searchTitle);
                catalog.searchByTitle(searchTitle);
            } else if (option == "2") {
                cout << "Enter author name: ";
                string searchAuthor;
                getline(cin, searchAuthor);
                catalog.searchByAuthor(searchAuthor);
            } else if (option == "3") {
                catalog.displayAllBooks();
            }
        } else if (mainOption == 2) {
            cout << "\nTransaction Menu:" << endl;
            cout << "1. Borrow a book" << endl;
            cout << "2. Return a book" << endl;
            cout << "3. View all books" << endl;
            cout << "Select option (1-3): ";
            string transOption;
            cin >> transOption;
            cin.ignore();

            if (transOption == "1") {
                cout << "Enter book title to borrow: ";
                string borrowTitle;
                getline(cin, borrowTitle);
                book* foundBook = catalog.findBookByTitle(borrowTitle);
                if (foundBook) {
                    if ((*foundBook).isBookAvailable()) {
                        (*foundBook).setAvailability(false);
                        cout << "\nBook borrowed successfully!" << endl;
                        cout << "Transaction Details:" << endl;
                        (*foundBook).displayInfo();
                    } else {
                        cout << "Sorry, this book is not available." << endl;
                    }
                } else {
                    cout << "Book not found in catalog." << endl;
                }
                break;
            } else if (transOption == "2") {
                cout << "Enter book title to return: ";
                string returnTitle;
                getline(cin, returnTitle);
                book* foundBook = catalog.findBookByTitle(returnTitle);
                if (foundBook) {
                    (*foundBook).returnBook();
                    cout << "\nBook returned successfully!" << endl;
                    cout << "Book Details:" << endl;
                    (*foundBook).displayInfo();
                } else {
                    cout << "Book not found in catalog." << endl;
                }
                break;
    }else if (transOption == "3") {
                catalog.displayAllBooks();
            }
        }
    }
    cout << "\nThank you for using Hekima Online Library Management System!" << endl;

    return 0;
}
