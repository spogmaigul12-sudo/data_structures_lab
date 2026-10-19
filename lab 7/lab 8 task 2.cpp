
#include <iostream>
using namespace std;
 
#define SIZE 5
 
class CircularQueue {
    int arr[SIZE];
    int front, rear, count;
public:
    CircularQueue() : front(0), rear(-1), count(0) {}
 
    bool isEmpty() { return count == 0; }
    bool isFull()  { return count == SIZE; }
 
    void enqueue(int id) {
        if (isFull()) {
            cout << "Queue full: packet " << id << " dropped." << endl;
            return;
        }
        rear = (rear + 1) % SIZE;      // circular movement
        arr[rear] = id;
        count++;
        cout << "Packet " << id << " inserted at index " << rear << endl;
    }
 
    void transmit() {
        if (isEmpty()) {
            cout << "Queue empty: no packet to transmit." << endl;
            return;
        }
        cout << "Transmitted packet " << arr[front] << " (index " << front << " is now free)" << endl;
        front = (front + 1) % SIZE;
        count--;
    }
 
    void display() {
        if (isEmpty()) {
            cout << "Packets waiting: none" << endl;
            return;
        }
        cout << "Packets waiting (front -> rear): ";
        for (int i = 0; i < count; i++)
            cout << arr[(front + i) % SIZE] << "(idx " << (front + i) % SIZE << ") ";
        cout << endl;
    }
};
 
int main() {
    CircularQueue q;
    cout << "=== Network Data Packet Management (Circular Queue) ===" << endl;
    q.transmit();                      // empty
    q.enqueue(201);
    q.enqueue(202);
    q.enqueue(203);
    q.enqueue(204);
    q.enqueue(205);
    q.enqueue(206);                    // full
    q.display();
    q.transmit();                      // 201 sent, index 0 freed
    q.enqueue(207);                    // reuses index 0
    q.display();
    q.transmit();
    q.transmit();
    q.enqueue(208);                    // reuses index 1
    q.display();
    return 0;
}
 

