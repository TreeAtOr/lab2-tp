#ifndef QUEUE_H
#define QUEUE_H
#include <memory>
#include <iostream>
#include <cstdlib>
#include <cstring>
struct queue_data {int* new_allocated_head; int size; };

class Queue
{
private:
    int* queue_head;
    int queue_size;
protected:
    int* getQueueHead() const;

    int incrementSize();
    int decrementSize();

    void setQueueHead(int*);
    void setSize(int);
public:
    Queue();
    Queue(queue_data);
    ~Queue();

    int getSize() const;

    void push(int value);
    int pop();
    int at(const int index) const;

    queue_data copy() const;
    static queue_data concat(Queue* a, Queue* b);

    void print() const;

};

#endif // QUEUE_H
