
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;

    Node(int d){
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

//BST: Binary Search Tree

class BST{
private:
    Node *root;
    int size;

public:
    BST(){
        root = nullptr;
        size = 0;
    }
    ~BST(){
        clear(root);
    }
    //Recursively clears the given subtree at node n
    void clear(Node *n){
        if (n != nullptr){
            clear(n->left);
            clear(n->right);
            delete n;
        }
    }

    bool contains(int d){
        Node *n = root;
        bool found = false;
        while (n != nullptr && !found){
            if (n->data == d){
                found = true;
            }
            else if (d < n->data){
                n = n->left;
            }
            else{
                n = n->right;
            }
        }
        return found;
    }

    void insert(int d){
        if (!root){
            root = new Node(d);
            size++;
            return;
        }
        Node *n = root;
        while (n != nullptr){
            if (d  < n->data){
                if (n->left == nullptr){
                    n->left = new Node(d);
                    size++;
                    break;
                }
                else{
                    n = n->left;
                }
            }
            else{
                if (n->right == nullptr){
                    n->right = new Node(d);
                    size++;
                    break;
                }
                else{
                    n = n->right;
                }
            }
        }
    }

    void update_parent(Node *p, int dir, Node *child){
        if(p){
            if(dir == 1)
                p->left = child;
            else
                p->right = child;
        }
    }

    bool remove(int d){
        if (!root)
            return false;
        Node *n = root;
        Node *parent = nullptr; //track the target node's parent so we can update its right and left paths
        int p_dir = 0; //Parent direction - 1: left, 2: right.
        while (n != nullptr && n->data != d){
            if (d < n->data){
                parent = n;
                p_dir = 1;
                n = n->left;
            }
            else{
                parent = n;
                p_dir = 2;
                n = n->right;
            }
        }
        if (n == nullptr)
            return false;
        if (!n->left && !n->right){
            //1. Node n is a leaf node
            update_parent(parent, p_dir, nullptr);
        }
        else if (!n->left && n->right){
            //2 (a). Node n has only a right child
            if (n == root)
                root = n->right;
            else
                update_parent(parent, p_dir, n->right);
        }
        else if(n->left && !n->right){
            //2 (b). Node n has only a left child
            if (n == root)
                root = n->left;
            else
                update_parent(parent, p_dir, n->left);
        }
        else{
            //3. Node n has both left and right children
            if (!n->right->left){
                //3 (a). Right child has no left children
                n->right->left = n->left;
                if (n == root){
                    root = n->right;
                }
                else
                    update_parent(parent, p_dir, n->right);
            }
            else{
                //3 (b). Right child has left children
                Node *s, *t;
                s = n->right;
                t = n->right;
                while (s->left->left){
                    //find left-most descendant
                    s = s->left;
                }
                //t is now left-most descendant
                t =s->left;
                //t's parent takes on t's right sub-tree
                s->left = t->right;
                //t replaces n
                t->left = n->left;
                t->right = n->right;
                if (n == root)
                    root = t;
                else
                    update_parent(parent, p_dir, t);
            }
        }

        delete n;
        size--;
        return true;
    }
};


int main(){
    BST b;
    b.insert(90);
    b.insert(50);
    b.insert(150);
    b.insert(20);
    b.insert(75);
    b.insert(66);
    //b.insert(10);
    b.insert(80);
    b.insert(60);
    b.insert(68);
    b.insert(62);
    b.insert(10);

    /*
    150 : 1 case
    20 : 2(b) case
    90 : 3(a) case
    50 : 3(b) case
    */

    cout << boolalpha << "remove 150?: " << b.remove(10) <<endl;
    cout << boolalpha << "contains 150?: " << b.contains(10) <<endl;

    return 0;
}
