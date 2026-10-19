#include <iostream>
using namespace std;
 
#define SIZE 5
 
class Deque {
    int arr[SIZE];
    int front, rear, count;
public:
    Deque() : front(0), rear(SIZE - 1), count(0) {}
 
    bool isEmpty() { return count == 0; }
    bool isFull()  { return count == SIZE; }
 
    void insertFront(int id) {
        if (isFull()) { cout << "Deque full: cannot insert " << id << " at front." << endl; return; }
        front = (front - 1 + SIZE) % SIZE;
        arr[front] = id;
        count++;
        cout << "Inserted " << id << " at front." << endl;
    }
 
    void insertRear(int id) {
        if (isFull()) { cout << "Deque full: cannot insert " << id << " at rear." << endl; return; }
        rear = (rear + 1) % SIZE;
        arr[rear] = id;
        count++;
        cout << "Inserted " << id << " at rear." << endl;
    }
 
    void deleteFront() {
        if (isEmpty()) { cout << "Deque empty: cannot remove from front." << endl; return; }
        cout << "Removed " << arr[front] << " from front." << endl;
        front = (front + 1) % SIZE;
        count--;
    }
 
    void deleteRear() {
        if (isEmpty()) { cout << "Deque empty: cannot remove from rear." << endl; return; }
        cout << "Removed " << arr[rear] << " from rear." << endl;
        rear = (rear - 1 + SIZE) % SIZE;
        count--;
    }
 
    void display() {
        if (isEmpty()) { cout << "Deque is empty." << endl; return; }
        cout << "Front -> ";
        for (int i = 0; i < count; i++) {
            cout << arr[(front + i) % SIZE];
            if (i < count - 1) cout << ", ";
        }
        cout << " <- Rear" << endl;
    }
};
 
int main() {
    Deque d;
    cout << "=== Train Station Passenger Management (Deque) ===" << endl;
    d.deleteFront();                   // empty
    d.insertRear(301);
    d.insertRear(302);
    d.insertFront(300);
    d.display();                       // 300, 301, 302
    d.insertFront(299);
    d.insertRear(303);
    d.insertRear(304);                 // full
    d.display();
    d.deleteFront();
    d.deleteRear();
    d.display();
    d.deleteFront(); d.deleteFront(); d.deleteRear();
    d.deleteRear();                    // empty
    d.display();
    return 0;
}
 
