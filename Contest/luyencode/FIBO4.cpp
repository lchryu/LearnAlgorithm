#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
#define ll long long
#define X first
#define Y second

using namespace std;

void fastIO() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 
}
const int mod = 1e6 + 7;
int main() {
    int n; cin >> n;
    if (n < 2) cout << 1;
    else {
        int f1 = 1, f2 = 1, fn;
        for (int i = 3; i <= n; i++) {
            fn = (f1 % mod + f2 % mod) % mod;
            f2 = f1;
            f1 = fn;
        }
        cout << fn << endl;
    }

}