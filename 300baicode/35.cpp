#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;

void fastIO() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 
    system("cls");
}
const int maxn = 1e7 + 5;
bool p[maxn] = {false, false};
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
    //fastIO();
    int l, r; cin >> l >> r;
    int cnt35 = 0, cnt2 = 0;
    for (int i = l; i <= r; i++) {
        if (i % 3 == 0 || i % 5 == 0) cnt35++;
        if (i % 2 == 0) cnt2 += i;
    }
    cout << cnt35 << ' ' << cnt2;
}