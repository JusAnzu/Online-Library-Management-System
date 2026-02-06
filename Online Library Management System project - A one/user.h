#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

class user {
private:
    std::string name;
    int userID;

public:
    user(std::string n, int id) : name(n), userID(id) {}
    
    // Getters for testing purposes
    std::string getName() const { return name; }
    int getUserID() const { return userID; }

    void displayInfo() const {
        std::cout << "Hello " << name << ", welcome to Hekima library (ID: " << userID << ")" << std::endl;
    }
};

#endif