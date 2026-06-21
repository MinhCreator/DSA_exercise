#include <iostream>

class myQueue
{

    // Array to store queue elements.
    int *arr;

    // Maximum number of elements the queue can hold.
    int capacity;

    // Current number of elements in the queue.
    int size;

public:
    myQueue(int c)
    {
        capacity = c;
        arr = new int[capacity];
        size = 0;
    }

    bool isEmpty(){return size == 0;}

    bool isFull(){return size == capacity;}

    void enqueue(int x)
    {
        if (size == capacity)
        {
            std::cout << "Queue Overflow" << std::endl;
            return;
        }

        arr[size++] = x;
    }

    void dequeue()
    {
        if (size == 0)
        {
            std::cout << "Queue Underflow" << std::endl;
            return;
        }

        for (int i = 0; i < size; i++){
            arr[i - 1] = arr[i];
        }
        size--;
    }

    int getFront(){
        if (size == 0)
        {
            std::cout << "Queue empty" << std::endl;
            return -1;
        }
        return arr[0];
    }

    int getRear(){
        if (size == 0)
        {
            std::cout << "Queue empty" << std::endl;
            return -1;
        }
        return arr[size - 1];
    }
};

