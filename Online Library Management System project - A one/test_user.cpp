#include <iostream>
#include <cassert>
#include <limits> // For testing numeric limits
#include "user.h"
using namespace std;

void runTests() {
    cout << "Running User Class Tests\n" << endl;

    // POSITIVE SCENARIO:
    // 1. Initialization of personal details
    user u1("Alice Wangari", 1001);
    assert(u1.getName() == "Alice Wangari");
    assert(u1.getUserID() == 1001);
    cout << "[PASS] Test Case 1: Initialization of personal details." << endl;

    // NEGATIVE SCENARIOS:
    // 1. Negative ID Scenario
    user u_neg("Bad ID User", -500);
    assert(u_neg.getUserID() == -500);
    cout << "[PASS] Negative Case 1: System allows negative IDs (Logic check required)." << endl;

    // 2. Empty Name Scenario
    user u_empty("", 2002);
    assert(u_empty.getName() == "");
    cout << "[PASS] Negative Case 2: System allows empty name strings." << endl;

    // 3. Testing the limit of the 'int' data type
    int maxID = numeric_limits<int>::max();
    user u_max("Max ID User", maxID);
    assert(u_max.getUserID() == maxID);
    cout << "[PASS] Negative Case 3: System handles maximum integer ID." << endl;

    // 4. Numerical String as Name
    user u_num("123456", 3003);
    assert(u_num.getName() == "123456");
    cout << "[PASS] Negative Case 4: System allows numerical strings as names." << endl;

    cout << "\nAll test scenarios completed!" << endl;
}

int main() {
    runTests();
    return 0;
}