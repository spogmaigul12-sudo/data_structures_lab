
#include <iostream>
#include <string>
using namespace std;
 
#define MAX 10
 
struct Patient {
    string id;
    int priority;   // 1 = highest urgency
};
 
// Priority comparison: a patient with a SMALLER priority number is more urgent.
// Equal priority -> earlier arrival is treated first (FIFO among equals).
class PriorityQueue {
    Patient arr[MAX];
    int size;
public:
    PriorityQueue() : size(0) {}
 
    bool isEmpty() { return size == 0; }
    bool isFull()  { return size == MAX; }
 
    void insert(string id, int priority) {
        if (isFull()) {
            cout << "Queue full: cannot add " << id << endl;
            return;
        }
        // keep array sorted by priority (insertion after last equal priority)
        int i = size - 1;
        while (i >= 0 && arr[i].priority > priority) {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = {id, priority};
        size++;
        cout << "Patient " << id << " admitted with priority " << priority << endl;
    }
 
    void treat() {
        if (isEmpty()) {
            cout << "Queue empty: no patients waiting." << endl;
            return;
        }
        cout << "Treating patient " << arr[0].id << " (priority " << arr[0].priority << ")" << endl;
        for (int i = 1; i < size; i++) arr[i - 1] = arr[i];
        size--;
    }
 
    void display() {
        if (isEmpty()) {
            cout << "Waiting patients: none" << endl;
            return;
        }
        cout << "Waiting patients:" << endl;
        for (int i = 0; i < size; i++)
            cout << "  " << arr[i].id << "  -> priority " << arr[i].priority << endl;
    }
};
 
int main() {
    PriorityQueue pq;
    cout << "=== Hospital Emergency Department (Priority Queue) ===" << endl;
    pq.treat();                        // empty
    pq.insert("P101", 3);
    pq.insert("P102", 1);
    pq.insert("P103", 2);
    pq.insert("P104", 3);
    pq.display();
    pq.treat();                        // P102 first
    pq.treat();                        // P103
    pq.display();
    pq.treat();
    pq.treat();
    pq.treat();                        // empty
    return 0;
}
 

