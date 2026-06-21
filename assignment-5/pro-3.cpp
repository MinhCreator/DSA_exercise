#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *next;

    Node(int value) : value(value), next(nullptr) {}
};

class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(int value)
    {
        Node *new_node = new Node(value);

        if (rear == nullptr)
        {
            front = new_node;
        }
        else
        {
            rear->next = new_node;
        }

        rear = new_node;
    }

    int dequeue()
    {
        if (front == nullptr)
        {
            return -1;
        }

        int result = front->value;
        Node *temp = front;
        front = front->next;
        delete temp;

        if (front == nullptr)
        {
            rear = nullptr;
        }

        return result;
    }

    bool is_empty()
    {
        return front == nullptr;
    }

    void print_queue()
    {
        Node *current = front;
        while (current != nullptr)
        {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }
};

Queue reverse_queue(Queue &queue)
{
    Queue reversed_queue;
    int *array = new int[sizeof(queue) / sizeof(int)];
    int index = 0;

    while (!queue.is_empty())
    {
        array[index++] = queue.dequeue();
    }

    for (int i = index - 1; i >= 0; i--)
    {
        reversed_queue.enqueue(array[i]);
    }

    delete[] array;

    return reversed_queue;
}

int main()
{
    Queue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);

    Queue reversed_queue = reverse_queue(queue);
    reversed_queue.print_queue(); // prints "5 4 3 2 1"
    return 0;
}