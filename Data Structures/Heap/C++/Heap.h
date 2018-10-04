
#ifndef MAXHEAP_H
#define MAXHEAP_H

void swap(int *x, int *y);

class Maxheap
{
    int *arr;
    int capacity;
    int heap_size;
public:
    
    Maxheap(int capacity);


    void Maxheapify(int );

    int parent(int i) { return (i-1)/2; }


    int left(int i) { return (2*i + 1); }


    int right(int i) { return (2*i + 2); }


    int extractMax();


    void increaseKey(int i, int new_val);


    int getMax() { return arr[0]; }


    void deleteKey(int i);


    void insertKey(int k);
};

#endif
