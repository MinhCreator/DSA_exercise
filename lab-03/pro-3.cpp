#include <iostream>
using namespace std;

// A simple structure to hold our queue data
struct Queue
{
    int arr[100]; // Array to hold up to 100 people
    int front = 0;
    int rear = 0;
    int count = 0;
    int capacity;
};

struct queueTest{
    int key;
};

queueTest q[100];
int front = 0;
int rear = 0;

int main()
{
    int n, k;
    cout << "Enter number of people (n) and step (k): ";
    cin >> n >> k;

    Queue person_queue;
    person_queue.capacity = n;

    // 1. Fill the queue with people 1, 2, 3... n
    for (int i = 1; i <= n; i++)
    {
        person_queue.arr[person_queue.rear] = i;
        person_queue.rear = (person_queue.rear + 1) % n;
        person_queue.count++;
    }

    // 2. Process until only 1 person remains
    while (person_queue.count > 1)
    {
        // Skip k-1 people: take from front, put at back
        for (int i = 0; i < k - 1; i++)
        {
            int person = person_queue.arr[person_queue.front]; // Get person from front
            person_queue.front = (person_queue.front + 1) % n; // Move front pointer
            person_queue.arr[person_queue.rear] = person;      // Put them at the back
            person_queue.rear = (person_queue.rear + 1) % n;   // Move rear pointer
        }

        // Eliminate the k-th person
        cout << "Eliminated: " << person_queue.arr[person_queue.front] << endl;
        person_queue.front = (person_queue.front + 1) % n; // Just move past them
        person_queue.count--;                   // One less person in circle
    }

    // 3. The last person left in the queue is the winner
    cout << "---" << endl;
    cout << "Winner is position: " << person_queue.arr[person_queue.front] << endl;

    return 0;
}