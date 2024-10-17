#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int t; cin >> t;
    while (t--) {
        int k; cin >> k;
        string s; cin >> s;
        
        map<char, int>mp;
        for (char x : s) mp[x]++;
        
        priority_queue<int>q;
        for (auto it : mp) q.push(it.second);

        while (k > 0) {
            int top = q.top(); q.pop();
            top--;
            k--;
            q.push(max(top, 0));
        }
        
        ll ans = 0;
        while (!q.empty()) {
            ans += 1ll * q.top() * q.top();
            q.pop();
        }
        cout << ans << endl;
    }
}