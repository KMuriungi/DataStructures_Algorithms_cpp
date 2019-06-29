#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(){
        data = 0;
        next = nullptr;
    }

    Node(int d){
        data = d;
        next = nullptr;
    }
};

class LinkedList{
private:
    Node* root;
    int size;

public:
    LinkedList(){
        size = 0;
        root = nullptr;
    }

    ~LinkedList(){
        while (root != nullptr){
            Node* next = root->next;
            delete root;
            root = next;
        }
    }

    void insert(unsigned int index, int d){
        if (index == 0){
            Node *n = new Node(d);
            n->next = root;
            root = n;
        }
        else{
            Node *n = root;
            for (int i=1; i<index && n->next != nullptr; i++){
                n = n->next;
            }
            n->next = new Node(d);
        }
        size++;
    }

    void remove(unsigned int index){
        Node *p = root;
        if (index == 0){
            Node *n = root->next;
            delete root;
            root = n;
            size--;
            return;
        }
        for (int i=1; i<index && p->next !=nullptr; i++){
            p = p->next;
        }
        if (p->next != nullptr){
            Node *n = p->next;
            if (n != nullptr){
                Node *r = n->next;
                p->next = r;
                size--;
                delete n;
            }
        }
    }

    int find(int d){
        Node *n = root;
        bool found = false;
        int i = -1; //index
        while (n != nullptr && !found){
            i++;
            if (n->data == d)
                found = true;
            n = n->next;
        }
        return i;
    }

    bool contains(int d){
        return !(find(d) == -1);
    }

    int get(int i){
        Node *n = root;
        for (int j=0; j<i && n != nullptr; i++){
            n = n->next;
        }
        if (n == nullptr)
            throw std::runtime_error("no data at index i");
        return n->data;
    }

    bool empty(){
        return size == 0;
    }
};

int main(){
    //1. Custom List of INTS
    LinkedList li;
    li.insert(0,10);
    li.insert(1,20);
    li.insert(2,30);
    cout << "li.get(0): " << li.get(0) << endl;
    li.remove(0);
    cout << boolalpha << "li.contain(10): " <<li.contains(10) << endl;
    li.remove(0);
    cout << "li.get(0): " << li.get(0) << endl;
    cout << "empty: " << boolalpha << li.empty() << endl <<endl;

    //2. Standard Library List
    std::vector<int> v;
    v.insert(v.begin(), 10);
    v.insert(v.begin() + 1, 20);
    v.insert(v.begin() + 2, 30);
    cout << "v.at(0): " << v.at(0) <<endl;
    //cout << "v.front(): " << v.front() <<endl;
    v.erase(v.begin());
    //auto itr = find(v.begin(), v.end(), 30);
    //cout << "v.find(): " << (itr != v.end()) <<endl;
    auto itr = find(v.begin(), v.end(), 40);
    cout << "v.find(): " << boolalpha << itr != v.end()) <<endl;
    cout << "empty: " << boolalpha << v.empty() << endl;

    return 0;
}
