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
    string w; vector<string>v;
    while (ss >> w) v.push_back(w);
    while (!v.empty()) {cout << v.back() << ' '; v.pop_back();}
}