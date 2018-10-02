#include<iostream>
#include<climits>
using namespace std;

void swap(int *x, int *y);

class Maxheap
{
    int *arr;
    int cap;
    int hs;
public:
    // Constructor
    Maxheap(int cap);


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

Maxheap::Maxheap(int cap)
{
    hs = 0;
    cap = cap;
    arr = new int[cap];
}


void Maxheap::insertKey(int k)
{
    if (hs == cap)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }


    hs++;
    int i = hs - 1;
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
    if (hs <= 0)
        return INT_MIN;
    if (hs == 1)
    {
        hs--;
        return arr[0];
    }


    int root = arr[0];
    arr[0] = arr[hs-1];
    hs--;
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
    if (l < hs && arr[l] > arr[i])
        largest = l;
    if (r < hs && arr[r] > arr[largest])
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
    cout << h.extractMax() << " ";
    cout << h.getMax() << " ";
    h.increaseKey(2, 7);
    cout << h.getMax();
    return 0;
}
