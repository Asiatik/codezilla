#include <iostream>
#include<conio.h>
#include<stdlib.h>

#define MAX_SIZE 5

using namespace std;

void insertion(int[]);

int main() {
    int arr_sort[MAX_SIZE], i;

    cout << "Simple C++ Insertion Sort Example - Array and Functions\n";
    cout << "\nEnter " << MAX_SIZE << " Elements for Sorting : " << endl;
    for (i = 0; i < MAX_SIZE; i++)
        cin >> arr_sort[i];

    cout << "\nYour Data   :";
    for (i = 0; i < MAX_SIZE; i++) {
        cout << "\t" << arr_sort[i];
    }

    insertion(arr_sort);
    getch();
}

void insertion(int fn_arr[]) {
    int i, j, a, t;
    for (i = 1; i < MAX_SIZE; i++) {
        t = fn_arr[i];
        j = i - 1;

        while (j >= 0 && fn_arr[j] > t) {
            fn_arr[j + 1] = fn_arr[j];
            j = j - 1;
        }
        fn_arr[j + 1] = t;

        cout << "\nIteration : " << i;
        for (a = 0; a < MAX_SIZE; a++) {
            cout << "\t" << fn_arr[a];
        }
    }

    cout << "\n\nSorted Data :";
    for (i = 0; i < MAX_SIZE; i++) {
        cout << "\t" << fn_arr[i];
    }
}
