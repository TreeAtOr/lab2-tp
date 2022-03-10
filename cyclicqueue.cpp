#include "cyclicqueue.h"
#include "queue.h"
#include <ostream>

void CyclicQueue::_readNewValue()
{
    this->push(this->_readIntValue());
}

int CyclicQueue::_readIntValue(){
    int ret;
    std::cout << "Введите целое число: ";
    std::cin >> ret;
    return ret;
}

CyclicQueue::CyclicQueue(){};
CyclicQueue::CyclicQueue(int size)
{
    for ( int i = 0; i < size; i++ ){
        this->push(rand() % 21 - 10);
    }
}

const CyclicQueue CyclicQueue::operator++()
{
    this->_readNewValue();
    return CyclicQueue(this->copy());
}

const CyclicQueue CyclicQueue::operator--()
{
    std::cout << this->pop() << std::endl;
    return CyclicQueue(this->copy());
}

CyclicQueue operator++(CyclicQueue& _, int p) {
    CyclicQueue ret(_.copy());
    _+=_._readIntValue();
    return ret;
};
CyclicQueue operator--(CyclicQueue& _, int p) {
    CyclicQueue ret(_.copy());
    _-=_._readIntValue();
    return ret;
};

const CyclicQueue CyclicQueue::operator/(int v)
{
    CyclicQueue ret = CyclicQueue(this->copy());;
    ret/=v;
    return ret;
}

const CyclicQueue CyclicQueue::operator+(int v)
{
    CyclicQueue ret = CyclicQueue(this->copy());
    ret+=v;
    return ret;
}

const CyclicQueue CyclicQueue::operator-(int v)
{
    Queue temp = this->copy();
    CyclicQueue ret = CyclicQueue(this->copy());
    ret.setSize(this->getSize());
    ret-=v;
    return ret;
}

void CyclicQueue::operator/=(int v)
{
    int* array = this->getQueueHead();
    for ( int i = 0; i < this->getSize(); i++ ){
        array[i] /= v;
    }
}

void CyclicQueue::operator+=(int v)
{
    int* array = this->getQueueHead();
    for ( int i = 0; i < this->getSize(); i++ ){
        array[i] += v;
    }
}

void CyclicQueue::operator-=(int v)
{
    int* array = this->getQueueHead();
    for ( int i = 0; i < this->getSize(); i++ ){
        array[i] -= v;
    }
}

void CyclicQueue::operator=(const CyclicQueue& v)
{
    if( &v == this ){ return ;}
    queue_data tmp = v.copy();
    free(this->getQueueHead());
    this->setSize(tmp.size);
    this->setQueueHead(tmp.new_allocated_head);
}


int CyclicQueue::operator[](int index)
{
    return this->at(index);
}

bool CyclicQueue::operator==(CyclicQueue& v){
    return this->getSize() == v.getSize();
};
bool CyclicQueue::operator!=(CyclicQueue& v){
    return this->getSize() != v.getSize();
};
bool CyclicQueue::operator>=(CyclicQueue& v){
    return this->getSize() >= v.getSize();
};
bool CyclicQueue::operator<=(CyclicQueue& v){
    return this->getSize() <= v.getSize();
};
bool CyclicQueue::operator> (CyclicQueue& v){
    return this->getSize() > v.getSize();
};
bool CyclicQueue::operator< (CyclicQueue& v){
    return this->getSize() < v.getSize();
};

bool CyclicQueue::operator==(int v){
    return this->getSize() == v;
};
bool CyclicQueue::operator!=(int v){
    return this->getSize() != v;
};
bool CyclicQueue::operator>=(int v){
    return this->getSize() >= v;
};
bool CyclicQueue::operator<=(int v){
    return this->getSize() <= v;
};
bool CyclicQueue::operator> (int v){
    return this->getSize() > v;
};
bool CyclicQueue::operator< (int v){
    return this->getSize() < v;
};

bool operator==(int v, CyclicQueue& _){
    return _.getSize() == v;
};
bool operator!=(int v, CyclicQueue& _){
    return _.getSize() != v;
};
bool operator>=(int v, CyclicQueue& _){
    return _.getSize() <= v;
};
bool operator<=(int v, CyclicQueue& _){
    return _.getSize() >= v;
};
bool operator> (int v, CyclicQueue& _){
    return _.getSize() < v;
};
bool operator< (int v, CyclicQueue& _){
    return _.getSize() > v;
};

void CyclicQueue::operator<<(int* v){
    return this->push(*v);
};
void CyclicQueue::operator>>(int* v){
    *v = this->pop();
    return;
};

