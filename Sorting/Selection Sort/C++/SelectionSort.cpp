#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    cout << "Before sort:" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << array[i] << ", "; 
    }
    cout << endl;

    for(int i = 0; i < 10; i++)
    {
        int small = array[i];
        int smallIndex = i;

        for (int j = i; j < 10; j++)
        {
            if(array[j] < small)
            {
                small = array[j];
                smallIndex = j;
            }
        }

        swap(array[i], array[smallIndex]);
    }

    cout << "After sort: " << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << array[i] << ", "; 
    }
    cout << endl;

    return 0;
}
