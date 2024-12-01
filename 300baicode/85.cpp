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
    string fullName; getline(cin, fullName);
    stringstream ss(fullName);
    string word; 
    vector<string>s;
    while (ss >> word) {
        s.push_back(word);
    }
    s.pop_back();
    for (auto x : s) cout << x << ' ';
}