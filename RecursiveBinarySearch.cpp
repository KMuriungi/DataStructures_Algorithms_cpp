#include <iostream>
#include <algorithm>
#include <vector>

/*
a[]: sorted array of inputs
begin: lower index of array to search
end: upper index of array to search
t: the target we are looking for
*/

int binary_search (int a[], int begin, int end, int t){
    int mid;
    int diff;

    if (begin > end){
        return -1; //not found
    }else{
        mid = (begin + end) / 2; //bisect current sub-array
        diff = a[mid] - t; //diff from target

        if (diff == 0) //found
            return mid;
        else if (diff < 0) //you're below. check upper half
            return binary_search(a, mid + 1, end, t);
        else //You're above so check lower half
            return binary_search(a, begin, mid -1, t);
    }
}

int main(){
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    //1. Use our own binary search fxn
    std::cout << "Binary-Search for 2: " << binary_search(a,0,9,2) << std::endl;
    //std::cout << "Binary-Search for 10: " << binary_search(a,0,10,10) << std::endl << std::endl;
    std::cout << "Binary-Search for 10: " << binary_search(a,0,9,10) << std::endl << std::endl;

    //2. Use the standard-library binary-search
    //std::vector<int> v(a, a + 9);
    std::vector<int> v(a, a + 10);
    std::cout << "std::binary-search for 2: " << std::boolalpha <<  std::binary_search(v.begin(), v.end(), 2) << std::endl;
    std::cout << "std::binary-search for 10: " << std::boolalpha <<  std::binary_search(v.begin(), v.end(), 10) << std::endl;

    return 0;
}
