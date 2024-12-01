#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
#define ll long long
#define X first
#define Y second


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
    int n; cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    // sort(a, a + n);
    ll d = a[1] - a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] - a[i - 1] != d) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}