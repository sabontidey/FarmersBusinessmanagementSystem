#include <iostream>
#include <vector>
#include <limits>
#include "FarmerBusiness.cpp"

using namespace std;

int main() {
    vector<Business*> businessList;  // Polymorphic vector to store Business objects
    int choice;                       // User menu choice

    do {
        // Display menu
        cout << "\n=== Farmer Business Management System ===\n";
        cout << "1. Add Farmer Record\n";
        cout << "2. Display All Records\n";
        cout << "3. Delete a Record\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Validate menu choice
        while (cin.fail() || choice < 1 || choice > 4) {
            cin.clear(); // clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input. Enter 1-4: ";
            cin >> choice;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear newline

        // === ADD RECORD ===
        if (choice == 1) {
            string bName, oName, crop;
            int qty;
            double price;

            // Get business details
            cout << "Enter Business Name: ";
            getline(cin, bName);
            cout << "Enter Owner Name: ";
            getline(cin, oName);
            cout << "Enter Crop Name: ";
            getline(cin, crop);

            // Input validation for quantity (must be positive integer)
            do {
                cout << "Enter Quantity (number of units): ";
                cin >> qty;
                if (cin.fail() || qty < 0) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid input. Please enter a positive number.\n";
                    qty = -1; // reset to loop again
                }
            } while (qty < 0);
            cin.ignore(1000, '\n'); // clear leftover newline

            // Input validation for price (must be positive)
            do {
                cout << "Enter Price per Unit ($): ";
                cin >> price;
                if (cin.fail() || price < 0) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid input. Please enter a valid price.\n";
                    price = -1;
                }
            } while (price < 0);
            cin.ignore(1000, '\n');

            // Create new FarmerBusiness object and add to vector
            businessList.push_back(new FarmerBusiness(bName, oName, crop, qty, price));
            cout << "Record added successfully!\n";
        }

        // === DISPLAY RECORDS ===
        else if (choice == 2) {
            if (businessList.empty()) {
                cout << "No records to display.\n";
            }
            else {
                cout << "\n--- All Farmer Records ---\n";
                for (size_t i = 0; i < businessList.size(); ++i) {
                    cout << "Record #" << i + 1 << "\n";
                    businessList[i]->display(); // Polymorphic call
                }
            }
        }

        // === DELETE RECORD ===
        else if (choice == 3) {
            if (businessList.empty()) {
                cout << "No records to delete.\n";
                continue;
            }

            int index;
            cout << "Enter record number to delete (1-" << businessList.size() << "): ";
            cin >> index;

            // Validate record number
            while (cin.fail() || index < 1 || index > businessList.size()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Enter record number: ";
                cin >> index;
            }

            // Delete object and remove from vector
            delete businessList[index - 1];
            businessList.erase(businessList.begin() + (index - 1));

            cout << "Record deleted successfully!\n";
        }

    } while (choice != 4); // Exit program

    // Clean up dynamically allocated memory
    for (Business* b : businessList) {
        delete b;
    }

    cout << "Exiting program. Goodbye!\n";
    return 0;
}