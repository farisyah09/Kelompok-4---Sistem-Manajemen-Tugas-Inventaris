#include <iostream>
#include <vector>
#include "taskManagement.h"
#include "inventory.h"
#include "utils.h"
#include <limits>

void adminMenu() {
    int choice;
    do {
        clearScreen();
        cout << "\n=== Admin Menu ===\n";
        cout << "1. Task Management\n";
        cout << "2. Inventory Management\n";
        cout << "3. Exit\n";
        cout << "Select an option: ";
        cin >> choice;
        if (cin.fail()) {
            cout << "Invalid input. Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        } 

        switch (choice) {
            case 1:
                taskManagementMenu();
                break; 
            case 2:
                inventoryManagementMenu();
                break;                            
        }
    } while (choice != 3);
}

void technicianMenu() {
    int choice;
    do {
        clearScreen();
        cout << "\n=== Technician Menu ===\n";
        cout << "1. Task Operation:\n";
        cout << "2. Keluar\n";
        cout << "Select an option:: ";
        cin >> choice;
        if (cin.fail()) {
            cout << "Invalid input. Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }     

    } while (choice != 2);
}

int main() {
    int choice;
    do {
        clearScreen();
        cout << "\n=== Task and Inventory Management System ===\n";
        cout << "1. Login as Admin\n";
        cout << "2. Login as Technician\n";
        cout << "3. Exit\n";
        cout << "Select an option: ";
        cin >> choice;
        if (cin.fail()) {
            cout << "Invalid input. Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                adminMenu();
                break;
            case 2:
                technicianMenu();
                break;
        }
    } while (choice != 3);

    cout << "\nThank you for using this system.!\n";
    return 0;
}