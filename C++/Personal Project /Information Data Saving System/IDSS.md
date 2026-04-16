# --- Information Data Saving System (IDSS) ---

File     : idss_main.

Build    : g++ -o idss idss_main.cpp

Run      : ./idss


# Stores Personal / Contact records

ID | Full Name | Email | Phone | Category


# Features:

[1]   Add New Record      -> Input and save a new contact record

[2]   Display All         -> List every saved record with a total count

[3]   Search by ID        -> Find a single record by exact ID match

[4]   Search by Name      -> Find all records matching a full name

[5]   Filter by Category  -> List all records under a given category

[0] Exit                  -> Close the program



- All records are appended to **idss_records.dat**
- ofstream with ios::app so no existing data is overwritten.
- Each record is delimited by a **"-----"** sentinel line.
