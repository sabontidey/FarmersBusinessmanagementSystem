#include "Business.h"
#include <iostream>

class FarmerBusiness : public Business {
private:
    std::string cropName;
    int quantity;
    double pricePerUnit;

public:
    // Constructor
    FarmerBusiness(const std::string& bName, const std::string& oName,
        const std::string& crop, int qty, double price)
        : Business(bName, oName), cropName(crop), quantity(qty), pricePerUnit(price) {
    }

    // Getters
    std::string getCropName() const { return cropName; }
    int getQuantity() const { return quantity; }
    double getPricePerUnit() const { return pricePerUnit; }

    // Setters
    void setCropName(const std::string& crop) { cropName = crop; }
    void setQuantity(int qty) { quantity = qty; }
    void setPricePerUnit(double price) { pricePerUnit = price; }

    // Calculate revenue
    double calculateRevenue() const {
        return quantity * pricePerUnit;
    }

    // Display information
    void display() const override {
        std::cout << "Business Name: " << businessName << "\n";
        std::cout << "Owner Name: " << ownerName << "\n";
        std::cout << "Crop Name: " << cropName << "\n";
        std::cout << "Quantity: " << quantity << "\n";
        std::cout << "Price per Unit: $" << pricePerUnit << "\n";
        std::cout << "Total Revenue: $" << calculateRevenue() << "\n";
        std::cout << "-------------------------\n";
    }
};