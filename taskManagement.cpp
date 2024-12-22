#include "taskManagement.h"
#include "utils.h"
#include <iostream>

int TaskManagement::id_counter = 0;

// vector<TaskManagement> tasks;
vector<TaskManagement> tasks = {
    TaskManagement("Pemasangan CCTV", "Pemasangan CCTV di PT.Sahabat Lama", "2024-12-30", "Low"),
    TaskManagement("Perbaikan DVR", "Perbaikan di DVR di PT.Mentari Bersinar", "2024-12-25", "High")
};

void taskManagementMenu() {
    int choice;
    clearScreen();
    do {
        cout << "\n=== Task Management ===\n";
        cout << "1. Add a new task\n";
        cout << "2. Assign tasks\n";
        cout << "3. Display tasks\n";
        cout << "4. Back\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                addNewTask(tasks);
                break;
            case 2:
                assignTask(tasks);
                break;
            case 3:
                displayTasks(tasks);
                break;                
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 4);
}

void addNewTask(vector<TaskManagement>& tasks) {
    string title, description, deadline, priority;

    cout << "Enter task title: ";
    getline(cin, title);
    while (title.empty()) {
        cout << "Invalid title. Please enter a non-empty task title: ";
        getline(cin, title);
    } 
    
    cout << "Enter task description: ";
    getline(cin, description);
    while (description.empty()) {
        cout << "Invalid description. Please enter a non-empty task description: ";
        getline(cin, description);
    } 
        
    cout << "Enter task deadline (YYYY-MM-DD): ";
    getline(cin, deadline);
    while (deadline.empty()) {
        cout << "Invalid deadline. Please enter a valid deadline in the format YYYY-MM-DD: ";
        getline(cin, deadline);
    }    

    cout << "Enter task priority (Low/Medium/High): ";
    getline(cin, priority);
    while (priority != "Low" && priority != "Medium" && priority != "High") {
        cout << "Invalid priority. Please enter Low, Medium, or High: ";
        getline(cin, priority);
    }

    // cout << "Enter technician name: ";
    // getline(cin, technician);
    // while (technician.empty()) {
    //     cout << "Invalid technician name. Please enter a non-empty technician name: ";
    //     getline(cin, technician);
    // }    

    // tasks.emplace_back(title, description, deadline, priority, technician);
    tasks.emplace_back(title, description, deadline, priority);
    cout << "Task added successfully!" << endl;
}

void assignTask(vector<TaskManagement>& tasks) {
    if (tasks.empty()) {
        cout << "WARN: Skipping assing task, because task is empty." << endl;
        return;
    }
    
    int taskID;
    string technician;

    displayTasks(tasks);
    cout << "Input task ID where to assing: ";
    cin >> taskID;

    if (taskID < 1 || taskID > tasks.size()) {
        cout << "ERROR: task ID " << taskID << " not found, Please try again." << endl;
        return;
    }

    cin.ignore();
    cout << "Enter technician name: ";
    getline(cin, technician);
    while (technician.empty()) {
        cout << "Invalid technician name. Please enter a non-empty technician name: ";
        getline(cin, technician);
    }

    tasks[taskID - 1].technician = technician;
    cout << "SUCCESS: Task ID " << taskID << " is now assigned to technician " << technician << endl;

}

void displayTasks(const vector<TaskManagement>& tasks) {
    cout << "\n=== Task List ===\n";
    
    for (const auto& task : tasks) {
        cout << "Task ID: " << task.id << ", Title: " << task.title << ", Description: " << task.description << ", Deadline: " << task.deadline << ", Priority: " << task.priority << ", Status: " << task.status << ", Technician: " << task.technician << endl;
    }

    // cout << endl;
}