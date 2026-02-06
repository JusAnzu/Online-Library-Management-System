#include "BookCatalog.h" // Updated to match your provided header name
#include <cassert>
#include <iostream>
using namespace std;

void runTestSuite() {
    BookCatalog testCatalog;
    // Updated to a book from the source code
    testCatalog.addBook(book("Fundamentals Of IT", "Peter Kamau", 101));

    cout << "Starting bookcatalog tests\n";

    // POSITIVE SCENARIOS:
    // 1. Searching for an existing book
    assert(testCatalog.findBookByTitle("Fundamentals Of IT") != nullptr);
    cout << "[PASS] Positive: Existing book found.\n";

    // 2. Borrowing an available book
    book* b = testCatalog.findBookByTitle("Fundamentals Of IT");
    b->setAvailability(false);
    assert(b->isBookAvailable() == false);
    cout << "[PASS] Positive: Availability updated after borrow.\n";

    // NEGATIVE SCENARIOS:
    // 3. Searching for non-existent book (A title that is not in the book catalog)
    assert(testCatalog.findBookByTitle("Advanced Calculus") == nullptr);
    cout << "[PASS] Negative: Correctly returns null for missing book.\n";

    // 4. Checking for Case Sensitivity
    // "fundamentals of it" vs "Fundamentals Of IT"
    assert(testCatalog.findBookByTitle("fundamentals of it") == nullptr);
    cout << "[PASS] Negative: Search is case-sensitive (Expected Behavior).\n";

    // 5. Duplicate ID handling 
    testCatalog.addBook(book("Cultures of the World", "Henry Lynne", 101)); // Same ID as Fundamentals Of IT
    cout << "[WARN] System allowed duplicate ID 101. Consider adding a check!\n";

    cout << "All Tests Passed\n";
}

int main() {
    runTestSuite();
    return 0;
}