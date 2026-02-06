#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "user.h"
#include "book.h"

class transaction {
private:
    int transactionID;
    user* usr;
    const book* bk;
public:
    // The constructor automatically sets the book to unavailable
    transaction(int tid, user* u, const book* b) : transactionID(tid), usr(u), bk(b) {
        if (bk) const_cast<book*>(bk)->setAvailability(false);
    }
    
    void displayInfo() {
        std::cout << "Transaction ID: " << transactionID << std::endl;
        usr->displayInfo();
        bk->displayInfo();
    }

    // Getters for testing
    int getTransactionID() const { return transactionID; }
    const book* getBook() const { return bk; }
};

#endif