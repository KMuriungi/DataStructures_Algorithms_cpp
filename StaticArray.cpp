#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

int main() {
    //1. Primitive Array
    int a[4]; //Uninitialized Static Array
    int a1[4] = {20, 123, 99, 4096}; //Initialized Static Array

    //Zero-based indexing of arrays in C++
    a1[0] = 21;
    a1[3] = 4097;

    //Multi-Dimensional Array
    int aa[4][2]; // Typically rows first, then columns
    int aa2[2][2][3][4]; //Careful of memory use!

    //2. Standard-library "Static" Array
    cout << "Standard-library Array: \n";
    array<int, 5> ax = {1, 2, 3, 4, 5};
    cout << "Size: " << ax.size()  << endl;
    cout << "Front: " << ax.front() << endl;
    cout << "ax[0]: " << ax[0] << endl;
    cout << "back: " << ax.back() << endl;
    cout << "ax[ax.size() - 1]: " << ax[ax.size() - 1] << endl;

    return 0;
}
