#include <iostream>
using namespace std;

struct Node {
    string productID;
    Node* next;
};

Node* head = NULL;

// Add product at the end
void addProduct(string id) {
    Node* newNode = new Node;
    newNode->productID = id;
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

// Display shopping cart
void displayCart() {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->productID;

        if (temp->next != NULL)
            cout << " -> ";

        temp = temp->next;
    }

    cout << endl;
}

// Remove product using Product ID
void removeProduct(string id) {
    if (head == NULL) {
        cout << "Cart is empty." << endl;
        return;
    }

    // If first product is to be removed
    if (head->productID == id) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        if (temp->next->productID == id) {
            Node* deleteNode = temp->next;
            temp->next = temp->next->next;

            delete deleteNode;
            return;
        }

        temp = temp->next;
    }

    cout << "Product not found." << endl;
}

int main() {
    addProduct("P101");
    addProduct("P205");
    addProduct("P310");
    addProduct("P415");

    cout << "Shopping Cart:" << endl;
    displayCart();

    cout << "\nRemove Product: P310" << endl;
    removeProduct("P310");

    cout << "\nUpdated Cart:" << endl;
    displayCart();

    return 0;
}

