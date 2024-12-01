#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> adj[1001];  
bool visited[1001];     

bool hasCycle(int n) {
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            stack<pair<int, int>> s; 
            s.push({i, -1}); // Dinh bat dau va dinh cha gia dinh
            visited[i] = true;

            while (!s.empty()) {
                int u = s.top().first;
                int parent = s.top().second;
                s.pop();

                for (int v : adj[u]) {
                    if (!visited[v]) {
                        s.push({v, u});
                        visited[v] = true;
                    } else if (v != parent) {
                        return true; // tim thay chu trinh
                    }
                }
            }
        }
    }
    return false; // ko co chu trinh
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << (hasCycle(n) ? 1 : 0) << endl; 

    return 0;
}