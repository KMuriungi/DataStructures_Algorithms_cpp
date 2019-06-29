#include <iostream>
#include <queue>
using namespace std;

//IntQueue : A queue of integers

class IntQueue {
    int* element;
    int maxSize;
    int head;
    int tail;

public:
    IntQueue(int s){
        maxSize = s;
        head = -1;
        tail = -1;
        element = new int [s];
    }

    ~IntQueue(){
        delete[] element;
    }

    void enqueue(int x){
        if (tail == maxSize -1)
            throw std::runtime_error("Queue Full");
        tail++;
        element[tail] = x;
    }

    int dequeue(){
        if (head == maxSize -1)
            throw std::runtime_error("Queue Full");
        if (head == tail)
            throw std::runtime_error("Queue Empty");
        head++;
        return element[head];
    }

    bool empty(){
        return head == tail;
    }
};

int main(){

    //1. Custom Queue
    IntQueue i(5);
    i.enqueue(10);
    i.enqueue(15);
    i.enqueue(20);

    cout << "i.dequeue(): " << i.dequeue() << endl;
    cout << "i.dequeue(): " << i.dequeue() << endl;
    cout << "i.dequeue(): " << i.dequeue() << endl;
    cout << "empty: " << boolalpha << i.empty() << endl << endl;

    //2. Standard - Library Queue
    std::queue<int> s;
    s.push(11);
    s.push(12);
    s.push(13);
    cout << "s.front(): " << s.front() << endl;
    cout << "s.end(): " << s.back() << endl;
    s.pop();
    cout << "s.front(): " << s.front() << endl;
    s.pop();
    cout << "s.front(): " << s.front() << endl;
    s.pop();
    //cout << "s.front(): " << s.front() << endl;
    //s.pop();

    cout << "empty: " << boolalpha << s.empty() << endl;

    return 0;
}
