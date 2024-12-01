#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;

void fastIO() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 
}

int main() {
    fastIO();
    string s; getline(cin, s);
    stringstream ss(s);
    string w;
    int d = 0;
    while (ss >> w) {
        int l = 0, r = w.size() - 1;
        while (l < r) swap(w[l++], w[r--]);
        cout << w << ' ';
    }
}