#include <bits/stdc++.h>
using namespace std;

vector<int> adj[101]; // danh sách kề
vector<bool> visited(101, false); // trạng thái đã thăm của các đỉnh

void bfs(int u) {
    queue<int> q; 
    q.push(u); 
    visited[u] = true; // đánh dấu đỉnh đã thăm
    
    while (!q.empty()) {
        int cur = q.front(); 
        q.pop();
        cout << cur << endl; // in ra đỉnh hiện tại
        
        // Duyệt qua các đỉnh kề và sắp xếp chúng theo thứ tự tăng dần
        sort(adj[cur].begin(), adj[cur].end());
        for (int j : adj[cur]) {
            if (!visited[j]) {
                q.push(j); // đẩy đỉnh chưa thăm vào hàng đợi
                visited[j] = true; // đánh dấu đã thăm
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m; 
    cin >> n >> m; // nhập số lượng đỉnh và cạnh
    
    // nhập danh sách các cạnh
    for (int i = 1; i <= m; i++) {
        int u, v; 
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // đồ thị vô hướng
    }
    
    // Duyệt tất cả các đỉnh để bảo đảm không bỏ sót đỉnh nào trong đồ thị không liên thông
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            bfs(i);
        }
    }
}
