#include <iostream>
#include <list>
using namespace std;

int main(){
    //1. c++ static vs dynamic
    int a1[10]; //Static: compile-time initialized stored on stored on stack
    int* a2 = new int[10]; //Dynamic: run-time array stored on heap
    delete[] a2;

    //2. General Dynamic Array
    //Grows at run-time
    list<int> b = {1, 2, 3, 4, 5};
    cout << b.size() << endl;
    b.push_back(6); //Adds to the "List" increasing the size of 'b'
    cout <<b.size() << endl;

    return 0;
}
