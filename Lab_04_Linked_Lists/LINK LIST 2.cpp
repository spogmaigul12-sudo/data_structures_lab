#include <iostream>
using namespace std;

struct Node {
    string patientID;
    Node* next;
};

Node* head = NULL;

// Add patient at the end
void addPatient(string id) {
    Node* newNode = new Node;
    newNode->patientID = id;
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

// Display patients
void displayQueue() {
    Node* temp = head;

    cout << "Waiting Patients: ";

    while (temp != NULL) {
        cout << temp->patientID;

        if (temp->next != NULL)
            cout << " -> ";

        temp = temp->next;
    }

    cout << endl;
}

// Remove first patient
void servePatient() {
    if (head == NULL) {
        cout << "No patients in the queue." << endl;
        return;
    }

    Node* temp = head;

    cout << "Patient " << temp->patientID
         << " is being served." << endl;

    head = head->next;

    delete temp;
}

int main() {
    addPatient("P101");
    addPatient("P102");
    addPatient("P103");
    addPatient("P104");

    displayQueue();

    servePatient();

    cout << "Updated Queue: ";
    displayQueue();

    return 0;
}

