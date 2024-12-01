#include <bits/stdc++.h>

using namespace std;

const int MAX_NODES = 1001;

vector<int> adj[MAX_NODES];
int visited[MAX_NODES];
int originalComponents;

void dfs(int node) {
    visited[node] = 1;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

// Check if the number of connected components increases when a node is removed
bool check(int totalNodes) {    
    int newComponents = 0;
    for (int i = 1; i <= totalNodes; i++) {
        if (!visited[i]) {
            dfs(i);
            newComponents++; // Increment the count of connected components
        }
    }
    return newComponents > originalComponents; // Return true if components increased
}

int main() {
    int n, m;
    cin >> n >> m;

    while (m--) {
        int node1, node2;
        cin >> node1 >> node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }


    // Count the initial number of connected components
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            originalComponents++;
        }
    }

    int cntDinhTru = 0;
    for (int i = 1; i <= n; i++) {
        memset(visited, 0, sizeof(visited)); // Reset the visited array
        visited[i] = 1; // Simulate the removal of the current node

        if (check(n)) {
            cntDinhTru++;
        }
    }

    cout << cntDinhTru << endl;
    return 0;
}
