#include <iostream>
using namespace std;

/*
Partition function:
- swap based on pivot
- Pivot chosen to be left-most element (Easiest choice but not always the most effective)
*/

int partition (int *v, int left, int right){
    int i = left + 1; //swap index
    int p = v[left]; //set current pivot to the left-most
    for (int j = left + 1; j < right + 1; j++){
        //compare with the current p, if less then swap.
        if (v[j] < p){
            int tmp = v[j];
            v[j] = v[i];
            v[i] = tmp;
            i++;
        }
    }
    int pos = i - 1;
    int tmp = v[left];
    v[left] = v[pos];
    v[pos] = tmp;

    return pos; //return new midpoint with pivot in its final position.
}

//Operate recursively, into smaller & smaller left-right windows i.e sub-arrays
void quicksort(int *v, int left, int right){
    if (left < right){
        int pos = partition(v, left, right);
        quicksort(v, left, pos - 1);
        quicksort(v, pos + 1, right);
    }
}

int main(){
    int a[15] = {1,1,10,10,11,8, 4, 1, 5, 10, 7, 6, 2, 9, 3};

    cout << "unsorted: ";
    for (int i = 0; i < 15; i++){
        cout << a[i] << " ";
    }
    cout << endl;

    quicksort(a, 0, 14);

    cout << "sorted: ";
    for (int i = 0; i < 15; i++){
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
