#ifndef CYCLICQUEUE_H
#define CYCLICQUEUE_H
#include "queue.h"

class CyclicQueue : public Queue
{
protected:
    void _readNewValue();
public:
    CyclicQueue();
    CyclicQueue(int size);
    CyclicQueue(queue_data dat) : Queue(dat) {};

    const CyclicQueue operator++();
    const CyclicQueue operator--();

    friend CyclicQueue operator++(CyclicQueue& _, int p);
    friend CyclicQueue operator--(CyclicQueue& _, int p);

    const CyclicQueue operator/(int v);
    const CyclicQueue operator+(int v);
    const CyclicQueue operator-(int v);

    void operator/=(int v);
    void operator+=(int v);
    void operator-=(int v);

    void operator=(const CyclicQueue& v);
    int  operator[](int v);

    bool operator==(CyclicQueue& v);
    bool operator!=(CyclicQueue& v);
    bool operator>=(CyclicQueue& v);
    bool operator<=(CyclicQueue& v);
    bool operator> (CyclicQueue& v);
    bool operator< (CyclicQueue& v);

    bool operator==(int v);
    bool operator!=(int v);
    bool operator>=(int v);
    bool operator<=(int v);
    bool operator> (int v);
    bool operator< (int v);

    friend bool operator==(int v, CyclicQueue& _);
    friend bool operator!=(int v, CyclicQueue& _);
    friend bool operator>=(int v, CyclicQueue& _);
    friend bool operator<=(int v, CyclicQueue& _);
    friend bool operator> (int v, CyclicQueue& _);
    friend bool operator< (int v, CyclicQueue& _);

    void operator>>(int* v);
    void operator<<(int* v);

    static int _readIntValue();
};


#endif // CYCLICQUEUE_H
