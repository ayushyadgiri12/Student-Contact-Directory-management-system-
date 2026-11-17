# Student Contact Directory Management System

## DSA-1 Case Study 11 — Singly Linked List

### Project overview
A menu-driven C++11 console application that stores student/faculty/friend contact details in a singly linked list. It supports insertion at the beginning and end, searching by ID or name, deletion by ID, displaying all contacts, and counting contacts.

### Requirements
- C++11-compatible compiler (g++, clang++, Code::Blocks, or Visual Studio with C++11 support)
- No external libraries required

### Compile and run

**Linux / macOS / VS Code terminal**
```bash
g++ -std=c++11 -Wall -Wextra -pedantic main.cpp -o contact_directory
./contact_directory
```

**Windows (MinGW)**
```bash
g++ -std=c++11 -Wall -Wextra -pedantic main.cpp -o contact_directory.exe
contact_directory.exe
```

### Features
1. Loads five sample contacts when the program starts.
2. Adds a contact at the beginning.
3. Adds a contact at the end.
4. Searches by contact ID.
5. Searches by exact name (all exact matches are displayed).
6. Deletes a contact by ID.
7. Displays the complete directory.
8. Counts the nodes currently in the list.
9. Rejects duplicate IDs and validates mobile numbers as 7–15 digits.
10. Releases dynamically allocated memory when the directory object is destroyed.

### Data structure
Each node contains:
- `contactID`: unique integer identifier
- `name`: contact name
- `mobile`: mobile number stored as a string
- `next`: pointer to the next node

The `head` pointer stores the address of the first node. The last node points to `NULL`.

### Time complexity
| Operation | Complexity |
|---|---:|
| Insert at beginning | O(1) |
| Insert at end | O(n) |
| Search by ID/name | O(n) |
| Delete by ID | O(n) |
| Display all | O(n) |
| Count contacts | O(n) |

### Sample contacts
| ID | Name | Mobile |
|---:|---|---|
| 101 | Rahul | 9876543210 |
| 102 | Aman | 9876543211 |
| 103 | Priya | 9876543212 |
| 104 | Rohan | 9876543213 |
| 105 | Sneha | 9876543214 |

These are demonstration records. Replace them with permitted sample data before submitting if required by your instructor.

### Concepts demonstrated
Singly Linked List, dynamic memory allocation (`new`), pointers, node structure, insertion, deletion, traversal, searching, and memory deallocation (`delete`).

### Note
This is a console-based academic demonstration. Data is held in memory and is not saved after the program exits.
