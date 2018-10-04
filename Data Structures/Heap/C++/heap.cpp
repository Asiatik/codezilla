#include <iostream>
#include <climits>
#include "Heap.h"

Maxheap::Maxheap(int capacity)
{
    heap_size = 0;
    capacity = capacity;
    arr = new int[capacity];
}


void Maxheap::insertKey(int k)
{
    if (heap_size == capacity)
    {
        std ::  cout << "\nOverflow: Could not insertKey\n";
        return;
    }


    heap_size++;
    int i = heap_size - 1;
    arr[i] = k;


    while (i != 0 && arr[parent(i)] < arr[i])
    {
       swap(&arr[i], &arr[parent(i)]);
       i = parent(i);
    }
}

void Maxheap::increaseKey(int i, int new_val)
{
    arr[i] = new_val;
    while (i != 0 && arr[parent(i)] < arr[i])
    {
       swap(&arr[i], &arr[parent(i)]);
       i = parent(i);
    }
}

int Maxheap::extractMax()
{
    if (heap_size <= 0)
        return INT_MIN;
    if (heap_size == 1)
    {
        heap_size--;
        return arr[0];
    }


    int root = arr[0];
    arr[0] = arr[heap_size-1];
    heap_size--;
    Maxheapify(0);

    return root;
}



void Maxheap::deleteKey(int i)
{
    increaseKey(i, INT_MAX);
    extractMax();
}

void Maxheap::Maxheapify(int i)
{
    int l = left(i);
    int r = right(i);
    int largest = i;
    if (l < heap_size && arr[l] > arr[i])
        largest = l;
    if (r < heap_size && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        Maxheapify(largest);
    }
}


void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}