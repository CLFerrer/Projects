// =======================================
//        IDSS REFERENCE GUIDE
// Information Data Saving System (IDSS)
//      Source file: idss_main.cpp
// =======================================



// --- HEADER LIBRARIES ---

#include <iostream>     // Standard I/O — Input / Output syntax
#include <fstream>      // File I/O — provides ifstream (read) and ofstream (write) for .dat/.txt files
#include <string>       // String for storing and manipulating text
#include <iomanip>      // Formatting tool for aligning outputs
using namespace std;    // Avoids having to prefix std:: before every standard library name


// --- CLASS AND ENCAPSULATION ---

const string DATA_FILE = "idss_records.dat";  // Global constant — stores filename; const prevents accidental changes

class record {          // Defines a class that groups related data and functions together
    private:            // Makes listed members inaccessible from outside — protects id, fullName, etc.
    public:             // Makes listed members accessible from outside — used for input(), display(), saveToFile(), loadFromStream()
};


// --- GETTER ---

string getId();                  // returns private id field so search functions can compare it against a query
string getFullName();            // returns private fullName field for name-based searching
string getCategory();            // returns private category field for category-based filtering


// --- INPUT / OUTPUT ---

// cout                -> prints text to the console 
// cin                 -> reads text from the keyboard; stands for "character input"
// cin.ignore()        -> discards leftover \n in the input buffer before getline() is called
// getline(cin, var)   -> reads an entire line of text (including spaces)
// cin >> choice       -> reads a single integer value from the keyboard for menu selection
// endl                -> inserts a newline, equivalent to \n
// left                -> aligns the next output to the left inside the column set by setw()
// setw(n)             -> sets minimum column width to n characters for aligned record display


// --- FILE STREAMS (fstream) ---

// ofstream            -> output file stream; creates or opens a file for writing
// ifstream            -> input file stream; opens an existing file for reading
// ios::app            -> append mode; adds data to the END of file without overwriting existing content
// outFile.close()     -> closes output stream, ensuring data is written and file is released properly
// inFile.close()      -> closes input stream after all reading is done
// getline(in, var)    -> reads one line from a file stream; used in loadFromStream() for each field
// "-----"             -> delimiter written after every record to mark its end in the .dat file


// --- CONTROL FLOW ---

// do { } while (condition)  -> executes body at least once; repeats while condition is true (main loop)
// switch (choice)           -> jumps to matching case
// case n:                   -> marks the code block to run when switch expression equals n
// break;                    -> exits the switch block or loop
// default:                  -> executes when no case matches
// while (condition)         -> used in displayAll(), searchID(), searchByName(), filterByCategory()
// if / else                 -> checks whether a file opened successfully or a search found a match
// return 0;                 -> signals main() finished successfully
// return false;             -> returned by loadFromStream() when end of file is reached
// return true;              -> returned by loadFromStream() after all five fields are read successfully


// --- VOID FUNCTIONS ---

void addEntry();                        // prompts user to fill in a new record and saves it to the file
void displayAll();                      // opens data file and prints every record to the console with a count
void searchID();                        // searches file for a record whose id matches the user's query
void searchByName();                    // searches file for all records whose fullName matches the query
void filterByCategory();                // searches file for all records whose category matches the query
void printMenu();                       // prints the numbered menu options to the console

// void input()                         -> reads all five fields from inputs into private members
// void display() const                 -> prints the records in the idss_records.dat file
// void saveToFile() const              -> appends five fields + delimiter to the data file
// bool loadFromStream(ifstream &in)    -> reads five lines from file stream into record fields



// ============================================================
//    IDSS — idss_main.cpp | IDSS Reference Guide | CLFerrer
// ============================================================