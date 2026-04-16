// Created by CLFerrer
// Github: https://github.com/CLFerrer

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const string DATA_FILE = "idss_records.dat";

class record {
private:
    string id;          // id number
    string fullName;    // Full name of the person
    string email;       // Active email address
    string phone;       // Active phone number
    string category;    // Category of the record (e.g., student, employee, etc.)

public:
    // ------ Getters for the record fields ------
    string getId() const { return id;}
    string getFullName() const { return fullName; }
    string getCategory() const { return category; }

    void input(){
    // ID number
        cout << "Enter ID: ";
        cin.ignore();
        getline(cin, id);
    // Full name
        cout << "Enter Full Name: ";
        getline(cin, fullName);
    // Email address
        cout << "Enter Email: ";
        getline(cin, email);
    // Phone number
        cout << "Enter Phone: ";
        getline(cin, phone);
    // Category 
        cout << "Enter Category: ";
        getline(cin, category);
    }

    void display() const { // Displays the record
        cout << endl;
        cout << "  ============================================" << endl;
        cout << "  |  ID       : " << left << setw(29) << id << "|" << endl;
        cout << "  |  Name     : " << setw(29) << fullName   << "|" << endl;
        cout << "  |  Email    : " << setw(29) << email      << "|" << endl;
        cout << "  |  Phone    : " << setw(29) << phone      << "|" << endl;
        cout << "  |  Category : " << setw(29) << category   << "|" << endl;
        cout << "  ============================================" << endl;
}

    void saveToFile() const { // Saves the record to the data file
        ofstream outFile(DATA_FILE, ios::app); // Open file in append mode
        if (!outFile) {
            cerr  << "[Errors] Cannot open \'" << DATA_FILE << "\' for writing." << endl;
            return;
        }
    outFile << id       << endl // Write each field on a new line
            << fullName << endl
            << email    << endl
            << phone    << endl 
            << category << endl
            << "-----"  << endl; // Record delimiter
    outFile.close(); // Close the file
        cout << " [DONE] Record saved to " << DATA_FILE << endl;
}

bool loadFromStream(ifstream &in) { // Loads a record from the file stream
    if (!in)
        return false; // Check if the stream is valid

    if (!getline(in, id))
        return false; // Read ID

    if (!getline(in, fullName))
        return false; // Read Full Name

    if (!getline(in, email))
        return false; // Read Email

    if (!getline(in, phone))
        return false; // Read Phone

    if (!getline(in, category))
        return false; // Read Category

    string delimiter;
    getline(in, delimiter); // Read the record delimiter (-----)
    return true;            // Successfully loaded a record
    }
};

void addEntry() {
    record reco;
    reco.input(); // Get user input for the record
    reco.saveToFile(); // Save the record to the file
}

void displayAll() {
    ifstream inFile(DATA_FILE); // Open the data file for reading
    if (!inFile){
        cout << " [INFO] No records found. Add an entry first." << endl;
        return;  
    }
    cout << "\n ---------------- All Records ----------------\n";
    record reco;
    int count = 0;
    while (reco.loadFromStream(inFile)) { // Load and display each record
        cout << " Record #" << ++count << endl;
        reco.display();
    }
    if (count == 0)
        cout << " [INFO] Data File is empty." << endl;
    else 
        cout << "\n Total Records: " << count << " records found." << endl;

        inFile.close(); // Close the file after reading
}

void searchID() {
    string query;
    cout << "Enter ID to search: ";
    cin.ignore();
    getline(cin, query); // Get the ID to search for

    ifstream inFile(DATA_FILE); // Open the data file for reading
    if (!inFile) {
        cout << " [INFO] No data file found." << endl;
        return;
}

    bool found = false;
    record reco;
    while (reco.loadFromStream(inFile)) { // Load each record and check for a match
        if (reco.getId() == query) {
            cout << " [MATCH] Record Found: " << query << endl;
            reco.display(); // Display the found record
            found = true;
            break; // Exit loop after finding the record
        }
    }
    if (!found) {
        cout << " [INFO] No record found with ID \"" << query << "\"." << endl;
    }
    inFile.close(); // Close the file after reading
};

void searchByName() {
    string query;
    cout << endl << "Enter Name to search: ";
    cin.ignore();
    getline(cin, query); // Get the name to search for

    ifstream inFile(DATA_FILE); // Open the data file for reading
    if (!inFile) {
        cout << " [INFO] No data file found." << endl;
        return;
    }

    bool found = false;
    int ctr = 0; // Counter for matching records
    record reco;
    while (reco.loadFromStream(inFile)) { // Load each record and check for a match
        if (reco.getFullName() == query) {
            cout << " [MATCH #" << ++ctr << "]" << endl;
            reco.display(); // Display the found record
            found = true;
        }
    }
    if (!found)
        cout << " [INFO] No records found for name \"" << query << "\"." << endl;

    inFile.close(); // Close the file after reading
}

void filterByCategory() {
    string query;
    cout << endl << "Enter Category to filter: ";
    cin.ignore();
    getline(cin, query); // Get the category to filter by

    ifstream inFile(DATA_FILE); // Open the data file for reading
    if (!inFile) {
        cout << " [INFO] No data file found." << endl;
        return;
    }

    bool found = false;
    int ctr = 0; // Counter for matching records
    record reco;
    while (reco.loadFromStream(inFile)) {
        if (reco.getCategory() == query) {
            cout << " [" << ++ctr << "]" << endl;
            reco.display(); // Display the matching record
            found = true;
    }
}
if (!found)
    cout << " [INFO] No records found in the category \"" << query << "\"." << endl;
    
    inFile.close(); // Close the file after reading
}

// Menu Function
void printMenu() {
    cout << "\n -------------------------------------------" << endl;
    cout << "    INFORMATION DATA SAVING SYSTEM (IDSS)  " << endl;
    cout << " -------------------------------------------" << endl;
    cout << "    [1] Add New Record                      " << endl;
    cout << "    [2] Display All Records                 " << endl;
    cout << "    [3] Search by ID                        " << endl;
    cout << "    [4] Search by Name                      " << endl;
    cout << "    [5] Filter by Category                  " << endl;
    cout << "    [0] Exit                                " << endl;
    cout << " ------------------------------------------" << endl;
    cout << "  Choice: ";
}

int main (){
    int choice;

    cout << "\n =============================================" << endl;
    cout << " | WELCOME TO INFORMATION DATA SAVING SYSTEM |" << endl;
    cout << " =============================================" << endl;
    do {
        printMenu(); // Display the menu
        cin >> choice; // Get user choice

        switch (choice) {
            case 1: // add new record
                addEntry (); 
                    break;
            case 2: // display all records
                displayAll();
                    break;
            case 3: // search by ID
                searchID();
                    break;
            case 4: // search by name
                searchByName();
                    break;
            case 5: // filter by category
                filterByCategory();
                    break;
            case 0: // exit the program
                cout << "\n System closed. Data saved to \"" << DATA_FILE << "\"." << endl; // Exit message
                    break;
            default: // Handle invalid input
                cout << " [ERROR] Invalid choice. Please try again." << endl; // Handle invalid input
        }
    } while (choice != 0); // Loop until the user chooses to exit

    return 0; // Exit the program
}
