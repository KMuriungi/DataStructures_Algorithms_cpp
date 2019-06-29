#include <iostream>
using namespace std;

void output (int a[], int size){
    for (int i = 0; i < size; i++){
        cout << a[i] << ' ';
    }
    cout << endl;
}

// Running Time in Bubble sort: O(n^2) (n-squared)

void bubble_sort(int a[], int size){
    bool has_swapped = true;

    for (int i = 1; i < size && has_swapped; i++){
        has_swapped = false;
        for (int j = 0; j < size - 1; j++){
            if (a[j] > a[j + 1]){
                int aux = a[j];
                a[j] = a[j + 1];
                a[j + 1] = aux;
                has_swapped = true;
            }
        }
        output(a, size); //output the state of the array after each step
    }
}

int main(){
    int a[] = {7, 2, 8, 4, 6, 3, 5, 9 ,1 ,1 ,1
     ,3};
    output(a, 12); //output initial state of the array
    bubble_sort(a, 12); //sort

    cout << endl;
    output(a, 12); //output sorted array

    return 0;
}
