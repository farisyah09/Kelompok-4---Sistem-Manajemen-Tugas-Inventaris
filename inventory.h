#ifndef INVENTORYMANAGEMENT_H
#define INVENTORYMANAGEMENT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class InventoryManagement {
public:
    static int id_counter;
    int id;
    string item_code;
    string item_name;
    string quantity;
    string status;
    string category;

    InventoryManagement(string item_code, string item_name, string quantity, string status, string category) : item_code(item_code), item_name(item_name), quantity(quantity), status(status), category(category) { 
        id = ++id_counter;
    }
};

void inventoryManagementMenu();
void addNewInventory(vector<InventoryManagement>& inventory);
void getDetailsInventory(const vector<InventoryManagement>& inventory);

extern vector<InventoryManagement> inventory;

#endif
