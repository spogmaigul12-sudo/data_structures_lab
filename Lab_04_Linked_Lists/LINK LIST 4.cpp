#include <iostream>
using namespace std;

struct Node {
    int rollNo;
    Node* next;
};

Node* head = NULL;

// Add student at the end
void addStudent(int rollNo) {
    Node* newNode = new Node;
    newNode->rollNo = rollNo;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

// Insert student at the beginning
void insertAtBeginning(int rollNo) {
    Node* newNode = new Node;

    newNode->rollNo = rollNo;
    newNode->next = head;

    head = newNode;
}

// Search student
void searchStudent(int rollNo) {
    Node* temp = head;

    while (temp != NULL) {
        if (temp->rollNo == rollNo) {
            cout << "Student with Roll Number "
                 << rollNo << " Found." << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Student Not Found." << endl;
}

// Display enrolled students
void displayStudents() {
    Node* temp = head;

    cout << "Enrolled Students: ";

    while (temp != NULL) {
        cout << temp->rollNo;

        if (temp->next != NULL)
            cout << " -> ";

        temp = temp->next;
    }

    cout << endl;
}

int main() {
    // Initial list: 22 -> 35 -> 41 -> 56
    addStudent(22);
    addStudent(35);
    addStudent(41);
    addStudent(56);

    cout << "Initial List:" << endl;
    displayStudents();

    // Insert 18 at beginning
    insertAtBeginning(18);

    cout << "\nAfter Insertion:" << endl;
    displayStudents();

    // Search
    int rollNo;
    cout << "\nEnter Roll Number to Search: ";
    cin >> rollNo;

    searchStudent(rollNo);

    return 0;
}

