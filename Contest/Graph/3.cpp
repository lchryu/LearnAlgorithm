#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adjList[1005];

int main(){
    
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }
    
    for(int i = 1; i <= n; i++){
        sort(adjList[i].begin(), adjList[i].end());
        cout << i << " : ";
        for(int v : adjList[i]){
            cout << v << ' ';
        }
        cout << endl;
    }
}
