#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
ll binPow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll x = binPow(a, b / 2);
    if (b % 2)
        return (((x % MOD) * (x % MOD)) % MOD * a % MOD) % MOD;
    return (x % MOD * x % MOD) % MOD;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll x, y;
    cin >> x >> y;
    cout << binPow(x, y);
}
