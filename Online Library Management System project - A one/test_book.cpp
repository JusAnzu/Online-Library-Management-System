#include <cassert>
#include <iostream>
#include "book.h"

using namespace std;

void runBookTests() {
    cout << "Running Book Class Tests:" << endl;

    // POSITIVE SCENARIOS:
    
    // 1. Successful Initialization of  a given book
    book b1("Fundamentals Of IT", "Peter Kamau", 101);
    assert(b1.getTitle() == "Fundamentals Of IT");
    assert(b1.getAuthor() == "Peter Kamau");
    assert(b1.getBookID() == 101);
    assert(b1.isBookAvailable() == true);
    cout << "[PASS] Positive Case 1: Fundamentals Of IT initialized correctly." << endl;

    // 2. Borrowing Logic
    book b2("Cultures of the World", "Henry Lynne", 201);
    b2.setAvailability(false);
    assert(b2.isBookAvailable() == false);
    cout << "[PASS] Positive Case 2: Cultures of the World set to Unavailable." << endl;

    // 3. Returning Logic
    book b3("The Global Village", "John Paul", 103);
    b3.setAvailability(false); // Borrow first
    b3.returnBook();           // Then return
    assert(b3.isBookAvailable() == true);
    cout << "[PASS] Positive Case 3: The Global Village returned correctly." << endl;


    // NEGATIVE SCENARIOS:

    // 1. How the system handles negative Book ID
    book b_neg("Basics of Business", "David Githinji", -301);
    assert(b_neg.getBookID() == -301);
    cout << "[PASS] Negative Case 1: Basics of Business accepts negative ID." << endl;

    // 2. How the system handles empty strings for Title/Author
    book b_empty("", "", 0);
    assert(b_empty.getTitle() == "");
    assert(b_empty.getAuthor() == "");
    cout << "[PASS] Negative Case 2: System accepts empty metadata." << endl;

    // 3. How the system handles extremely long titles
    string longTitle = "Communications " + string(1000, '!'); 
    book b_long(longTitle, "Nicholas Wafula", 401);
    assert(b_long.getTitle().length() > 1000);
    cout << "[PASS] Negative Case 3: Communications stress-test title handled." << endl;

    cout << "\nAll Book tests passed successfully!" << endl;
}

int main() {
    runBookTests();
    return 0;
}