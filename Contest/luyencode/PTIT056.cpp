#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
bool p[maxn + 1] = {false, false};
void sieve() {
    for (int i = 2; i <= maxn; i++) p[i] = true;
    for (int i = 2; i <= sqrt(maxn); i++) {
        if (p[i]) {
            for (int j = i * i; j <= maxn; j += i) {
                p[j] = false;
            }
        }
    }
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    sieve();
    int n; cin >> n;
    if (!p[n]) {
        cout << "NO";
        return 0;
    } 
    int s = 0;
    while (n != 0) {
        s += n % 10;
        n /= 10;
    }
    if (p[s]) cout << "YES";
    else cout << "NO";
}