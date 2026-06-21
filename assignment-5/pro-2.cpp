#include <iostream>

struct node
{
    std::string name;
    node *next;
};

struct queue
{
    node *front;
    node *rear;
};

void enqueue(queue *q, std::string name) {
    node *temp = new node();
    temp->name = name;
    temp->next = nullptr;
    if (q->front == nullptr) {
        q->front = temp;
    } else {
        q->rear->next = temp;
    }
    q->rear = temp;
}

std::string dequeue(queue *q) {
    if (q -> front == nullptr)
        return "";
    std::string name = q->front->name;
    node *temp = q->front;
    q->front = q->front->next;
    delete temp;

    if (q->front == nullptr)
        q->rear = nullptr;

    return name;
}

bool isEmpty(queue *q) {
    return q->front == nullptr;
}

void display(queue *q) {
    node *temp = q->front;
    
    while (temp != nullptr) {
        std::cout << temp->name << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main() {

    queue q;
    q.front = nullptr;
    q.rear = nullptr;

    enqueue(&q, "A");
    enqueue(&q, "B");
    enqueue(&q, "C");
    enqueue(&q, "D");
    enqueue(&q, "E");

    display(&q);
    dequeue(&q);
    display(&q);
    return 0;

}