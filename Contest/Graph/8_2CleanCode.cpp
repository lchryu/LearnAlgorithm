#include <bits/stdc++.h>
using namespace std;

// Define a struct to hold the edge information
struct Edge {
    int u, v, weight;
};

int main() {
    int n;
    cin >> n;
    
    vector<Edge> edges;
    // vector<pair<int, int>>edges;

    // Input the matrix and store the valid edges
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            if(x && i < j) {
                edges.push_back({i, j, x});
            }
        }
    }

    // Output the edges
    for(auto edge : edges) {
        cout << edge.u << " " << edge.v << " " << edge.weight << endl;
    }

    return 0;
}
