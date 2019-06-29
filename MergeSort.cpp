#include <iostream>
using namespace std;

/*
Compare and swap elements in the sub-array
Storing the resulting in the auxiliary array
Overwrite the array v with aux once the sort has been completed
*/

void merge(int *v, int left, int mid, int right, int* aux){
    int i = left; //left sub-array
    int m = mid; //right sub-array

    // (left, mid -1) compared to (mid, right)
    // insert into aux  in sorted order
    for (int j = left; j < right; j++){
        if (i < mid && (m >= right || v[i] <= v[m])){
            aux[j] = v[i];
            i++;
        }else{
            aux[j] = v[m];
            m++;
        }
    }
    //Overwrite the original array, from left to right,
    //With the merged and sorted aux
    for (int j = left; j < right; j++)
        v[j] = aux[j];
}

void mergesort(int *v, int left, int right, int *aux){
    if (right - left <= 1) //Size one sub-array is sorted
        return;

    int mid = (left + right) / 2;
    mergesort(v, left, mid, aux);
    mergesort(v, mid, right, aux);
    merge(v, left, mid, right, aux);
}

int main(){
    int a[15] = {1,1,10,10,11,8, 4, 1, 5, 10, 7, 6, 2, 9, 3};
    int aux[15]; //auxiliary space needed for mergesort

    cout << "unsorted: ";
    for (int i = 0; i < 15; i++){
        cout << a[i] << " ";
    }
    cout << endl;

    mergesort(a, 0, 15, aux);

    cout << "sorted: ";
    for (int i = 0; i < 15; i++){
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
