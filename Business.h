#ifndef BUSINESS_H
#define BUSINESS_H

#include <string>
#include <iostream>

class Business {
protected:
    std::string businessName;
    std::string ownerName;

public:
    // Constructor
    Business(const std::string& bName, const std::string& oName)
        : businessName(bName), ownerName(oName) {
    }

    // Getters
    std::string getBusinessName() const { return businessName; }
    std::string getOwnerName() const { return ownerName; }

    // Setters
    void setBusinessName(const std::string& bName) { businessName = bName; }
    void setOwnerName(const std::string& oName) { ownerName = oName; }

    // Pure virtual function, must be implemented by derived class
    virtual void display() const = 0;

    // Virtual destructor
    virtual ~Business() {}
};

#endif // BUSINESS_H