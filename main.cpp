#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// =================== Task Management ===================
const int MAX_TASKS = 100;
string taskManagement[MAX_TASKS][6];
int taskCount = 0;

void addNewTask() {
    if (taskCount >= MAX_TASKS) {
        cout << "ERROR: Task list is full!" << endl;
        return;
    }

    cin.ignore();
    cout << "Enter task title: ";
    getline(cin, taskManagement[taskCount][0]);

    cout << "Enter task description: ";
    getline(cin, taskManagement[taskCount][1]);

    cout << "Enter task deadline (YYYY-MM-DD): ";
    getline(cin, taskManagement[taskCount][2]);

    cout << "Enter task priority (normal/urgent): ";
    getline(cin, taskManagement[taskCount][3]);

    cout << "Enter task status: ";
    getline(cin, taskManagement[taskCount][4]);

    cout << "Enter technician name: ";
    getline(cin, taskManagement[taskCount][5]);

    taskCount++;
    cout << "Task added successfully!" << endl;
}

void getDetailsTask() {
    if (taskCount == 0) {
        cout << "WARN: No tasks available." << endl;
        return;
    }

    cout << "\n=== Task List ===\n";
    for (int i = 0; i < taskCount; i++) {
        cout << "Task ID: " << i + 1 << ", Title: " << taskManagement[i][0] << ", Description: " << taskManagement[i][1] << ", Deadline: " << taskManagement[i][2] << ", Priority: " << taskManagement[i][3] << ", Status: " << taskManagement[i][4] << ", Technician: " << taskManagement[i][5] << endl;
    }
}

void taskManagementMenu() {
    int choice;
    do {
        cout << "\n=== Task Management ===\n";
        cout << "1. Add a new task\n";
        cout << "2. View task list\n";
        cout << "3. Back\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addNewTask();
                break;
            case 2:
                getDetailsTask();
                break;
            case 3:
                cout << "Returning to previous menu...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);
}

// =================== Inventory Management ===================
const int MAX_ITEMS = 100;
string inventoryManagement[MAX_ITEMS][5];
int inventoryCount = 0;

void addNewInventory() {
    if (inventoryCount >= MAX_ITEMS) {
        cout << "ERROR: Inventory list is full!" << endl;
        return;
    }

    cin.ignore();
    cout << "Enter item code: ";
    getline(cin, inventoryManagement[inventoryCount][0]);

    cout << "Enter item name: ";
    getline(cin, inventoryManagement[inventoryCount][1]);

    cout << "Enter quantity: ";
    getline(cin, inventoryManagement[inventoryCount][2]);

    cout << "Enter category: ";
    getline(cin, inventoryManagement[inventoryCount][3]);

    inventoryManagement[inventoryCount][4] = "Available";

    inventoryCount++;
    cout << "Inventory added successfully!\n";
}

void getDetailsInventory() {
    if (inventoryCount == 0) {
        cout << "WARN: Inventory list is empty.\n";
        return;
    }

    cout << "\n=== Inventory List ===\n";
    for (int i = 0; i < inventoryCount; i++) {
        cout << "Item ID: " << i + 1 << ", Item Code: " << inventoryManagement[i][0] << ", Item Name: " << inventoryManagement[i][1] << ", Quantity: " << inventoryManagement[i][2] << ", Category: " << inventoryManagement[i][3]<< ", Status: " << inventoryManagement[i][4]<< endl;
    }
}

void inventoryManagementMenu() {
    int choice;
    do {
        cout << "\n=== Inventory Management ===\n";
        cout << "1. Add a new inventory\n";
        cout << "2. View inventory list\n";
        cout << "3. Back\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addNewInventory();
                break;
            case 2:
                getDetailsInventory();
                break;
            case 3:
                cout << "Returning to previous menu...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);
}

// =================== Main Menu ===================
void adminMenu() {
    int choice;
    do {
        cout << "\n=== Admin Menu ===\n";
        cout << "1. Task Management\n";
        cout << "2. Inventory Management\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                taskManagementMenu();
                break;
            case 2:
                inventoryManagementMenu();
                break;
            case 3:
                cout << "Exiting Admin Menu...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);
}

void technicianMenu() {
    int choice;
    do {
        cout << "\n=== Technician Menu ===\n";
        cout << "1. View Task List\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                getDetailsTask();
                break;
            case 2:
                cout << "Exiting Technician Menu...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 2);
}

int main() {
    int choice;
    do {
        cout << "\n=== Task and Inventory Management System ===\n";
        cout << "1. Login as Admin\n";
        cout << "2. Login as Technician\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                adminMenu();
                break;
            case 2:
                technicianMenu();
                break;
            case 3:
                cout << "Thank you for using the system!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
