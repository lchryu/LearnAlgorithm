#include <bits/stdc++.h>
using namespace std;

vector<int> alist[1001];
int tplt[1001], cnt=1;

void DFS(int u){
    tplt[u] = cnt;
    for(int v : alist[u]){
        if(!tplt[v]) DFS(v);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        alist[u].push_back(v);
        alist[v].push_back(u);
    }
    
    for(int i=1; i<=n; i++){
        if(!tplt[i]) {
            DFS(i); // de quy o tplt[i] 
            cnt++;
        }
    }
    
    int q; cin >> q;
    while(q--){
        int s, t;
        cin >> s >> t;
        if(tplt[s]==tplt[t]) cout << "1\n";
        else cout << "-1\n";
    }
    
    return 0;
}
