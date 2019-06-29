#include <iostream>

using namespace std;

int main(){
    //Adjacency Matrix
    int adj[4][4] = {
        // columns:
        // 1 2 3
            {0, 1, 0, 1}, //row 1 = node 1
            {1, 0, 1, 0}, //row 2 = node 2
            {0, 1, 0, 1}, //row 3 = node 3
            {1, 0, 1, 0}  //row 4 = node 4
    };
    for (int i = 0; i < 4; i++){
        //for each row
        cout << "Node: " << (i + 1) << ": ";
        for (int j = 0; j < 4; j++){
            //for each column
            if (adj[i][j] != 0)
                cout << (j + 1) << " ";
        }
        cout << endl;
    }
    return 0;
}
