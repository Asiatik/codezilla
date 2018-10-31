#include<iostream>
#include<climits>
#include "Heap.h"

int main()
{
    Maxheap h(13);
    h.insertKey(4);
    h.insertKey(3);
    h.deleteKey(2);
    h.insertKey(16);
    h.insertKey(6);
    h.insertKey(5);
    h.insertKey(46);
    std :: cout << h.extractMax() << " ";
    std :: cout << h.getMax() << " ";
    h.increaseKey(2, 7);
    std :: cout << h.getMax();
    return 0;
}
