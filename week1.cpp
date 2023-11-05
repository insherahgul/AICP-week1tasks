#include <iostream>
using namespace std;

int main() {
    // Define arrays to store item information
    const string item_codes[] = {"A1", "A2", "B1", "B2", "B3", "C1", "C2", "C3", "D1", "D2", "E1", "E2", "E3", "F1", "FZz", "G1", "G2"};
    const string descriptions[] = {"Compact", "Tower", "8 GB", "16 GB", "32 GB", "1 TB HDD", "2 TB HDD", "4 TB HDD", "240 GB SSD", "480 GB SSD", "1 TB HDD", "2 TB HDD", "4 TB HDD", "DVD/Blu-Ray Player", "DVD/Blu-Ray Re-writer", "Standard Version", "Professional Version"};
    const double prices[] = {75.00, 150.00, 79.99, 149.99, 299.99, 49.99, 89.99, 129.99, 59.99, 119.99, 49.99, 89.99, 129.99, 50.00, 100.00, 100.00, 175.00};

    // Constants for the basic set of components
    const double basic_components_cost = 200.0;

    // Input from the customer
    string selected_case, selected_ram, selected_hdd;
    cout << "Select a case (A1/A2): ";
    cin >> selected_case;
    cout << "Select RAM (B1/B2/B3): ";
    cin >> selected_ram;
    cout << "Select Main Hard Disk Drive (C1/C2/C3): ";
    cin >> selected_hdd;

    // Validate input and calculate the total price
    double total_price = basic_components_cost;

    if ((selected_case == "A1" || selected_case == "A2") && (selected_ram == "B1" || selected_ram == "B2" || selected_ram == "B3") &&
        (selected_hdd == "C1" || selected_hdd == "C2" || selected_hdd == "C3")) {
        int case_index = (selected_case == "A1") ? 0 : 1;
        int ram_index = (selected_ram == "B1") ? 2 : ((selected_ram == "B2") ? 3 : 4);
        int hdd_index = (selected_hdd == "C1") ? 5 : ((selected_hdd == "C2") ? 6 : 7);

        total_price += prices[case_index] + prices[ram_index] + prices[hdd_index];
        cout << "Chosen items:" << endl;
        cout << "Case: " << descriptions[case_index] << endl;
        cout << "RAM: " << descriptions[ram_index] << endl;
        cout << "Main Hard Disk Drive: " << descriptions[hdd_index] << endl;
        cout << "Total Price: $" << total_price << endl;

        // Task 2: Additional items
    string chose;
        cout << "\tDo You Want To Continue purchasing (Y/N)" << endl;
        cin >> chose;

        int additional_items = 0;
        double discount = 0.0;

        while (chose == "Y") {
            cout << "\tPlease select your product by its code:" << endl;
            cout << "\tSolid State Drive (D1/D2):" << endl;
            cout << "\tSecond Hard Disk Drive (E1/E2/E3):" << endl;
            cout << "\tOptical Drive (F1/F2):" << endl;
            cout << "\tOperating System (G1/G2):" << endl;
            string choice;
            int index;

            cout << "\tEnter your choice: ";
            cin >> choice;

            if ((choice == "D1" || choice == "D2" || choice == "E1" || choice == "E2" || choice == "E3" || choice == "F1" || choice == "F2" || choice == "G1" || choice == "G2")) {
                if (choice == "D1" || choice == "D2") {
                    index = (choice == "D1") ? 8 : 9;
                } else if (choice == "E1" || choice == "E2" || choice == "E3") {
                    index = (choice == "E1") ? 10 : (choice == "E2") ? 11 : 12;
                } else if (choice == "F1" || choice == "F2") {
                    index = (choice == "F1") ? 13 : 14;
                } else if (choice == "G1" || choice == "G2") {
                    index = (choice == "G1") ? 15 : 16;
                }

                total_price += prices[index];
                cout << "\nChosen item:" << endl;
                cout << "Description: " << descriptions[index] << endl;

                additional_items++;
            } else {
                cout << "Invalid item selection. Please choose from the available options." << endl;
            }

            cout << "\tDo You Want To Continue purchasing (Y/N)" << endl;
            cin >> chose;
        }
//		Task 3 applying discount
        if (chose == "N") {
            if (additional_items == 1) {
                discount = total_price * 0.05; // 5% discount for one additional item
            } else if (additional_items >= 2) {
                discount = total_price * 0.10; // 10% discount for two or more additional items
            }
            total_price -= discount;

            cout << "You have finished purchasing." << endl;
            cout << "Total Savings: $" << discount << endl;
            cout << "New Price after Discounts: $" << total_price << endl;
        }
    } else {
        cout << "Invalid item selection. Please choose from the available options." << endl;
    }

    return 0;
}

