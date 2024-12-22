#include "taskManagement.h"
#include "utils.h"
#include <iostream>
#include <limits>

int TaskManagement::id_counter = 0;

// vector<TaskManagement> tasks;
vector<TaskManagement> tasks = {
    TaskManagement("Pemasangan CCTV", "Pemasangan CCTV di PT.Sahabat Lama", "2024-12-30", "normal", "New", ""),
    TaskManagement("Perbaikan DVR", "Perbaikan VR di PT.Mentari Bersinar", "2024-12-25", "urgent", "New", ""),
    TaskManagement("Perbaikan DVR", "Perbaikan DVR di PT.Bulan Merah", "2024-12-27", "urgent", "In-Progress", "")
};

void taskManagementMenu() {
    int choice;
    string input;
    clearScreen();
    do {
        cout << "\n=== Task Management ===\n";
        cout << "1. Add a new task\n";
        cout << "2. Assign task\n";
        cout << "3. Get list task\n";
        cout << "4. Back\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (cin.fail()) {
            cout << "Invalid input. Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                addNewTask(tasks);
                break;
            case 2:
                assignTask(tasks);
                break;
            case 3:
                getDetailsTask(tasks);
                break;                
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 4);
}

void addNewTask(vector<TaskManagement>& tasks) {
    string title, description, deadline, priority, status, technician;

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

    cout << "Enter task priority (normal/urgent): ";
    getline(cin, priority);
    while (priority != "normal" && priority != "urgent") {
        cout << "Invalid priority. Please enter Low, Medium, or High: ";
        getline(cin, priority);
    }
    
    status = "New";
    // cout << "Enter technician name: ";
    // getline(cin, technician);
    // while (technician.empty()) {
    //     cout << "Invalid technician name. Please enter a non-empty technician name: ";
    //     getline(cin, technician);
    // }    

    // tasks.emplace_back(title, description, deadline, priority, technician);
    tasks.emplace_back(title, description, deadline, priority, status, technician);
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
    cout << "Input the task ID you want to assign: ";
    cin >> taskID;

    if (taskID < 1 || taskID > tasks.size()) {
        cout << "WARN: task ID " << taskID << " not found, Please try again." << endl;
        return;
    }

    cout << "Enter technician name: ";
    cin.ignore();
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

void getDetailsTask(const vector<TaskManagement>& tasks) {
    if (tasks.empty()) {
        cout << "WARN: Skipping assing task, because task is empty." << endl;
        return;
    }    

    string status;
    bool task_found = false;

    cout << "Get the details task by status (New/In-Progress/Done) or type 'All' to get all tasks: ";
    cin >> status;

    if (status.empty()) {
        cout << "WARN: input status is empty, Please try again." << endl;
        return;
    }
    
    if (status == "All") {
        task_found = true;
        displayTasks(tasks);
    } else {
        cout << "\n=== Task List ===\n";
        for (const auto& task : tasks) {
            if (task.status == status) {
                task_found = true;
                cout << "Task ID: " << task.id << ", Title: " << task.title << ", Description: " << task.description << ", Deadline: " << task.deadline << ", Priority: " << task.priority << ", Status: " << task.status << ", Technician: " << task.technician << endl;
            }
        }
    }

    if (!task_found) {
        cout << "No tasks found with status: " << status << endl;
    }
}