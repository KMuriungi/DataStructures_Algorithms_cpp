#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/*
topsort: Topological Sort

Input:
    adj: adjacency matrix to represent the graph

Return:
    vector<int> - sorted nodes in the graph
                - if the graph contains a  cycle, return an empty vector
*/

template <size_t cols>
vector<int> topsort(int adj[][cols]){
    vector<int> v;
    unordered_set<int> s; //current set of nodes with no incoming edges

    //find all nodes with no incoming edge
    for (int i = 0; i < cols; i++){
        bool incoming = false;
        for (int j = 0; j < cols && !incoming; j++){
            if (adj[j][i] != 0)
                incoming = true;
        }
        if (!incoming)
            s.insert(i);
    }
    while (!s.empty()){
        int n = *s.begin();
        s.erase(n);
        v.push_back(n);
        for(int i = 0; i < cols; i++){ //if the node n has an outgoing edge
            if (adj[n][i] != 0){
                adj[n][i] = 0; //remove the edge
                bool incoming = false;
                for (int j = 0; j < cols && !incoming; j++) {
                    if (adj[j][i] != 0)
                        incoming = true;
                }
                if (!incoming) //the edge removed frees up another valid node
                    s.insert(i);
            }
        }
    }
    //cycle detection
    if (v.size() != cols) {
        //if we haven't sorted every node then we have a cycle
        v.clear();
    }
    return v;
}

int main(){
    //adjacency matrix representing a directed graph of 6 nodes
    int adj[6][6] = {
        {0,1,0,0,1,0},  //1
        {0,0,1,0,0,0},  //2
        {0,0,0,0,0,1},  //3
        {0,0,0,0,0,1},  //4
        {0,0,0,1,0,0},  //5
        {0,0,0,0,0,0}   //6
    };

    vector<int> t = topsort(adj);

    if (t.empty()){
        cout << "Cycle / Loop Detected.";
    }
    else{
        cout << "Topological Order: ";
        for (int i : t) {
            cout << (i + 1) << " ";
        }
    }
    cout <<  endl;
    return 0;
}
