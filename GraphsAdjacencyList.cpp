#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    //Adjacency list: map from a node 'id' (int) to a list of neighboring node 'ids' (vector<int>)
    map<int, vector<int>> adj;

    //create and add node 1's edges
    vector<int> n1 = {2};
    adj.insert(make_pair(1, n1));

    //create  and add node 2's edges
    vector<int> n2 = {1, 3};
    adj.insert(make_pair(2, n2));

    //create and add node 3's edges
    vector<int> n3 = {2};
    adj.insert(make_pair(3, n3));

    for (int i = 1; i <= 3; i++){
        cout << "Node " << i << " : ";
        //auto v = adj[i];
        vector<int> v = adj[i];
        for (int j : v){
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
