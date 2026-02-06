#include <iostream>
#include <cassert>
#include "transaction.h"
#include "user.h"
#include "book.h"

using namespace std;

void runTransactionTests() {
    cout << "Running Transaction Class Tests" << endl;

    // Setup: Transactions need existing Users and Books
    user u1("Alice Wangari", 1001);
    book b1("Fundamentals Of IT", "Peter Kamau", 101);

    // POSITIVE SCENARIOS:

    // 1. Successful Transaction & Automatic Status Update
    
    assert(b1.isBookAvailable() == true); 
    
    transaction t1(5001, &u1, &b1);
    
    assert(t1.getTransactionID() == 5001);
    assert(b1.isBookAvailable() == false); 
    cout << "[PASS] Positive Case 1: Transaction created and book availability updated." << endl;

    // 2. Data Persistence
    // Checks if the transaction holds the correct book reference
    assert(t1.getBook()->getTitle() == "Fundamentals Of IT");
    cout << "[PASS] Positive Case 2: Transaction correctly references the book." << endl;


    // NEGATIVE SCENARIOS:

    // 1. Transaction with Null Book
    // Testing what happens if a transaction is created but the book pointer is null.
    transaction t_null(5002, &u1, nullptr);
    assert(t_null.getBook() == nullptr);
    cout << "[PASS] Negative Case 1: Handled null book pointer (no crash)." << endl;

    // 2. Transaction with Negative ID
    transaction t_neg(-1, &u1, &b1);
    assert(t_neg.getTransactionID() == -1);
    cout << "[PASS] Negative Case 2: System allows negative transaction IDs." << endl;

    // 3. Double Transaction
   
    book b2("Cultures of the World", "Henry Lynne", 201);
    transaction t_first(6001, &u1, &b2);
    transaction t_second(6002, &u1, &b2); 
    
    assert(b2.isBookAvailable() == false);
    cout << "[PASS] Negative Case 3: Creating multiple transactions for the same book doesn't crash." << endl;

    cout << "\nAll Transaction tests completed!" << endl;
}

int main() {
    runTransactionTests();
    return 0;
}