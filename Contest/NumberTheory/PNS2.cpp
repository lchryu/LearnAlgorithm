#include <bits/stdc++.h>
using namespace std;
const int m = 1e8;
vector<bool>p(m + 1, false);
void sieve() {
    for (int i = 2; i <= m; i++) p[i] = true;
    for (int i = 2; i <= sqrt(m); ++i) {
        if (p[i]) {
            for (int j = i * i; j <= m; j += i) {
                p[j] = false;
            }
        }
    }
}
int main() {
    sieve();
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if (p[n]) cout << "YES";
        else cout << "NO";
        cout << "\n";
    }
}