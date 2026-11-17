#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Node {
    int contactID;
    string name;
    string mobile;
    Node* next;

    Node(int id, const string& n, const string& m)
        : contactID(id), name(n), mobile(m), next(NULL) {}
};

class ContactDirectory {
private:
    Node* head;

    Node* findByID(int id) const {
        Node* current = head;
        while (current != NULL) {
            if (current->contactID == id) return current;
            current = current->next;
        }
        return NULL;
    }

    bool validMobile(const string& mobile) const {
        if (mobile.empty()) return false;
        for (size_t i = 0; i < mobile.size(); ++i) {
            if (mobile[i] < '0' || mobile[i] > '9') return false;
        }
        return mobile.size() >= 7 && mobile.size() <= 15;
    }

    bool addContact(int id, const string& name, const string& mobile,
                    bool atBeginning) {
        if (id <= 0 || name.empty() || !validMobile(mobile)) {
            cout << "Invalid details. ID must be positive, name cannot be empty, "
                    "and mobile must contain 7-15 digits.\n";
            return false;
        }
        if (findByID(id) != NULL) {
            cout << "A contact with this ID already exists.\n";
            return false;
        }

        Node* newNode = new Node(id, name, mobile);

        if (atBeginning) {
            newNode->next = head;
            head = newNode;
        } else {
            if (head == NULL) {
                head = newNode;
            } else {
                Node* current = head;
                while (current->next != NULL) current = current->next;
                current->next = newNode;
            }
        }

        cout << "Contact added successfully.\n";
        return true;
    }

public:
    ContactDirectory() : head(NULL) {}

    ~ContactDirectory() {
        Node* current = head;
        while (current != NULL) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    ContactDirectory(const ContactDirectory&) = delete;
    ContactDirectory& operator=(const ContactDirectory&) = delete;

    void insertAtBeginning(int id, const string& name, const string& mobile) {
        addContact(id, name, mobile, true);
    }

    void insertAtEnd(int id, const string& name, const string& mobile) {
        addContact(id, name, mobile, false);
    }

    void searchByID(int id) const {
        Node* result = findByID(id);
        if (result == NULL) {
            cout << "Contact not found.\n";
            return;
        }
        printContact(result);
    }

    void searchByName(const string& name) const {
        Node* current = head;
        bool found = false;
        while (current != NULL) {
            if (current->name == name) {
                printContact(current);
                found = true;
            }
            current = current->next;
        }
        if (!found) cout << "Contact not found.\n";
    }

    void deleteByID(int id) {
        Node* current = head;
        Node* previous = NULL;

        while (current != NULL && current->contactID != id) {
            previous = current;
            current = current->next;
        }

        if (current == NULL) {
            cout << "Contact not found.\n";
            return;
        }

        if (previous == NULL) {
            head = current->next;
        } else {
            previous->next = current->next;
        }

        delete current;
        cout << "Contact deleted successfully.\n";
    }

    void displayAll() const {
        if (head == NULL) {
            cout << "The contact directory is empty.\n";
            return;
        }

        cout << "\n========== STUDENT CONTACT DIRECTORY ==========\n";
        cout << "ID\\tName\\t\\tMobile Number\n";
        cout << "------------------------------------------------\n";

        Node* current = head;
        while (current != NULL) {
            cout << current->contactID << "\\t"
                 << current->name << "\\t\\t"
                 << current->mobile << "\n";
            current = current->next;
        }
        cout << "------------------------------------------------\n";
    }

    int countContacts() const {
        int count = 0;
        Node* current = head;
        while (current != NULL) {
            ++count;
            current = current->next;
        }
        return count;
    }

    static void printContact(const Node* contact) {
        cout << "\nContact found:\n"
             << "ID: " << contact->contactID << "\n"
             << "Name: " << contact->name << "\n"
             << "Mobile: " << contact->mobile << "\n";
    }
};

void showMenu() {
    cout << "\n===== STUDENT CONTACT DIRECTORY =====\n"
         << "1. Add contact at beginning\n"
         << "2. Add contact at end\n"
         << "3. Search contact by ID\n"
         << "4. Search contact by name\n"
         << "5. Delete contact by ID\n"
         << "6. Display all contacts\n"
         << "7. Display total number of contacts\n"
         << "8. Exit\n"
         << "Enter your choice: ";
}

int readInteger(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) return value;
        cout << "Please enter a valid number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void readContactDetails(int& id, string& name, string& mobile) {
    id = readInteger("Enter contact ID: ");
    cout << "Enter name: ";
    getline(cin >> ws, name);
    cout << "Enter mobile number: ";
    cin >> mobile;
}

int main() {
    ContactDirectory directory;

    // Five starter contacts, as required by the case study.
    directory.insertAtEnd(101, "Rahul", "9876543210");
    directory.insertAtEnd(102, "Aman", "9876543211");
    directory.insertAtEnd(103, "Priya", "9876543212");
    directory.insertAtEnd(104, "Rohan", "9876543213");
    directory.insertAtEnd(105, "Sneha", "9876543214");

    cout << "\nFive sample contacts have been loaded.\n";

    int choice;
    do {
        showMenu();
        if (!(cin >> choice)) {
            cout << "Please enter a valid menu number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        int id;
        string name, mobile;

        switch (choice) {
            case 1:
                readContactDetails(id, name, mobile);
                directory.insertAtBeginning(id, name, mobile);
                break;
            case 2:
                readContactDetails(id, name, mobile);
                directory.insertAtEnd(id, name, mobile);
                break;
            case 3:
                id = readInteger("Enter contact ID to search: ");
                directory.searchByID(id);
                break;
            case 4:
                cout << "Enter exact name to search: ";
                getline(cin >> ws, name);
                directory.searchByName(name);
                break;
            case 5:
                id = readInteger("Enter contact ID to delete: ");
                directory.deleteByID(id);
                break;
            case 6:
                directory.displayAll();
                break;
            case 7:
                cout << "Total contacts: " << directory.countContacts() << "\n";
                break;
            case 8:
                cout << "Thank you for using the Contact Directory.\n";
                break;
            default:
                cout << "Invalid choice. Select a number from 1 to 8.\n";
        }
    } while (choice != 8);

    return 0;
}
