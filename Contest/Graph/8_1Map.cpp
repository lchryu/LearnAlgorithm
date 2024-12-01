#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;
int main() {
    int n; cin >> n;
    map<ii, int> mp;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int x; cin >> x;
            if(x && i < j) mp[{i, j}] = x;
        }
    }
    for(auto x : mp){
        cout << x.first.first << " " << x.first.second << " " << x.second << endl;
    }

    return 0;
}
