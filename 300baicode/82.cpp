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
string getName(string fullName) {
    stringstream ss(fullName);
    string word;
    string res;
    while (ss >> word) res = word;
    return res;
}
int main() {
    fastIO();
    string name; getline(cin, name);
    int cnt = 0;
    for ( char c : name) {
        if (isupper(c)) cnt++;
    }
    cout << cnt;
}