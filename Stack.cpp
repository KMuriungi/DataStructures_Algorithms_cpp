#include <iostream>
#include <stack>
#include <stdexcept>
using namespace std;

//IntStack : Stack of  Integers

class IntStack{
    int* element;
    int maxSize;
    int topIndex;

public:
    // int s: maxSize  (fixed size)
    IntStack(int s){
        maxSize = s;
        topIndex = -1;
        element = new int[s];
    }
    ~IntStack(){
        delete[] element;
    }

    void push(int x){
        if (topIndex == maxSize - 1)
            throw std::runtime_error("Stack Full");
        topIndex++;
        element[topIndex] = x;
    }

    void pop(){
        if (topIndex == -1)
            throw std::runtime_error("Stack Empty");
        topIndex--;
    }

    int top(){
        if (topIndex == -1)
            throw std::runtime_error("Stack Empty");
        return element[topIndex];
    }

    bool empty(){
        return topIndex == -1;
    }
};

int main(){

    //1. Custom Stack
    IntStack i(5);
    i.push(10);
    cout <<  "i.top(): " <<i.top() << endl;
    i.pop();
    cout << "Empty: " << boolalpha << i.empty() << endl << endl;

    //2. Standard Library Stack
    std::stack<int> s;
    s.push(11);
    int x = s.top();
    cout << "s.top(): " << x << endl;
    s.pop();
    cout << "Empty: " << boolalpha << s.empty() << endl;

    return 0;
}
