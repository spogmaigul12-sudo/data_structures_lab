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

// Display students
void displayStudents() {
    Node* temp = head;

    cout << "Registered Students: ";

    while (temp != NULL) {
        cout << temp->rollNo;

        if (temp->next != NULL)
            cout << " -> ";

        temp = temp->next;
    }

    cout << endl;
}

// Search student
void searchStudent(int rollNo) {
    Node* temp = head;

    while (temp != NULL) {
        if (temp->rollNo == rollNo) {
            cout << "Student Found" << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Student Not Found" << endl;
}

int main() {
    addStudent(101);
    addStudent(105);
    addStudent(108);
    addStudent(112);

    displayStudents();

    int rollNo;
    cout << "Enter Roll Number to Search: ";
    cin >> rollNo;

    searchStudent(rollNo);

    return 0;
}

