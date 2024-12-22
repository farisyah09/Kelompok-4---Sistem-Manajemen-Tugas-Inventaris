#include "inventory.h"
#include "utils.h"
#include <iostream>
#include <limits>

int InventoryManagement::id_counter = 0;

vector<InventoryManagement> inventory = {
    InventoryManagement("CCTV001", "CCTV Camera", "10", "Available", "Supplies"),
    InventoryManagement("DVR002", "DVR", "5", "In-Use", "Supplies"),
    InventoryManagement("CCTV003", "CCTV Power Supply", "20", "Available", "Supplies"),
    InventoryManagement("CCTV005", "CCTV Cable (Coaxial)", "30", "Available", "Supplies"),
    InventoryManagement("CCTV006", "CCTV Monitor", "8", "Available", "Supplies"),
    InventoryManagement("Ladder001", "Tangga", "5", "Available", "Tools"),
    InventoryManagement("Wrench001", "Kunci pas", "10", "Available", "Tools"),
    InventoryManagement("Drill001", "Bor", "7", "Available", "Tools")    
};


void inventoryManagementMenu() {
    int choice;
    clearScreen();
    do {
        cout << "\n=== Inventory Management ===\n";
        cout << "1. Add a new inventory\n";
        cout << "2. Get list inventory\n";
        cout << "3. Back\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 3.\n";
            continue;
        }

        cin.ignore();
        switch (choice) {
            case 1:
                addNewInventory(inventory);
                break;
            case 2:
                getDetailsInventory(inventory);
                break;
            case 3:
                cout << "Exiting Inventory Management...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 3);
}

void addNewInventory(vector<InventoryManagement>& inventory) {
    string item_code, item_name, quantity, status, category;

    cout << "Enter item code: ";
    getline(cin, item_code);

    bool found = false;
    for (auto& item : inventory) {
        if (item.item_code == item_code) {
            found = true;
            cout << "Item found: " << item.item_name << " (Current quantity: " << item.quantity << ")\n";
            cout << "Enter additional quantity to add: ";
            string additional_quantity;
            getline(cin, additional_quantity);

            try {
                int new_quantity = stoi(item.quantity) + stoi(additional_quantity);
                item.quantity = to_string(new_quantity);
                cout << "Quantity updated successfully! New quantity: " << item.quantity << "\n";
            } catch (const invalid_argument&) {
                cout << "Invalid quantity entered. Update failed.\n";
            }
            break;
        }
    }

    if (!found) {
        cout << "Enter item name: ";
        getline(cin, item_name);

        cout << "Enter quantity: ";
        getline(cin, quantity);

        status = "Available";

        cout << "Enter category: ";
        getline(cin, category);

        inventory.emplace_back(item_code, item_name, quantity, status, category);
        cout << "Inventory added successfully!\n";
    }
}

void getDetailsInventory(const vector<InventoryManagement>& inventory) {
    cout << "\n=== Inventory List ===\n";
    for (const auto& item : inventory) {
        cout << "Inventory ID: " << item.id << ", Item Code: " << item.item_code << ", Item Name: " << item.item_name << ", Quantity: " << item.quantity << ", Status: " << item.status << ", Category: " << item.category << endl;
    }
}
