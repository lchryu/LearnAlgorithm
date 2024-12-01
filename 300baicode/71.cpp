#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;

void fastIO() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 
    system("cls");
}
int main() {
    fastIO();
    string s; getline(cin, s);
    string x; getline(cin, x);
    string y; getline(cin, y);
    for (int i = 0; i < s.size(); i++) {
        if (x == s.substr(i, x.size())) {
            s.replace(i, x.size(), y);
        }
    }
    cout << s;
}