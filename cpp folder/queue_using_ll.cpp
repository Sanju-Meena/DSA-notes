#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    // Constructor to easily create a new node
    Node(int val) : data(val), next(nullptr) {}
};

// The Queue class
class Queue {
private:
    Node* front; // Pointer to the front of the queue
    Node* rear;  // Pointer to the rear of the queue

public:
    // Constructor to initialize an empty queue
    Queue() : front(nullptr), rear(nullptr) {}

    // Destructor to free all allocated memory
    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    // Function to add an element to the rear of the queue
    void enqueue(int value) {
        // 1. Create a new node
        Node* newNode = new Node(value);

        // 2. If the queue is empty, the new node is both front and rear
        if (isEmpty()) {
            front = rear = newNode;
            cout << value << " has been enqueued." << endl;
            return;
        }

        // 3. Otherwise, link the current rear to the new node
        rear->next = newNode;
        
        // 4. Update the rear pointer to be the new node
        rear = newNode;

        cout << value << " has been enqueued." << endl;
    }

    // Function to remove an element from the front of the queue
    void dequeue() {
        // 1. Check for underflow
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        // 2. Store the current front node to delete it later
        Node* temp = front;
        int dequeuedValue = temp->data;

        // 3. Move the front pointer to the next node
        front = front->next;

        // 4. If the queue becomes empty, update the rear pointer as well
        if (front == nullptr) {
            rear = nullptr;
        }

        // 5. Delete the old front node to free memory
        delete temp;

        cout << dequeuedValue << " has been dequeued." << endl;
    }

    // Function to get the front element
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1; // Or throw an exception
        }
        return front->data;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Function to display the elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue elements: FRONT -> ";
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "REAR" << endl;
    }
};

// Main function to demonstrate the Queue
int main() {
    Queue q;

    q.display();

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    cout << "Front element is: " << q.peek() << endl;

    q.dequeue();
    q.display();

    q.dequeue();
    q.dequeue();
    q.display();

    q.dequeue(); // Trying to dequeue from an empty queue

    return 0;
}