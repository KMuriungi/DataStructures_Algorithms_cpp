#include <iostream>
#include <map>
#include <vector>
#include <stack>

using namespace std;

/*
dfs: Depth First Search

Input:
    adj - adjacency list to represent the graph
    source - id of the starting node
    target - id of the target node (stopping condition)

return:
    true if target found
    false if not found

Note: the visited array assumes the nodes of the graph are number from 1 to its size
*/

bool dfs(map<int, vector<int>> adj, int source, int target) {
    bool target_found = false;
    bool *visited = new bool[adj.size() + 1];
    for (int i = 0; i <= adj.size(); i++)
        visited[i] = false;

    stack<int> s;
    s.push(source);
    visited[source] = true;

    cout << "dfs: ";
    while (!s.empty()){
        int v = s.top();
        s.pop();
        cout << v << " ";
        if (v == target) {
            target_found = true; //target found
            break;
        }
        for (int n : adj[v]){ //for each neighbor of v
            if (!visited[n]){
                s.push(n);
                visited[n] = true;
            }
        }
    }
    delete[] visited;
    cout << endl;
    return target_found;
}


int main(){
    map<int, vector<int>> adj;

    //add nodes to graph
    //create and add node 1's edges
    vector<int> n1 = {2, 3};
    adj.insert(make_pair(1, n1));

    //create and add node 2's edges
    vector<int> n2 = {1, 4};
    adj.insert(make_pair(2, n2));

    //create and add node 3's edges
    vector<int> n3 = {1, 4};
    adj.insert(make_pair(3, n3));

    //create and add node 4's edges
    vector<int> n4 = {2, 3, 5, 6};
    adj.insert(make_pair(4, n4));

    //create and add node 5's edges
    vector<int> n5 = {4};
    adj.insert(make_pair(5, n5));

    //create and add node 6's edges
    vector<int> n6 = {4};
    adj.insert(make_pair(6, n5));

    cout << boolalpha << dfs(adj, 1, 7) << endl;
    return 0;
}
