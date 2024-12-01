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
bool p(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return n > 1;
}
int main() {
    int n; cin >> n;
    int i = 2, cnt = 0;
    while (i * i < n) {
        if (p(i)) cnt++;
        i++;
    }
    cout << cnt;
}